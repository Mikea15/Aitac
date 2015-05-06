#include "Surface.h"

Surface::Surface()
{
}
/** this function loads the surfaces */
SDL_Surface * Surface::LoadSurface( std::string filename )
{
    SDL_Surface * temp = NULL, *ret = NULL;

    if((temp = IMG_Load(filename.c_str())) == NULL) {

        return NULL;
    }

    ret = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);

    return (ret);
}

SDL_Surface * Surface::LoadSurfaceTransparent( std::string filename , int ColorR , int ColorG , int ColorB )
{
    SDL_Surface * temp = NULL, *ret = NULL;

    if((temp = IMG_Load(filename.c_str())) == NULL) {

        return NULL;
    }

    if( ( ColorR <= 255 && ColorR >= 0 ) && ( ColorG <= 255 && ColorG >= 0 ) && ( ColorB <= 255 && ColorB >= 0 ) )
        SDL_SetColorKey(temp, SDL_SRCCOLORKEY | SDL_RLEACCEL , SDL_MapRGB(temp->format, ColorR, ColorG, ColorB));
    else
    {
        fprintf(stderr, "( ! ) - Could not Set the Color of the Surface your trying to load transparent\n");
        return(NULL);
    }

    ret = SDL_DisplayFormatAlpha(temp);
    SDL_FreeSurface(temp);

    return(ret);
}

/** this functions blits the surfaces on the screen */
bool Surface::OnDraw( SDL_Surface *Target, SDL_Surface *Source, int X, int Y )
{
    if(Target == NULL || Source == NULL)
    {
        return false;
    }

    SDL_Rect pos;
    pos.x = X;
    pos.y = Y;

    SDL_BlitSurface(Source, NULL, Target, &pos);
    return true;
}

/** this functions blits the surfaces on the screen */
bool Surface::OnDraw( SDL_Surface *Target , SDL_Surface *Source , SDL_Rect dist )
{
    if(Target == NULL || Source == NULL)
    {
        return false;
    }

    SDL_BlitSurface(Source, NULL, Target, &dist);
    return true;
}

/** this function blits a cutted part of an image */
bool Surface::OnDraw( SDL_Surface *Target, SDL_Surface *Source, int X, int Y, int X2, int Y2, int W, int H )
{
    if(Target == NULL || Source == NULL)
    {
        return false;
    }

    SDL_Rect pos;
    pos.x = X;
    pos.y = Y;

    SDL_Rect SrcR;

    SrcR.x = X2;
    SrcR.y = Y2;
    SrcR.w = W;
    SrcR.h = H;

    SDL_BlitSurface(Source, &SrcR, Target, &pos);
    return true;
}

/** this function blits a cutted part of an image */
bool Surface::OnDraw( SDL_Surface *Target, SDL_Surface *Source , SDL_Rect dist , int X2 , int Y2 , int W , int H )
{
    if(Target == NULL || Source == NULL)
    {
        return false;
    }

    SDL_Rect SrcR;

    SrcR.x = X2;
    SrcR.y = Y2;
    SrcR.w = W;
    SrcR.h = H;

    SDL_BlitSurface(Source, &SrcR, Target, &dist);
    return true;
}

/** this function fills the target with a desired color */
bool Surface::OnFill( SDL_Surface *Target , int ColorR , int ColorG , int ColorB )
{
    if(Target == NULL)
    {
        return false;
    }

    if( ( ColorR <= 255 && ColorR >= 0 ) && ( ColorG <= 255 && ColorG >= 0 ) && ( ColorB <= 255 && ColorB >= 0 ) )
    {
        SDL_FillRect(Target, NULL, SDL_MapRGB(Target->format, ColorR, ColorG, ColorB));
        return true;
    }
    else
    {
        return false;
    }
}

/** this functions sets a color from a surface transparent */
bool Surface::SetTransparent( SDL_Surface *Target , int ColorR , int ColorG , int ColorB )
{
    if(Target == NULL)
    {
        return false;
    }

    if( ( ColorR <= 255 && ColorR >= 0 ) && ( ColorG <= 255 && ColorG >= 0 ) && ( ColorB <= 255 && ColorB >= 0 ) )
    {
        SDL_SetColorKey(Target, SDL_SRCCOLORKEY | SDL_RLEACCEL , SDL_MapRGB(Target->format, ColorR, ColorG, ColorB));
        return true;
    }
    else
    {
        return false;
    }
}

/** this functions sets the surface alpha ( transparancy ) */
bool Surface::SetAlpha( SDL_Surface *Target , int Alpha )
{
    if(Target == NULL)
    {
        return false;
    }

    if( Alpha <= 255 && Alpha >= 0 )
    {
        SDL_SetAlpha(Target, SDL_SRCALPHA, Alpha);
        return true;
    }
    else
    {
        return false;
    }
}

SDL_Surface * Surface::RotoZoom( SDL_Surface *target, float angle, float zoom, int smoothing )
{
    SDL_Surface *temp = NULL;
    temp = rotozoomSurface(target, angle, zoom, smoothing);
    SDL_FreeSurface(target);
    return(temp);
}

