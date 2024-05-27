/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-mypaint-matteo.aufiero
** File description:
** but_functions
*/

#include "my.h"
#include <ctype.h>

int erase_canvas(data_t *data)
{
    for (int i = 0; i < 4 * 1920 * 1080; i += 4) {
        data->pix_tab[i] = 0;
        data->pix_tab[i + 1] = 0;
        data->pix_tab[i + 2] = 0;
        data->pix_tab[i + 3] = 0;
    }
    return 0;
}

int eraser(data_t *data)
{
    data->a = 0;
    return 0;
}

int pencil(data_t *data)
{
    data->tool = 1;
    data->a = 255;
    return 0;
}

int size(data_t *data)
{
    data->isResizing = sfTrue;
    return 0;
}

int exit_window(data_t *data)
{
    sfRenderWindow_close(data->window);
    return 0;
}
