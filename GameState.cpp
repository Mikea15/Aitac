#include "GameState.h"

GameState::GameState()
{
}

void ChangeState(App *game, GameState* state);
{
    game->ChangeState(state);
}
