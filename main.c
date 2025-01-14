
#include <stddef.h>
#include "helper.h"


int 
main (int argc, char **argv)
{
    my_app_t *app = NULL;


    app = app_alloc ();
    app_create_window (app, "my app", 640, 480);
    app_background_color (app, 0xffaabb, 0xff);

    /* runtime loop */
    while (!app_should_quit (app))
    {
        /* handle events */
        app_handle_events (app);
        if (app_should_quit (app)) goto main_exit;

        /* draw the window */
        app_draw_background (app);
    }

main_exit:
    /* free */
    app_destroy_window (app);
    app_free (app);
    app = NULL;
    return 0;
}


/* end of file */
