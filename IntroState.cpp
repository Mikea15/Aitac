
void IntroState::OnRender(App *game)
{
    Surface::OnFill(game->m_screen, 2, 25, 255);

    SDL_Flip(game->m_screen);
}
