// sans_lomono.h - Sans Lomono 1.0 (September 2026), a tiny vector debug font.
//
// Chris Lomont, 2026, www.lomont.org
// License: do whatever you want with this file, forever, anywhere, with no
// attribution required.  It is provided as is, with no warranty of any kind;
// the author is not liable for anything that happens because of it.
//
// The 95 printable ASCII characters (32..126) as outlines of lines and
// quadratic beziers, in 1806 bytes of data and about 60 lines of decoder.
// Monospaced.  No serifs.  No hinting.  No RAM.  No shame.
//
// Two ways to use it:
//
//   1. lomono_glyph()      gives you the outline of one character as move /
//                        line / quad / close callbacks, for your own vector
//                        rasterizer.  Fill with the NON-ZERO winding rule.
//   2. lomono_draw_text()  draws a string straight into pixels through a
//                        put-pixel callback, anti-aliased with exact area
//                        coverage, newlines included.  What you want at 3 a.m.
//
// ---------------------------------------------------------------------------
// Metrics.  Units are 1/LOMONO_SCALE (= 1/2) of a design unit.  y goes UP,
// the baseline is y = 0, and a character's origin is the left edge of its
// cell.  Every character advances LOMONO_ADVANCE.
//
//     cell top       LOMONO_TOP      32   ( nothing pokes above this )
//     cap height     LOMONO_CAP      28   capitals, digits, ascenders, i/j dots
//     x-height       LOMONO_XHEIGHT  20   top of lowercase
//     baseline                      0
//     cell bottom    LOMONO_BOTTOM   -8   descenders of g j p q y stop here
//     advance        LOMONO_ADVANCE  24
//     stroke width   LOMONO_STROKE    4
//
// A text cell is LOMONO_ADVANCE wide by LOMONO_CELL_H (= 40) tall, with the
// baseline LOMONO_TOP below the top of the cell.  Scaling to a cell H pixels
// tall means multiplying every coordinate by H / 40.  Round letters do not
// overshoot; everything sits exactly on these lines, so text tiles a grid
// with no surprises.
//
// ---------------------------------------------------------------------------
// The data (in sans_lomono.c), for the curious and the porting:
//
// Character c is the bit string lomono_char_data[lomono_char_starts[c-32] ..
// lomono_char_starts[c-31]), read most significant bit first.  Space is empty.
//
// A point is one LOMONO_PT_BITS (= 10) bit unsigned integer v, mixed radix:
//     x = v / LOMONO_YRANGE + LOMONO_XMIN        (LOMONO_YRANGE = 39, LOMONO_XMIN = 1)
//     y = v % LOMONO_YRANGE + LOMONO_YMIN        (LOMONO_YMIN = -8)
// 24 x-values times 39 y-values is 936 < 1024, so a point is 10 bits instead
// of 5 + 6.  One divide buys a bit per point.
//
// Ops are prefix codes followed by their operands:
//     0     L  point           line to point
//     10    Q  point point     quadratic bezier via control point to point
//     110   M  point           start a new contour at point
//     111   R  index point     start a new contour by copying shared shape
//                              `index` (LOMONO_REF_BITS = 5 bits), translated
//                              so its first point lands on point
// There is no close op.  A contour closes when the next M or R begins or
// the character ends.  A character always begins with a contour, so its
// leading 11 is not stored: the first bit is just the M/R selector.  After
// an R nothing can follow except 11 or the end.
//
// Padding to the byte boundary is zero bits.  Stop reading when fewer than
// 1 + LOMONO_PT_BITS = 11 bits remain: a zero padding bit would read as an L
// wanting a 10 bit point, and there are never more than 7 padding bits, so
// padding can never impersonate data.
//
// Shared shape i is the bit string lomono_shape_data[lomono_shape_starts[i] ..
// lomono_shape_starts[i+1]): its first point (no selector bit), then L and Q
// ops only, zero padded.  Shapes are the contours several characters use at
// different positions: stems, dots, three bar lengths, the lowercase bowl,
// the capital O, the little rings of % and @.  24 shapes, referenced 90 times.
//
// Fill rule is NON-ZERO winding.  Strokes overlap on purpose (the bowl of P
// lies on its stem) and the fill unions them; outer contours are clockwise
// with y up, holes counter-clockwise.  Even-odd will give you holes where
// strokes cross.  You have been warned.
//
// ---------------------------------------------------------------------------
// Statistics, for the byte counters among us:
//
//     characters             95   ASCII 32..126
//     contours              161   504 lines, 364 quadratics, 1393 points
//     shared shapes          24   referenced 90 times
//
//     character bit strings   1313 bytes   lomono_char_data
//     character offsets        192 bytes   lomono_char_starts (96 x uint16)
//     shared shape strings     276 bytes   lomono_shape_data
//     shared shape offsets      25 bytes   lomono_shape_starts
//     total                   1806 bytes
//
//     average per character   13.8 bytes, 14.7 points
//
// Code (clang -Oz): the outline decoder alone is about 570 bytes of Thumb-2
// on a Cortex-M4 and about 840 bytes on x86-64; decoder plus the pixel text
// writer, about 2.2 KB and 2.9 KB.  The text writer uses about 2.3 KB
// of stack for its edge list and one row of cells (both sizes are #ifndef
// knobs in the .c, under 1 KB is possible); the decoder uses a few locals.
// ---------------------------------------------------------------------------
#ifndef SANS_LOMONO_H
#define SANS_LOMONO_H
#include <stdint.h>

enum {
    LOMONO_SCALE = 2, LOMONO_ADVANCE = 24, LOMONO_XHEIGHT = 20, LOMONO_CAP = 28,
    LOMONO_TOP = 32, LOMONO_BOTTOM = -8, LOMONO_STROKE = 4,
    LOMONO_CELL_H = LOMONO_TOP - LOMONO_BOTTOM,          /* 40 */
    LOMONO_FIRST = 32, LOMONO_COUNT = 95,
    LOMONO_PT_BITS = 10, LOMONO_YRANGE = 39, LOMONO_XMIN = 1, LOMONO_YMIN = -8,
    LOMONO_REF_BITS = 5
};

/* Outline callbacks.  Coordinates are integers in 1/LOMONO_SCALE units, y up. */
typedef struct lomono_sink {
    void (*move)(void *user, int x, int y);                  /* start a contour   */
    void (*line)(void *user, int x, int y);                  /* line to           */
    void (*quad)(void *user, int cx, int cy, int x, int y);  /* quad via cx,cy to */
    void (*close)(void *user);                               /* back to the start */
} lomono_sink;

/* Emit the outline of character ch (32..126).  Returns 1, or 0 for a
 * character the font does not have (nothing is emitted for those). */
int lomono_glyph(int ch, const lomono_sink *sink, void *user);

/* Your pixel.  Called once per pixel the text touches, left to right, top
 * to bottom, with the text color in the low 24 bits (as you passed it) and
 * the pixel's coverage in the top byte: 255 = fully inside the outline,
 * 1..254 = the edge runs through it.  Blend it however your surface likes;
 * demo.c does it properly in linear light. */
typedef void (*lomono_pixel_fn)(void *user, int x, int y, uint32_t rgba);

/* Draw text with the top left of the first cell at (*x, *y), each cell
 * cell_h pixels tall (and lomono_cell_w(cell_h) wide).  '\n' returns to the
 * starting x and moves down one cell.  Characters outside 32..126 advance
 * silently.  On return *x, *y is where the next character would go, so you
 * can keep calling to append.
 *
 * Anti-aliased with exact area coverage (the integer cover/area scanline
 * technique), non-zero winding, one pixel row at a time, visiting only the
 * rows and columns a character can reach.  Uses about 2.3 KB of stack (an
 * edge list and one row of cells; see LOMONO_MAX_EDGES / LOMONO_MAX_COLS in
 * the .c to shrink it) and no heap.  Cells taller than 500 px are drawn at
 * 500; cells wider than LOMONO_MAX_COLS pixels are clipped on the right. */
void lomono_draw_text(int *x, int *y, int cell_h, const char *text,
                    lomono_pixel_fn put, void *user, uint32_t color);

/* Cell width in pixels for a cell height, rounded to nearest. */
static inline int lomono_cell_w(int cell_h) { return (LOMONO_ADVANCE * cell_h + LOMONO_CELL_H / 2) / LOMONO_CELL_H; }

#endif
