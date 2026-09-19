// sans_lomono.c - Sans Lomono 1.1 (September 2026), a tiny vector debug
// font: data + decoder + a pixel-pushing text writer.  Format: sans_lomono.h.
//
// Chris Lomont, 2026, www.lomont.org
// License: do whatever you want with this file, forever, anywhere, with no
// attribution required.  It is provided as is, with no warranty of any kind;
// the author is not liable for anything that happens because of it.
//
// The tables below are generated (1814 bytes).  Do not edit them by hand
// unless you enjoy debugging fonts one bit at a time.  The code after them
// is small enough to read over coffee.
#include "sans_lomono.h"

/* ------------------------------------------------------------------ data */

static const uint16_t lomono_char_starts[96] = {  /* byte offset of each character (32..126), plus the end */
    0,0,5,10,19,24,35,79,81,90,99,113,118,120,122,124,
    130,140,149,173,212,226,254,290,299,308,347,352,357,367,372,382,
    407,439,451,490,515,535,549,560,591,598,605,622,636,645,663,677,
    682,684,694,702,704,709,729,739,757,765,777,791,802,808,819,828,
    830,836,875,882,907,914,942,961,982,987,992,1011,1025,1039,1052,1057,
    1062,1069,1076,1092,1128,1148,1168,1178,1196,1208,1225,1239,1272,1274,1307,1321,
};

static const uint8_t lomono_char_data[1321] = {
    186,11,228,128,192,209,123,244,172,192,213,66,245,158,186,180,190,173,12,139,79,246,128,64,
    223,126,231,74,121,147,30,121,71,154,89,79,4,158,45,203,168,192,106,170,82,142,168,164,
    154,53,205,72,207,100,169,86,206,104,21,62,199,65,120,113,7,168,28,248,62,83,232,211,
    74,194,173,42,142,35,59,210,23,92,82,153,97,31,248,137,135,192,48,117,242,177,138,10,
    54,48,0,206,9,197,130,219,90,194,175,23,43,73,102,139,64,206,9,239,190,64,202,7,
    182,171,146,3,5,106,237,171,140,112,165,181,232,115,113,88,133,214,209,111,18,39,69,15,
    160,50,206,94,192,8,112,150,232,218,190,159,105,11,91,63,103,96,188,25,85,117,103,86,
    238,108,113,155,224,8,80,150,232,218,190,159,104,238,9,197,170,250,206,173,220,216,227,55,
    179,139,105,122,29,157,182,176,94,28,13,72,207,110,106,142,167,170,183,4,64,104,88,125,
    52,54,126,12,193,178,70,87,106,124,106,99,140,110,28,107,76,208,236,237,181,130,240,212,
    104,198,123,115,84,117,61,86,56,64,240,37,181,112,86,117,110,230,199,25,175,25,237,205,
    81,212,245,88,225,70,193,174,14,225,1,198,180,205,14,206,219,88,47,14,225,45,209,181,
    125,60,19,45,248,218,145,149,32,37,64,197,193,240,115,124,91,95,7,4,26,113,158,220,
    213,29,88,172,106,221,205,142,51,126,54,156,74,174,171,218,93,163,56,16,116,33,194,91,
    163,106,250,107,72,179,182,214,11,195,112,146,3,228,132,192,202,7,228,132,192,105,229,57,
    161,179,240,120,15,154,152,171,75,234,208,192,8,237,41,164,3,48,110,142,2,24,8,112,
    150,232,218,190,159,105,48,122,11,45,229,218,172,43,58,183,115,99,140,223,228,128,192,158,
    47,230,141,245,25,82,14,108,94,22,17,80,220,211,228,254,160,216,251,27,177,70,214,2,
    1,72,36,116,108,195,40,5,230,168,252,51,181,62,114,6,95,109,74,7,161,45,15,217,
    134,81,100,16,120,215,25,232,30,168,234,122,171,131,208,157,165,232,118,119,1,130,240,126,
    132,234,34,140,169,8,108,113,141,144,86,117,110,230,199,25,179,25,237,205,81,212,237,14,
    206,219,88,47,15,97,45,209,181,125,60,5,225,44,232,218,190,147,103,109,174,51,205,205,
    81,213,181,110,230,142,48,103,96,188,37,181,118,166,56,198,123,63,239,190,64,5,225,45,
    171,181,49,198,50,251,239,144,86,117,110,230,199,25,179,25,237,205,81,212,234,168,224,28,
    70,148,208,236,237,181,130,240,246,18,221,27,87,211,192,140,203,227,206,251,239,144,142,3,
    237,173,251,105,240,106,237,14,206,219,88,47,13,198,156,103,183,53,71,83,171,176,140,203,
    221,40,211,12,42,239,79,4,156,207,179,176,28,227,61,159,179,176,94,18,192,5,225,44,
    96,28,37,196,213,217,218,159,85,231,136,202,13,177,150,5,225,44,96,42,133,118,213,217,
    218,198,27,195,44,165,181,232,115,64,150,15,165,181,232,115,116,254,216,147,193,149,150,15,
    210,251,59,83,230,112,139,79,142,3,234,212,192,28,227,78,51,219,154,163,169,213,219,87,
    104,118,118,218,193,120,110,18,192,28,230,249,93,181,115,184,99,130,88,24,4,144,209,159,
    20,184,184,155,242,198,74,39,4,140,138,64,72,223,126,199,59,98,83,224,144,28,231,29,
    93,183,227,208,102,129,39,156,6,9,109,93,170,15,102,126,206,193,120,50,82,1,28,86,
    231,52,218,169,245,54,69,73,170,187,28,236,221,77,132,176,28,233,181,38,140,113,150,109,
    78,104,227,17,231,73,127,166,51,152,74,192,171,53,48,106,52,209,137,144,27,211,147,50,
    218,126,142,206,212,250,171,170,249,134,113,77,173,122,150,248,211,52,99,61,107,162,235,213,
    119,210,138,207,5,225,172,29,174,107,228,140,203,225,109,120,28,80,85,181,94,226,198,217,
    171,25,237,205,81,212,173,6,206,219,88,47,14,97,13,201,180,253,36,143,59,225,109,120,
    28,80,17,42,174,171,220,88,219,53,99,61,185,170,58,145,160,89,219,107,5,225,204,33,
    185,54,159,161,136,80,25,99,134,57,225,251,9,193,83,77,52,195,114,254,190,150,126,217,
    132,133,181,224,113,118,158,206,108,205,173,137,192,180,100,199,115,99,83,116,234,179,140,203,
    236,206,192,186,3,228,134,192,76,169,62,146,81,24,39,11,70,76,99,162,179,98,217,156,
    158,73,164,140,203,216,8,169,6,232,95,83,228,140,205,184,144,48,101,182,90,224,116,170,
    148,80,28,101,154,35,156,5,225,12,150,146,145,182,50,250,224,62,188,236,184,203,236,206,
    192,133,181,224,113,64,140,195,225,109,120,28,80,143,51,225,109,120,28,80,185,25,196,60,
    72,194,246,159,164,170,218,175,132,228,165,35,85,213,94,226,198,217,179,26,238,13,163,232,
    54,118,218,193,120,104,52,35,61,185,170,58,150,169,219,216,55,15,97,13,201,180,253,40,
    47,229,182,90,224,117,70,167,208,28,101,154,35,143,18,42,205,87,136,208,27,227,78,51,
    219,154,163,169,213,155,79,104,118,118,218,193,120,110,16,192,27,230,241,89,180,243,184,99,
    130,24,23,4,136,207,30,196,180,182,155,178,198,74,38,248,140,138,64,56,1,10,49,187,
    15,44,131,54,36,240,7,0,27,232,20,180,132,61,167,155,41,56,29,67,204,119,34,234,
    204,8,109,61,166,145,214,126,206,193,120,51,66,96,252,86,244,55,12,161,58,13,72,201,
    61,8,193,104,22,128,233,245,55,44,107,73,111,151,20,140,147,203,170,238,95,102,14,187,
    217,255,28,244,63,12,161,58,17,151,210,221,6,193,104,22,127,204,113,151,44,235,73,111,
    151,89,125,45,203,138,238,95,101,252,227,7,114,98,247,81,205,102,211,233,101,156,149,19,
    92,
};

static const uint16_t lomono_shape_starts[25] = {  /* 24 shared shapes, used 88 times */
    0,13,26,63,69,75,99,112,125,138,151,157,174,191,197,203,
    209,222,235,246,252,258,264,270,276,
};

static const uint8_t lomono_shape_data[276] = {
    113,99,108,213,140,246,230,168,234,154,175,113,64,109,96,188,57,132,55,38,211,244,91,59,
    109,64,211,213,157,91,185,177,198,111,198,219,139,105,122,29,157,182,176,94,27,141,56,207,
    110,106,142,167,170,183,6,14,196,56,75,116,109,95,79,50,193,120,75,28,224,128,203,57,
    107,64,224,131,196,72,141,66,117,95,89,213,188,54,56,198,88,47,9,104,126,213,244,251,
    71,131,192,76,99,140,225,141,244,182,94,215,217,127,76,64,74,96,252,69,132,180,214,135,
    225,154,19,74,64,115,99,140,217,140,246,230,168,234,218,183,115,64,109,96,188,61,132,183,
    70,213,244,155,59,109,64,210,193,248,67,105,224,128,203,57,115,151,116,166,54,205,112,119,
    8,105,109,11,193,224,206,212,250,169,170,247,22,54,205,80,115,8,110,77,167,232,160,170,
    198,184,219,85,224,130,203,121,131,67,224,190,68,72,141,95,160,115,99,140,223,141,183,22,
    171,235,58,183,115,64,112,96,236,67,132,183,70,213,244,251,71,112,64,129,208,28,255,167,
    4,246,89,86,114,214,130,75,105,125,67,32,94,198,248,231,48,96,80,133,49,12,53,0,
    128,75,41,133,68,32,223,134,88,8,87,96,
};

/* --------------------------------------------------------------- decoder */

typedef struct { const uint8_t *p; unsigned pos, end; } bits;   /* bit cursor */

static unsigned get(bits *b, int n)              /* n bits, MSB first, n <= 16 */
{
    unsigned v = 0;
    while (n--) { v = (v << 1) | ((b->p[b->pos >> 3] >> (7 - (b->pos & 7))) & 1); b->pos++; }
    return v;
}

static void point(bits *b, int dx, int dy, int *x, int *y)   /* one 10-bit point */
{
    unsigned v = get(b, LOMONO_PT_BITS);
    *x = (int)(v / LOMONO_YRANGE) + LOMONO_XMIN + dx;              /* the famous divide */
    *y = (int)(v % LOMONO_YRANGE) + LOMONO_YMIN + dy;
}

/* Emit L/Q ops until the stream runs dry or a contour-start prefix (11)
 * shows up.  Returns 1 if it saw the 11 (caller reads the M/R selector),
 * 0 at the end.  dx,dy translate everything (used for shared shapes). */
static int body(bits *b, int dx, int dy, const lomono_sink *s, void *u)
{
    int x, y, cx, cy;
    for (;;) {
        if (b->end - b->pos < 1 + LOMONO_PT_BITS) return 0;      /* only padding left */
        if (get(b, 1) == 0) {                                   /* 0: line */
            point(b, dx, dy, &x, &y); s->line(u, x, y);
        } else if (get(b, 1) == 0) {                            /* 10: quad */
            if (b->end - b->pos < 2 * LOMONO_PT_BITS) return 0;
            point(b, dx, dy, &cx, &cy); point(b, dx, dy, &x, &y); s->quad(u, cx, cy, x, y);
        } else {
            return 1;                                           /* 11: another contour */
        }
    }
}

int lomono_glyph(int ch, const lomono_sink *s, void *u)
{
    bits b;
    if (ch < LOMONO_FIRST || ch >= LOMONO_FIRST + LOMONO_COUNT) return 0;
    b.p = lomono_char_data + lomono_char_starts[ch - LOMONO_FIRST]; b.pos = 0;
    b.end = 8u * (lomono_char_starts[ch - LOMONO_FIRST + 1] - lomono_char_starts[ch - LOMONO_FIRST]);
    if (b.end == 0) return 1;                                   /* space: the sound of silence */
    for (;;) {                                                  /* one contour per lap */
        int x, y, more;
        if (get(&b, 1) == 0) {                                  /* M: contour spelled out */
            point(&b, 0, 0, &x, &y); s->move(u, x, y);
            more = body(&b, 0, 0, s, u);
        } else {                                                /* R: shared shape, moved */
            bits d; int idx = (int)get(&b, LOMONO_REF_BITS), sx, sy;
            point(&b, 0, 0, &x, &y);
            d.p = lomono_shape_data + lomono_shape_starts[idx]; d.pos = 0;
            d.end = 8u * (lomono_shape_starts[idx + 1] - lomono_shape_starts[idx]);
            point(&d, 0, 0, &sx, &sy);                          /* where it was drawn */
            s->move(u, x, y);
            body(&d, x - sx, y - sy, s, u);                     /* where it goes now */
            more = b.end - b.pos >= 2 && get(&b, 2) == 3;
        }
        s->close(u);
        if (!more) return 1;
    }
}

/* ------------------------------------------------------- pixel text writer */
/* An exact-area scanline rasterizer, the classic cover/area trick:
 *
 *   Every edge is walked through the pixel cells it crosses.  A cell keeps
 *   two integers: `cover`, how much of the edge's vertical extent passed
 *   through it (signed, so direction gives winding), and `area`, twice the
 *   trapezoid area between the edge and the cell's left side.  Sweeping a
 *   row left to right, a running sum of `cover` says how much of each pixel
 *   is inside from edges further left; subtracting the cell's own `area`
 *   corrects for the part of the pixel the edge actually cuts off.  The
 *   result is the exact coverage of the pixel by the polygon, with
 *   non-zero winding, in one pass, with integer arithmetic.
 *
 * Coordinates are fixed point pixels with SUB subpixels, relative to the
 * glyph's cell so they fit in 16 bits (cells up to 500 px tall).  Quads are
 * flattened into 1..8 chords depending on their size in pixels, so small
 * text makes few edges.  One pixel row of cells lives on the stack; rows
 * and columns a glyph cannot touch are never visited.  Coverage arrives in
 * the top byte of the pixel callback's RGBA, 255 = fully inside.
 *
 * Stack: LOMONO_MAX_EDGES * 8 + LOMONO_MAX_COLS * 8 bytes, about 2.3 KB
 * with the defaults.  Both are #ifndef, so a tiny target can say
 *     -DLOMONO_MAX_EDGES=64 -DLOMONO_MAX_COLS=48
 * and draw 16 px text in under a kilobyte; anything that does not fit is
 * clipped, never overrun. */

#ifndef LOMONO_MAX_EDGES
#define LOMONO_MAX_EDGES 160      /* `%` at 8 chords per quad needs 132; small text ~15 */
#endif
#ifndef LOMONO_MAX_COLS
#define LOMONO_MAX_COLS  128      /* widest cell we rasterize, in pixels (213 px tall) */
#endif
#define LOMONO_MAX_CELL_H 500     /* keeps 26.6-ish coordinates inside int16 */
#define SUB   64                  /* subpixels per pixel */
#define SHIFT 6

typedef struct { int16_t x0, y0, x1, y1; } edge;             /* fixed point, glyph-relative */
typedef struct { int cover, area; } cell;
static int iabs(int v) { return v < 0 ? -v : v; }
typedef struct {
    edge e[LOMONO_MAX_EDGES]; int n;
    int scale;                        /* fixed point pixels per font unit */
    int cx, cy, sx, sy;               /* current and contour start points, fixed point */
    int ymin, ymax, xmin, xmax;       /* pixel bounds touched, glyph-relative */
} raster;

static void add_edge(raster *r, int x1, int y1)
{
    if (r->n < LOMONO_MAX_EDGES && y1 != r->cy) {
        edge *e = &r->e[r->n++];
        e->x0 = (int16_t)r->cx; e->y0 = (int16_t)r->cy; e->x1 = (int16_t)x1; e->y1 = (int16_t)y1;
    }
    if ((y1 >> SHIFT) < r->ymin) r->ymin = y1 >> SHIFT;
    if ((y1 >> SHIFT) > r->ymax) r->ymax = y1 >> SHIFT;
    if ((x1 >> SHIFT) < r->xmin) r->xmin = x1 >> SHIFT;
    if ((x1 >> SHIFT) > r->xmax) r->xmax = x1 >> SHIFT;
    r->cx = x1; r->cy = y1;
}
static int tx(const raster *r, int x) { return x * r->scale; }
static int ty(const raster *r, int y) { return (LOMONO_TOP - y) * r->scale; }   /* y flips here */

static void r_move(void *u, int x, int y)
{
    raster *r = (raster *)u;
    r->cx = r->sx = tx(r, x); r->cy = r->sy = ty(r, y);
    add_edge(r, r->cx, r->cy);                       /* no edge, just the bounds */
}
static void r_line(void *u, int x, int y) { raster *r = (raster *)u; add_edge(r, tx(r, x), ty(r, y)); }
static void r_quad(void *u, int cx, int cy, int x, int y)
{
    raster *r = (raster *)u;
    int x0 = r->cx, y0 = r->cy, px = tx(r, cx), py = ty(r, cy), x1 = tx(r, x), y1 = ty(r, y), i, n;
    int ext = (iabs(px - x0) + iabs(py - y0) + iabs(x1 - px) + iabs(y1 - py)) >> SHIFT;   /* ~ length, px */
    n = 1 + ext / 6; if (n > 8) n = 8;              /* one chord per ~6 px of curve, max 8 */
    for (i = 1; i <= n; i++) {                       /* t = i/n with 8-bit weights */
        int t = i * 256 / n, s = 256 - t;
        long long ax = (long long)s * s * x0 + 2LL * s * t * px + (long long)t * t * x1;
        long long ay = (long long)s * s * y0 + 2LL * s * t * py + (long long)t * t * y1;
        add_edge(r, (int)(ax >> 16), (int)(ay >> 16));
    }
}
static void r_close(void *u) { raster *r = (raster *)u; add_edge(r, r->sx, r->sy); }

static int floordiv(int a, int b) { int q = a / b; return (a % b != 0 && (a < 0) != (b < 0)) ? q - 1 : q; }

/* Add one piece of an edge that lies within the current pixel row to the
 * row's cells.  x1, x2 are 24.8 pixel x relative to the row's first cell;
 * fy1, fy2 the subpixel y within the row (0..SUB); the piece runs from
 * (x1, fy1) to (x2, fy2) and dy = fy2 - fy1 carries the direction sign.
 * Distributes dy over the cells the piece crosses, exactly. */
static void accumulate(cell *row, int ncols, int x1, int fy1, int x2, int fy2)
{
    int dy = fy2 - fy1, dx = x2 - x1;
    int ex1 = x1 >> SHIFT, ex2 = x2 >> SHIFT, fx1 = x1 & (SUB - 1), fx2 = x2 & (SUB - 1);
    int incr, first, p, delta, mod, lift, rem, y;
    if (dy == 0) return;
    if (ex1 < 0) ex1 = 0; if (ex1 >= ncols) ex1 = ncols - 1;      /* clip, keeps winding */
    if (ex2 < 0) ex2 = 0; if (ex2 >= ncols) ex2 = ncols - 1;
    if (ex1 == ex2) {                                            /* one cell: easy */
        row[ex1].cover += dy; row[ex1].area += dy * (fx1 + fx2); return;
    }
    if (dx > 0) { incr = 1;  first = SUB; p = (SUB - fx1) * dy; }
    else        { incr = -1; first = 0;   p = fx1 * dy; dx = -dx; }
    delta = floordiv(p, dx); mod = p - delta * dx;               /* to the first cell edge */
    row[ex1].cover += delta; row[ex1].area += delta * (fx1 + first);
    y = fy1 + delta; ex1 += incr;
    if (ex1 != ex2) {
        p = SUB * dy; lift = floordiv(p, dx); rem = p - lift * dx; /* per full cell */
        while (ex1 != ex2) {
            delta = lift; mod += rem; if (mod >= dx) { mod -= dx; delta++; }
            row[ex1].cover += delta; row[ex1].area += delta * SUB;
            y += delta; ex1 += incr;
        }
    }
    delta = fy2 - y;                                             /* the remainder */
    row[ex2].cover += delta; row[ex2].area += delta * (fx2 + SUB - first);
}

static void fill(const raster *r, int ox, int oy, lomono_pixel_fn put, void *user, uint32_t color)
{
    cell row[LOMONO_MAX_COLS];
    int col0 = r->xmin - 1, ncols = r->xmax - r->xmin + 3, py;
    if (ncols > LOMONO_MAX_COLS) ncols = LOMONO_MAX_COLS;
    for (py = r->ymin; py <= r->ymax; py++) {
        int top = py << SHIFT, bot = top + SUB, i, lo = ncols, hi = -1, cov = 0;
        for (i = 0; i < r->n; i++) {                              /* edges crossing this row */
            const edge *e = &r->e[i];
            int ya = e->y0, yb = e->y1, xa = e->x0, xb = e->x1, ca, cb;
            if ((ya < top && yb < top) || (ya >= bot && yb >= bot)) continue;
            if (ya > yb) { int t = ya; ya = yb; yb = t; t = xa; xa = xb; xb = t; }  /* now ya < yb */
            ca = ya < top ? top : ya; cb = yb > bot ? bot : yb;   /* clip to the row */
            if (ca != ya) xa = e->x0 + (int)((long long)(ca - e->y0) * (e->x1 - e->x0) / (e->y1 - e->y0));
            if (cb != yb) xb = e->x0 + (int)((long long)(cb - e->y0) * (e->x1 - e->x0) / (e->y1 - e->y0));
            if (ca == cb) continue;
            {   /* first touch of the row: clear only the cells we can use */
                int c0 = (xa < xb ? xa : xb) >> SHIFT, c1 = (xa > xb ? xa : xb) >> SHIFT;
                c0 -= col0; c1 -= col0;
                if (c0 < 0) c0 = 0; if (c1 >= ncols) c1 = ncols - 1;
                if (hi < 0) { int k; for (k = c0; k <= c1; k++) row[k].cover = row[k].area = 0; lo = c0; hi = c1; }
                else {
                    int k;
                    for (k = c0; k < lo; k++) row[k].cover = row[k].area = 0;
                    for (k = hi + 1; k <= c1; k++) row[k].cover = row[k].area = 0;
                    if (c0 < lo) lo = c0; if (c1 > hi) hi = c1;
                }
            }
            if (e->y0 < e->y1) accumulate(row, ncols, xa - (col0 << SHIFT), ca - top, xb - (col0 << SHIFT), cb - top);
            else               accumulate(row, ncols, xb - (col0 << SHIFT), cb - top, xa - (col0 << SHIFT), ca - top);
        }
        if (hi < 0) continue;                                     /* nothing on this row */
        for (i = lo; i < ncols; i++) {                            /* the sweep */
            int a;
            if (i > hi) { if (cov == 0) break; a = cov * (SUB * 2); }   /* run-out to the right */
            else { cov += row[i].cover; a = cov * (SUB * 2) - row[i].area; }
            a >>= (2 * SHIFT + 1 - 8);                            /* -> 0..256, signed */
            if (a < 0) a = -a;
            if (a > 255) a = 255;
            if (a) put(user, ox + col0 + i, oy + py, ((uint32_t)a << 24) | (color & 0xffffffu));
        }
    }
}

void lomono_draw_text(int *x, int *y, int cell_h, const char *text,
                      lomono_pixel_fn put, void *user, uint32_t color)
{
    static const lomono_sink sink = { r_move, r_line, r_quad, r_close };
    int x0 = *x, adv;
    raster r;
    if (cell_h > LOMONO_MAX_CELL_H) cell_h = LOMONO_MAX_CELL_H;
    adv = lomono_cell_w(cell_h);
    r.scale = (cell_h * SUB) / LOMONO_CELL_H;                     /* fixed point pixels per unit */
    for (; *text; text++) {
        if (*text == '\n') { *x = x0; *y += cell_h; continue; }
        r.n = 0; r.ymin = r.xmin = 1 << 30; r.ymax = r.xmax = -(1 << 30);
        if (lomono_glyph((unsigned char)*text, &sink, &r) && r.n) fill(&r, *x, *y, put, user, color);
        *x += adv;
    }
}
