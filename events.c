/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-mypaint-matteo.aufiero
** File description:
** events
*/

#include "my.h"

static void manage_keys(data_t *data)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(data->window);
    if (data->event.key.code == sfKeyR)
        erase_canvas(data);
    if (data->event.key.code == sfKeyP)
        pencil(data);
    if (data->event.key.code == sfKeyE)
        eraser(data);
    if (data->event.key.code == sfKeyS && data->event.key.control)
        save_image(data);
}

void manage_resize(data_t *data)
{
    if (data->event.type == sfEvtResized) {
        data->mouse_pos = (sfVector2f){
            sfMouse_getPositionRenderWindow(data->window).x * (1677.f /
            sfRenderWindow_getSize(data->window).x),
            sfMouse_getPositionRenderWindow(data->window).y * (900.f /
            sfRenderWindow_getSize(data->window).y)
        };
    }
    data->mouse_pos = (sfVector2f){
        sfMouse_getPositionRenderWindow(data->window).x * (1600.f /
        sfRenderWindow_getSize(data->window).x),
        sfMouse_getPositionRenderWindow(data->window).y * (900.f /
        sfRenderWindow_getSize(data->window).y)
    };
}

static void check_mouseclick(data_t *data)
{
    if (data->event.mouseButton.button == sfMouseLeft) {
        if (!is_clicked(data->buttons[5], data) &&
        !is_clicked(data->buttons[11], data) &&
        !is_clicked(data->buttons[12], data)){
            data->spectrum = 0;
            data->buttons[11]->isactive = 0;
            data->buttons[12]->isactive = 0;
        }
        if (!is_clicked(data->buttons[3], data)) {
            data->isResizing = sfFalse;
        }
        if (!is_clicked(data->buttons[6], data) &&
        !is_clicked(data->buttons[7], data) &&
        !is_clicked(data->buttons[8], data)) {
            data->buttons[7]->isactive = 0;
            data->buttons[8]->isactive = 0;
        }
        if (!is_clicked(data->buttons[10], data))
            data->help = 0;
    }
}

void manage_events(data_t *data)
{
    while (sfRenderWindow_pollEvent(data->window, &data->event)) {
        if (data->event.type == sfEvtClosed)
            sfRenderWindow_close(data->window);
        manage_resize(data);
        if (data->event.type == sfEvtKeyPressed)
            manage_keys(data);
        if (data->event.type == sfEvtMouseButtonPressed)
            check_mouseclick(data);
        if (data->isResizing)
            handleresizing(data);
        else
            destroytext(data);
    }
}
