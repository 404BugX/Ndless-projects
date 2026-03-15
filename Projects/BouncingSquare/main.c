#include <libndls.h>
#include <os.h>
#include <SDL/SDL.h>

int main(void) {

    char *valeur;
    show_msg_user_input("Size", "Input a size for the Square", "15", &valeur);
    int size = atoi(valeur);
    free(valeur);

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface *screen = SDL_SetVideoMode(320, 240, 16, SDL_SWSURFACE);
    SDL_ShowCursor(SDL_DISABLE);

    Uint32 Background = SDL_MapRGB(screen->format, 5, 25, 5);
    Uint32 Square = SDL_MapRGB(screen->format, 0, 230, 0);

    int x = 320/2-size/2;
    int y = 240/2-size/2;

    int dsx = 2;
    int dsy = 2;
    int bx = 12;
    int by = 12;
    int vx = dsx;
    int vy = dsy;

    while (1) {
        SDL_FillRect(screen, NULL, Background);
        SDL_FillRect(screen, &(SDL_Rect){x, y, size, size}, Square);
        SDL_Flip(screen);

        // Up : y < 0
        // Down : y > 240 - size
        // Left : x < 0
        // Right : x > 320 - size

        if (x < 0 || x > 320 - size) {if (vx > 0) vx = -(dsx + bx); else vx = dsx + bx;}
        if (y < 0 || y > 240 - size) {if (vy > 0) vy = -(dsy + by); else vy = dsy + by;}

        if (vx > 0) {if (vx != dsx) vx -= 1;} else if (vx != -dsx) vx += 1;
        if (vy > 0) {if (vy != dsy) vy -= 1;} else if (vy != -dsy) vy += 1;

        x += vx;
        y += vy;

        if (isKeyPressed(KEY_NSPIRE_ESC)) return 0;
        msleep(35);
    }
    return 0;
}
