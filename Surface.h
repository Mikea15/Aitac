#ifndef _SURFACE_H_
#define _SURFACE_H_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_rotozoom.h>

#include <string>

class Surface
{
    public:
        Surface();

    public:
        static SDL_Surface * LoadSurface( std::string filename );
        // load image and set transparent
        static SDL_Surface * LoadSurfaceTransparent( std::string filename , int ColorR = 0, int ColorG = 0, int ColorB = 0 );
        static bool OnDraw( SDL_Surface *Target, SDL_Surface *Source, SDL_Rect dist );
        static bool OnDraw( SDL_Surface *Target, SDL_Surface *Source, int X, int Y ); // alt
        static bool OnDraw( SDL_Surface *Target, SDL_Surface *Source, int X, int Y, int X2, int Y2, int W, int H );
        static bool OnDraw( SDL_Surface *Target, SDL_Surface *Source, SDL_Rect dist, int X2, int Y2, int W, int H ); // alt
        static bool OnFill( SDL_Surface *Target, int ColorR = 0, int ColorG = 0, int ColorB = 0 ); // fill surface
        static bool SetTransparent( SDL_Surface *Target, int ColorR = 0, int ColorG = 0, int ColorB = 0 ); // set color transparent
        static bool SetAlpha( SDL_Surface *Target, int Aplha ); // set alpha on surface.
        /** WIP */
        static SDL_Surface * RotoZoom( SDL_Surface *target, float angle, float zoom = 1, int smoothing = SMOOTHING_OFF );

};

#endif

