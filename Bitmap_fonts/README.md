# bitmap fonts

Header-only bitmap fonts. Requires SDL 1.2 (-lSDL)

| File | Size | Function |
|---|---|---|
| `font_3x5.h` | 3×5 px | `draw_text3` / `draw_char3` |
| `font_5x7.h` | 5×7 px | `draw_text` / `draw_char` |
| `font_8x8.h` | 8×8 px | `draw_text8` / `draw_char8` |

## Example usage

```c
#include <SDL/SDL.h>
#include "font_5x7.h"

Uint32 white = SDL_MapRGB(screen->format, 255, 255, 255);

draw_text(screen, "Hello!", x, y, white, &font_5x7);
draw_text8(screen, "Title", x, y, white, &font_8x8);
draw_text3(screen, "x:10 y:20", x, y, white, &font_3x5);
```

Supports `\n` for line breaks. ASCII 32–126.
