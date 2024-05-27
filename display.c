/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-mypaint-matteo.aufiero
** File description:
** display
*/

#include "my.h"


void display_pixels(data_t *data)
{
    sfTexture_updateFromPixels(data->canvas_texture, data->pix_tab,
    1196, 677, 0, 0);
    sfRenderWindow_drawSprite(data->window, data->canvas, NULL);
}

void check_pixels(data_t *data, int i)
{
    int x;
    int y;
    int index;

    x = data->mouse_pos.x - 196 + i;
    y = data->mouse_pos.y - 123;
    if (x < 0 || x > 1196 || y < 0 || y > 677)
        return;
    index = (x + y * 1196) * 4;
    data->pix_tab[index] = data->r;
    data->pix_tab[index + 1] = data->g;
    data->pix_tab[index + 2] = data->b;
    data->pix_tab[index + 3] = data->a;
    data->old_pos = data->new_pos;
    data->new_pos = (sfVector2f){x, y};
    if (data->old_pos.x != -1 && data->old_pos.y != -1)
        fill_between(data);
}

void is_pixel_pressed(data_t *data)
{
    if (data->new_pos.x == -1 && data->new_pos.y == -1)
        data->old_pos = (sfVector2f){-1, -1};
    if (data->mouse_pos.x < 196 || data->mouse_pos.x > 196 + 1196 ||
    data->mouse_pos.y < 123 || data->mouse_pos.y > 123 + 677)
        data->new_pos = (sfVector2f){-1, -1};
    if (sfMouse_isButtonPressed(sfMouseLeft) && data->spectrum == 0) {
        for (int i = 0; i < data->size; i++) {
            check_pixels(data, i);
        }
    }
    if (!sfMouse_isButtonPressed(sfMouseLeft))
        data->new_pos = (sfVector2f){-1, -1};
}

void display_menu(data_t *data)
{
    if (data->spectrum == 1)
        sfRenderWindow_drawSprite(data->window, data->buttons[5]->sprite,
        NULL);
    if (data->help == 1)
        sfRenderWindow_drawSprite(data->window, data->help_sprite, NULL);
    sfRectangleShape_setFillColor(data->color_rect, (sfColor){data->r,
    data->g, data->b, 255});
    sfRenderWindow_drawRectangleShape(data->window, data->color_rect, NULL);
}

void display_window(data_t *data)
{
    sfRenderWindow_clear(data->window, sfBlack);
    sfRenderWindow_drawSprite(data->window, data->bg_sprite, NULL);
    for (int i = 0; i < data->nb_buttons; i++) {
        if (i == 5 || data->buttons[i]->isactive == 0)
            continue;
        sfRenderWindow_drawSprite(data->window, data->buttons[i]->sprite,
        NULL);
    }
    is_pixel_pressed(data);
    display_pixels(data);
    display_menu(data);
    if (data->text)
        sfRenderWindow_drawText(data->window, data->text, NULL);
    if (data->current && data->isResizing == sfFalse)
        sfRenderWindow_drawText(data->window, data->current, NULL);
    sfRenderWindow_display(data->window);
}
