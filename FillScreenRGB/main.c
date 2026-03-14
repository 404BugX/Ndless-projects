#include <libndls.h>
#include <os.h>
#include <SDL/SDL.h>


int main(void) {
    
    unsigned int choix = show_msgbox_2b("WARNING", "Epilepsy warning!", "Proceed", "Quit");
    if (choix == 2) return 0;

    msleep(100);

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface *screen = SDL_SetVideoMode(320, 240, 16, SDL_SWSURFACE);
    SDL_ShowCursor(SDL_DISABLE);
    
    while (1) {
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 0, 0));
        SDL_Flip(screen);
        if (any_key_pressed()) {break;}
        msleep(100);
        
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 255, 0));
        SDL_Flip(screen);
        if (any_key_pressed()) {break;}
        msleep(100);
        
        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 255));
        SDL_Flip(screen);
        if (any_key_pressed()) {break;}
        msleep(100);

        
    }

    return 0;
}
