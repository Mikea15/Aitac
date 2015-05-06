#include "App.h"

void App::OnEvent(SDL_Event event)
{
    Event::OnEvent(event);
}

void App::OnExit()
{
    m_running = false;
}

void App::OnKeyDown( SDLKey sym , SDLMod mod , Uint16 unicode )
{
    switch(sym)
    {
        case SDLK_ESCAPE:
            OnExit();
        break;
        default: break;
    }
}
