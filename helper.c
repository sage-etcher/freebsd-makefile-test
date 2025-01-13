
#include "helper.h"

#include <SDL2/SDL.h>
#include <stddef.h>
#include <stdlib.h>


typedef struct my_app
{
    SDL_Window *win;
    SDL_Renderer *rend;
    SDL_Rect size;
    SDL_Color bg;
    int should_quit;
} my_app_t;


static SDL_Color hex_to_color (uint32_t hex, uint8_t alpha);


int
app_should_quit (my_app_t *app)
{
    return app->should_quit;
}


void
app_quit (my_app_t *app)
{
    app->should_quit = 1;
    return;
}


void
app_free (my_app_t *app)
{
    /* zero data */
    (void)memset (app, 0, sizeof (my_app_t));

    /* free structure */
    free (app);

    return;
}


my_app_t *
app_alloc (void)
{
    /* allocate structure */
    my_app_t *app = malloc (sizeof (my_app_t));
    if (!app) return NULL;

    /* default all to null */
    (void)memset (app, 0, sizeof (my_app_t));
   
    return app;
}


int
app_create_window (my_app_t *app, char *title, int w, int h)
{
    const int win_flags = SDL_WINDOW_RESIZEABLE;
    const int rend_flags = SDL_RENDERER_ACCEL | SDL_RENDERER_VSYNC;

    const int auto_pos = SDL_DEFAULT_POS;

    app->win = SDL_CreateWindow (title, auto_pos, auto_pos, w, h, win_flags);
    app->rend = SDL_CreateRenderer (app->win, -1, rend_flags);

    if ((!app->win) || (!app->rend))
    {
        app_destroy_window (app);
        return 1;
    }

    return 0;
}


void
app_destroy_window (my_app_t *app)
{
    SDL_DestroyRenderer (app->rend);
    SDL_DestroyWindow (app->win);

    app->rend = NULL;
    app->win  = NULL;

    return;
}


static SDL_Color
hex_to_color (uint32_t hex, uint8_t alpha)
{
    /* hex to rgba */
    SDL_Color color = {
        .r = ((hex & 0x00FF0000) >> (2*8)),
        .g = ((hex & 0x0000FF00) >> (1*8)),
        .b = ((hex & 0x000000FF) >> (0*8)),
        .a = alpha,
    };

    return color;
}


void
app_draw_background (my_app_t *app)
{
    SDL_SetDrawColor (app->rend, app->bg.r, app->bg.g, app->bg.b, app->bg.a);
    SDL_RenderClear (app->rend);
    return;
}


void
app_background_color (my_app_t *app, uint32_t hex, uint8_t alpha)
{
    app->bg = hex_to_color (hex, alpha);
    return;
}


void
app_handle_events (my_app_t *app)
{
    SDL_Event e;

    while (SDL_PollEvent (&e)) 
    {
        switch (e.type)
        {
        case SDL_QUIT:
            app_quit (app);
            return;
        }
    }

    return;
}


/* end of file */
