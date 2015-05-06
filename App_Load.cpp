#include "App.h"

bool App::OnLoad()
{
    test = Surface::LoadSurfaceTransparent("data\\spaceship1.bmp", 0, 0, 0);
    if( test == NULL )
    {
        fprintf( stderr, "[ Error ] Error while loading image\n");
        return false;
    }

    return true;
}
