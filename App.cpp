#include "App.h"


App::App(std::string appname, int width, int height)
{
    m_appname = appname;
    m_winW = width;
    m_winH = height;
    m_winB = 32;

    m_timeBefore = 0;
    m_timeNow = 0;
    m_time = 300; // milliseconds

    test = NULL;
}

int App::Execute()
{

    if( OnInit() == false )
    {
        fprintf(stderr, "[ Init ] Error \n");
        return EXIT_FAILURE;
    }

    if( OnLoad() == false )
    {
        fprintf(stderr, "[ Load ] Error \n");
        return EXIT_FAILURE;
    }


    while(m_running)
    {
        SDL_PollEvent(&m_event);

        OnEvent(m_event);

        m_timeNow = SDL_GetTicks();
        if (m_timeNow - m_timeBefore > m_time )
        {
            OnUpdate();
            m_timeBefore = m_timeNow;
        }
        else
        {
            SDL_Delay( m_time - (m_timeNow - m_timeBefore) );
        }

        OnRender();
    }

    OnCleanup();

    return EXIT_SUCCESS;
}

// this is when we clean one state and go to another
void App::ChangeState(GameState *state)
{
	// cleanup the current state
	if ( !states.empty() ) {
		states.back()->OnCleanup(); // states.back = last element .. Cleanup.
		states.pop_back(); // delete last element
	}

	// store and init the new state
	states.push_back(state); // add element at end of the vector
	states.back()->OnInit(); // init element
}

// to pause, for any menu or so to go but come back right after
void App::PushState(GameState *state)
{
	// pause current state
	if ( !states.empty() ) {
		states.back()->Pause();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->OnInit();
}

// to kill.
void App::PopState()
{
	// cleanup the current state
	if ( !states.empty() ) {
		states.back()->OnCleanup();
		states.pop_back();
	}

	// resume previous state
	if ( !states.empty() ) {
		states.back()->Resume();
	}
}
