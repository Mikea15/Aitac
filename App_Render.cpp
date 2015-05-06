#include "App.h"

void App::OnRender()
{
    Surface::OnFill(m_screen, 255, 255, 255);

    Surface::OnDraw(m_screen, test, 50, 50);

    SDL_Flip(m_screen);
}
