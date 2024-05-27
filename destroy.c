/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-mypaint-matteo.aufiero
** File description:
** destroy
*/

#include "my.h"

int destroy_all(data_t *data)
{
    sfClock *clock = sfClock_create();

    sfClock_getElapsedTime(clock);
    sfClock_destroy(clock);
    for (int i = 0; i < 9; i++) {
        sfTexture_destroy(data->buttons[i]->texture[0]);
        sfTexture_destroy(data->buttons[i]->texture[1]);
        sfTexture_destroy(data->buttons[i]->texture[2]);
        sfSprite_destroy(data->buttons[i]->sprite);
        free(data->buttons[i]->texture);
        free(data->buttons[i]);
    }
    free(data->buttons);
    sfTexture_destroy(data->canvas_texture);
    sfSprite_destroy(data->canvas);
    sfRenderWindow_destroy(data->window);
    free(data->pix_tab);
    free(data);
    return 0;
}
