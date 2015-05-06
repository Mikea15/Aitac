#ifndef _SM_H
#define _SM_H


class GameState
{
    public:
        GameState();

        virtual void OnInit();
        virtual void OnCleanup();

        virtual void Pause();
        virtual void Resume();

        virtual void OnEvent(SDL_Event event);
        virtual void OnUpdate();
        virtual void OnRender(App *game);

        void ChangeState(App *game, GameState *state);

};

#endif
