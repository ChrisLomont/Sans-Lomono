# History

## 1.1, 2026-09-19

Shape cleanup after looking at a large white-on-black proof rendered with a
different rasterizer. No format, API or metric changes; every glyph still
sits exactly on its metric lines. Fixes, in the order they were made
(times are US Eastern):

| time  | glyph | fix |
|-------|-------|-----|
| 10:45 | `&`   | rebuilt as one tangent-continuous path: the diagonal flows into the upper bowl, the descent runs straight into a circular arc round the lower bowl, the tail is cut perpendicular to the stroke and ends higher so it stands clear of the diagonal's foot. Three fewer points. |
| 10:55 | `3`   | top and bottom hooks are now mirror images about the middle bar (they end at y = 9.5 and 4.5). |
| 11:00 | `6`   | the bowl's closing stroke ends a unit higher, where the stem is still straight, so its cap no longer pokes past the curving stem edge. |
| 11:02 | `9`   | the right side is a straight stem from a rounded corner at y = 6.5 up to the top bowl, and the closing stroke ends on that straight run. |
| 11:08 | `a`   | the left end of the top bar is half a unit higher. |
| 11:12 | `m`   | the stem's top continues as a short bar out to the first arch's apex, removing the sliver where the square stem corner stood 0.13 above the arch. |
| 11:15 | `t`   | crossbar shortened to end flush with the right end of the base. |
| 11:20 | `~`   | outline is now exactly symmetric under 180-degree rotation (the 45-degree crossing had no symmetric grid pair and snapped lopsided). |

Considered and rejected: widening the clipped-mitre apexes of `V v W w M A ^`
from 1 to 2 units (cost 9 points, the 1.0 apexes are fine), and a redrawn `@`
(kept the 1.0 glyph).

Point count 1393 to 1394; packed data size in `sans_lomono.h`.

## 1.0, 2026-09-12

First release.
