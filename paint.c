/*
** EPITECH PROJECT, 2024
** bspaint
** File description:
** bs_paint
*/

#include "my.h"

void set_pixels(data_t *data)
{
    data->pix_tab = malloc(sizeof(sfUint8) * (4 * 1920 * 1080 + 1));
    for (int i = 0; i != 4 * 1920 * 1080; i += 4) {
        data->pix_tab[i] = 0;
        data->pix_tab[i + 1] = 0;
        data->pix_tab[i + 2] = 0;
        data->pix_tab[i + 3] = 0;
    }
    data->canvas = sfSprite_create();
    data->canvas_texture = sfTexture_create(1196, 677);
    sfTexture_updateFromPixels(data->canvas_texture, data->pix_tab,
    1196, 677, 0, 0);
    sfSprite_setTexture(data->canvas, data->canvas_texture, sfTrue);
    sfRenderWindow_drawSprite(data->window, data->canvas, NULL);
    sfSprite_setPosition(data->canvas, (sfVector2f){196, 123});
}

int main(int ac, __attribute__((unused))char **av)
{
    data_t *data = init_data();

    if (ac != 1)
        return 84;
    while (sfRenderWindow_isOpen(data->window)) {
        manage_events(data);
        check_buttons(data);
        display_window(data);
    }
    destroy_all(data);
    return 0;
}
