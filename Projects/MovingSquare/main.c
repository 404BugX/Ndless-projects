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

    while (1) {
        SDL_FillRect(screen, NULL, Background);
        SDL_FillRect(screen, &(SDL_Rect){x, y, size, size}, Square);
        SDL_Flip(screen);

        if (isKeyPressed(KEY_NSPIRE_ESC)) return 0;
        if ((isKeyPressed(KEY_NSPIRE_UP)) && !(y < 1)) y--; 
        if ((isKeyPressed(KEY_NSPIRE_DOWN)) && !(y > 239 - size))  y++;
        if ((isKeyPressed(KEY_NSPIRE_LEFT)) && !(x < 1))  x--;
        if ((isKeyPressed(KEY_NSPIRE_RIGHT)) && !(x > 319 - size)) x++;

    }
    return 0;
}
