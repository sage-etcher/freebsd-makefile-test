
#include <stddef.h>
#include "helper.h"


int 
main (int argc, char **argv)
{
    my_app_t *app = NULL;

    app_init ();

    app = app_alloc ();
    app_create_window (app, "my app", 640, 480);
    app_background_color (app, 0xffaabb, OPAQUE);

    /* runtime loop */
    while (!app_should_exit (app))
    {
        /* handle events */
        app_handle_events (app);
        if (app_should_exit (app)) goto main_exit;

        /* draw the window */
        app_draw_background (app);
        app_present (app);
    }

main_exit:
    /* free */
    app_destroy_window (app);
    app_free (app);
    app = NULL;

    app_quit ();

    return 0;
}


/* end of file */
