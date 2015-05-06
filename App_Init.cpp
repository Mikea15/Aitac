#include "App.h"

bool App::OnInit()
{
    // init SDL in Video Mode
    fprintf( stdout, "[ SDL ] - SDL Init - ");
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        fprintf( stdout, "Error: %s\n", SDL_GetError() );
        return false;
    }
    fprintf( stdout, "Ok\n" );


    // create screen
    fprintf( stdout, "[ SDL ] - VideoMode %dx%d @ %dbits - ", m_winW, m_winW, m_winB);
    if ( ( m_screen = SDL_SetVideoMode( m_winW, m_winH, m_winB, SDL_HWSURFACE | SDL_DOUBLEBUF ) ) == NULL )
    {
        fprintf( stdout, "Error: %s\n", m_winW, m_winW, m_winB, SDL_GetError() );
        return false;
    }
    fprintf( stdout, "Ok\n" );

    // set window title
    SDL_WM_SetCaption( m_appname.c_str(), NULL );
    fprintf( stdout, "[ SDL ] - Set Window Title - Ok");

    return true;
}

