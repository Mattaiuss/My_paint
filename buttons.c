/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-mypaint-matteo.aufiero
** File description:
** buttons
*/

#include "my.h"

static sfBool is_hover(button_t *button, data_t *data)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(button->sprite);

    if (sfFloatRect_contains(&rect, data->mouse_pos.x, data->mouse_pos.y))
        return sfTrue;
    return sfFalse;
}

sfBool is_clicked(button_t *button, data_t *data)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(button->sprite);

    if (sfFloatRect_contains(&rect, data->mouse_pos.x, data->mouse_pos.y) &&
    sfMouse_isButtonPressed(sfMouseLeft))
        return sfTrue;
    return sfFalse;
}

static void check_ishoverclick(data_t *data)
{
    for (int i = 0; i < data->nb_buttons; i++) {
        data->buttons[i]->status = 0;
    }
    for (int i = 0; i < data->nb_buttons; i ++) {
        if (is_hover(data->buttons[i], data))
            data->buttons[i]->status = 1;
        if (is_clicked(data->buttons[i], data) &&
        data->buttons[i]->status != 2) {
            data->buttons[i]->status = 2;
            data->buttons[i]->callback(data);
        }
    }
}

void check_buttons(data_t *data)
{
    check_ishoverclick(data);
    for (int i = 0; i < data->nb_buttons; i++) {
        if (data->buttons[i]->status == 1)
            sfSprite_setTexture(data->buttons[i]->sprite,
            data->buttons[i]->texture[1], sfTrue);
        if (data->buttons[i]->status == 2)
            sfSprite_setTexture(data->buttons[i]->sprite,
            data->buttons[i]->texture[2], sfTrue);
        if (data->buttons[i]->status == 0)
            sfSprite_setTexture(data->buttons[i]->sprite,
            data->buttons[i]->texture[0], sfTrue);
    }
}
