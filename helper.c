
#include "helper.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

#include <stdint.h> /* NOLINT: Allow indirect header include */
#include <stdlib.h>
#include <string.h>


typedef struct my_app
{
    SDL_Window *win;
    SDL_Renderer *rend;
    SDL_Rect size;
    SDL_Color bg;
    int should_exit;
} my_app_t;


static SDL_Color hex_to_color (uint32_t hex, uint8_t alpha);


int
app_init (void)
{
    const int SDL_FLAGS = SDL_INIT_EVENTS | SDL_INIT_VIDEO;
    return SDL_Init (SDL_FLAGS);
}


void
app_quit (void)
{
    SDL_Quit ();
}


int
app_should_exit (my_app_t *app)
{
    return app->should_exit;
}


void
app_exit (my_app_t *app)
{
    app->should_exit = 1;
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
    if (!app) { return NULL; }

    /* default all to null */
    (void)memset (app, 0, sizeof (my_app_t));

    return app;
}


int
app_create_window (my_app_t *app, char *title, int width, int height)
{
    const int win_flags = SDL_WINDOW_RESIZABLE;
    const int rend_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

    const int auto_pos = SDL_WINDOWPOS_UNDEFINED;

    app->win = SDL_CreateWindow (title, auto_pos, auto_pos, width, height, win_flags);
    app->rend = SDL_CreateRenderer (app->win, 0, rend_flags);

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
    app->win = NULL;

    return;
}


static SDL_Color
hex_to_color (uint32_t hex, uint8_t alpha) /* NOLINT: Allow adjacent convertible params */
{
    /* hex to rgba */
    const int BITS_PER_COLOR = 8;
    const int R_MASK = 0x00FF0000;
    const int G_MASK = 0x0000FF00;
    const int B_MASK = 0x000000FF;

    SDL_Color color = {0};
    color.r = (hex & R_MASK) >> (2 * BITS_PER_COLOR);
    color.g = (hex & G_MASK) >> (1 * BITS_PER_COLOR);
    color.b = (hex & B_MASK) >> (0 * BITS_PER_COLOR);
    color.a = alpha;

    return color;
}


void
app_draw_background (my_app_t *app)
{
    SDL_SetRenderDrawColor (app->rend, app->bg.r, app->bg.g, app->bg.b, app->bg.a);
    SDL_RenderClear (app->rend);
    return;
}


void
app_present (my_app_t *app)
{
    SDL_RenderPresent (app->rend);
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
    SDL_Event event;

    while (SDL_PollEvent (&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            app_exit (app);
            return;

        default:
            break;
        }
    }

    return;
}


/* end of file */
