#ifndef _APP_H
#define _APP_H

#include <SDL.h>

#include <string>
#include <vector>

#include "Event.h"
#include "Surface.h"
#include "GameState.h"

using namespace std;

class GameState;

class App : public Event
{
    public:
        App(std::string appname, int width, int height);

        int Execute();

        bool OnInit();
        bool OnLoad();
        void OnEvent(SDL_Event event);
            void OnExit();
            void OnKeyDown( SDLKey sym , SDLMod mod , Uint16 unicode );
        void OnUpdate();
        void OnRender();
        void OnCleanup();

        void ChangeState(GameState *state);
        void PushState(GameState *state);
        void PopState();

    private:
        std::string m_appname;
        int m_winW;
        int m_winH;
        int m_winB;
        int m_time;
        int m_timeNow;
        int m_timeBefore;
        int m_running;

        SDL_Surface *test;

        vector<GameState*> states;

    public:
        SDL_Surface *m_screen;
        SDL_Event m_event;
};


#endif
