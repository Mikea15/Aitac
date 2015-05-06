#include "App.h"

void App::OnCleanup()
{
    SDL_FreeSurface(m_screen);
    SDL_FreeSurface(test);
    SDL_Quit();
}
