
#ifndef _INTRO_H
#define _INTRO_H

class IntroState : public GameState
{
    public:
        void OnInit();
        void OnCleanup();

        void Pause();
        void Resume();

        void OnEvent(SDL_Event event);
        void OnUpdate();
        void OnRender();

        void ChangeState(App *game, GameState *state);

};

#endif
