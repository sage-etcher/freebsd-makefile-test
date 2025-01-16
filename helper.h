
#ifndef HELPER_HEADER
#define HELPER_HEADER

#include <stdint.h>

typedef struct my_app my_app_t;

#define OPAQUE 0xff
#define TRANSPARENT 0x00

int app_init (void);
void app_quit (void);

my_app_t *app_alloc (void);
void app_free (my_app_t *app);

int  app_create_window  (my_app_t *app, char *title, int w, int h);
void app_destroy_window (my_app_t *app);
void app_handle_events  (my_app_t *app);

void app_background_color (my_app_t *app, uint32_t hex, uint8_t alpha);
void app_draw_background (my_app_t *app);
void app_present (my_app_t *app);

int  app_should_exit (my_app_t *app);
void app_exit (my_app_t *app);



#endif
/* end of file */
