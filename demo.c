// demo.c - draws the Sans Lomono character set, in colors, anti-aliased,
// composited in linear light onto a checkerboard, and writes a PPM.
//
// Chris Lomont, 2026, www.lomont.org
// License: do whatever you want with this file, forever, anywhere, with no
// attribution required.  It is provided as is, with no warranty of any kind;
// the author is not liable for anything that happens because of it.
//
//     cc demo.c sans_lomono.c -lm -o demo && ./demo        (writes demo.ppm)
//
// PPM because every image viewer and converter on earth reads it and the
// writer is three lines.  Opened in binary mode to avoid 0x0A -> 0x0D 0x0A
//
// The "surface" is a plain sRGB byte buffer.  The pixel callback gets 
// color + coverage and blends the right way: decode both colors to linear light, 
// mix by coverage, encode back to sRGB.  
#define _CRT_SECURE_NO_WARNINGS     /* MSVC and its opinions about fopen */
#include <math.h>
#include <stdio.h>
#include "sans_lomono.h"

#define W 760
#define H 600

static unsigned char rgb[H][W][3];       /* sRGB bytes */
static float to_lin[256];                /* sRGB byte -> linear, precomputed */

static unsigned char to_srgb(float v)    /* linear -> sRGB byte */
{
    v = v <= 0.0031308f ? v * 12.92f : 1.055f * powf(v, 1.0f / 2.4f) - 0.055f;
    v = v * 255.0f + 0.5f;
    return (unsigned char)(v < 0 ? 0 : v > 255 ? 255 : v);
}

static void put(void *user, int x, int y, uint32_t rgba)   /* the entire "driver" */
{
    float a = (rgba >> 24) / 255.0f;
    unsigned char *d = rgb[y][x];
    int i;
    (void)user;
    if (x < 0 || x >= W || y < 0 || y >= H) return;
    for (i = 0; i < 3; i++) {
        float src = to_lin[(rgba >> (16 - 8 * i)) & 255], dst = to_lin[d[i]];
        d[i] = to_srgb(src * a + dst * (1 - a));
    }
}

static uint32_t hue(int i, int n)                           /* i of n around the color wheel */
{
    int h = i * 6 * 255 / n, s = h / 255, f = h % 255, r = 0, g = 0, b = 0;
    switch (s) {
    case 0: r = 255; g = f; break;   case 1: r = 255 - f; g = 255; break;
    case 2: g = 255; b = f; break;   case 3: g = 255 - f; b = 255; break;
    case 4: r = f; b = 255; break;   default: r = 255; b = 255 - f; break;
    }
    return (uint32_t)((r << 16) | (g << 8) | b);
}

int main(void)
{
    static const int sizes[] = { 40, 32, 24, 20, 16, 14, 12, 10, 8, 7, 6 };
    int x, y, row, i, s;
    char line[17];

    for (i = 0; i < 256; i++) {
        float v = i / 255.0f;
        to_lin[i] = v <= 0.04045f ? v / 12.92f : powf((v + 0.055f) / 1.055f, 2.4f);
    }
    for (y = 0; y < H; y++)                                  /* checkerboard of two grays */
        for (x = 0; x < W; x++) {
            unsigned char g = ((x / 20) + (y / 20)) & 1 ? 0x5a : 0x66;
            rgb[y][x][0] = rgb[y][x][1] = rgb[y][x][2] = g;
        }

    /* the full character set, 16 per row, one color per row */
    y = 8;
    for (row = 0; row < 6; row++) {
        for (i = 0; i < 16; i++) line[i] = (char)(32 + row * 16 + i);
        line[row == 5 ? 15 : 16] = 0;                        /* 95 chars, last row is short */
        x = 8;
        lomono_draw_text(&x, &y, 40, line, put, 0, hue(row, 6));
        y += 42;
    }

    /* the same line at shrinking sizes, to see where it gives up */
    y += 6;
    for (s = 0; s < (int)(sizeof sizes / sizeof sizes[0]); s++) {
        x = 8;
        lomono_draw_text(&x, &y, sizes[s], "The quick brown fox jumps over the lazy dog. 0O 1lI| 5S$ 2Z 8B",
                         put, 0, 0xffffff);
        y += sizes[s] + 2;
    }

    /* multi-line text in one call */
    x = 8; y = 500;
    lomono_draw_text(&x, &y, 18, "int main(void) {\n    printf(\"hi %d\\n\", 42);\n}", put, 0, 0xa0ffa0);

    {
        FILE *f = fopen("demo.ppm", "wb");
        if (!f) return 1;
        fprintf(f, "P6\n%d %d\n255\n", W, H);
        fwrite(rgb, 1, sizeof rgb, f);
        fclose(f);
    }
    return 0;
}
