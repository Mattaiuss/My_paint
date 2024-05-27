/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-mypaint-matteo.aufiero
** File description:
** init
*/

#include "my.h"
#include <math.h>

static void set_button(data_t *data, int i, char *but_names)
{
    data->buttons[i] = malloc(sizeof(button_t));
    data->buttons[i]->texture = malloc(sizeof(sfTexture *) * 3);
    data->buttons[i]->texture[0] =
    sfTexture_createFromFile(my_super_str_cat_int(but_names, 0, ".png"), NULL);
    data->buttons[i]->texture[1] =
    sfTexture_createFromFile(my_super_str_cat_int(but_names, 1, ".png"), NULL);
    data->buttons[i]->texture[2] =
    sfTexture_createFromFile(my_super_str_cat_int(but_names, 2, ".png"), NULL);
    data->buttons[i]->sprite = sfSprite_create();
    sfSprite_setTexture(data->buttons[i]->sprite, data->buttons[i]->texture[0],
    sfTrue);
    sfSprite_setScale(data->buttons[i]->sprite, (sfVector2f){2.7,
    2.7});
    sfSprite_setPosition(data->buttons[i]->sprite, (sfVector2f){25, 150 +
    i * 100});
    data->buttons[i]->isactive = 1;
}

int display_spectrum_status(data_t *data)
{
    data->spectrum = 1;
    data->buttons[11]->isactive = 1;
    data->buttons[12]->isactive = 1;
    return 0;
}

int get_hsl(data_t *data)
{
    float x_souris = data->mouse_pos.x - 100;
    hsl_t *hsl = malloc(sizeof(hsl_t));

    if (data->spectrum == 0)
        return 0;
    hsl->h = (x_souris - data->buttons[5]->pos.x) * 360 /
    (sfTexture_getSize(data->buttons[5]->texture[0]).x *
    sfSprite_getScale(data->buttons[5]->sprite).x);
    hsl->s = data->s;
    hsl->l = data->l;
    data->h = hsl->h;
    hsl_to_rgb(hsl, &data->r, &data->g, &data->b);
    return 0;
}

static void set_text(data_t *data)
{
    sfFont *font = sfFont_createFromFile("sprites/RS.ttf");

    data->input[0] = '\0';
    data->input[1] = '\0';
    data->input[2] = '\0';
    data->input[3] = '\0';
    data->isResizing = sfFalse;
    data->tsave = sfText_create();
    data->text = sfText_create();
    data->current = sfText_create();
    sfText_setFont(data->current, font);
    sfText_setCharacterSize(data->current, 23);
    sfText_setColor(data->current, sfColor_fromRGB(169, 169, 169));
    sfText_setString(data->current, "5");
}

static void set_buttons3_pos(data_t *data)
{
    data->pos_button = (sfVector2f){120, 260};
    sfSprite_setPosition(data->buttons[3]->sprite,
    (sfVector2f){data->pos_button.x - 15, data->pos_button.y - 10});
    sfText_setPosition(data->current, data->pos_button);
    sfRectangleShape_setSize(data->color_rect, (sfVector2f){100, 50});
    sfRectangleShape_setFillColor(data->color_rect, sfColor_fromRGB(0, 0, 0));
    sfRectangleShape_setPosition(data->color_rect, (sfVector2f){50, 720});
    sfRectangleShape_setOutlineColor(data->color_rect, sfBlack);
    sfRectangleShape_setOutlineThickness(data->color_rect, 2);
    sfSprite_setPosition(data->buttons[11]->sprite, (sfVector2f){400, 70});
    sfSprite_setScale(data->buttons[11]->sprite, (sfVector2f){0.350, 0.350});
    sfSprite_setPosition(data->buttons[12]->sprite, (sfVector2f){715, 70});
    sfSprite_setScale(data->buttons[12]->sprite, (sfVector2f){0.350, 0.350});
}

void set_callbacks(data_t *data)
{
    data->buttons[0]->callback = &pencil;
    data->buttons[1]->callback = &eraser;
    data->buttons[2]->callback = &erase_canvas;
    data->buttons[3]->callback = &size;
    data->buttons[4]->callback = &display_spectrum_status;
    data->buttons[5]->callback = &get_hsl;
    data->buttons[6]->callback = &open_file_menu;
    data->buttons[7]->callback = &save_image;
    data->buttons[8]->callback = &load_image;
    data->buttons[9]->callback = &exit_window;
    data->buttons[10]->callback = &display_help;
    data->buttons[11]->callback = &luminosity;
    data->buttons[12]->callback = &saturation;
}

static void set_drop_down_menu(data_t *data)
{
    sfSprite_setScale(data->buttons[4]->sprite, (sfVector2f){0.12, 0.12});
    sfSprite_setPosition(data->buttons[4]->sprite, (sfVector2f){100, 147});
    set_buttons3_pos(data);
    sfSprite_setPosition(data->buttons[5]->sprite, (sfVector2f){100, 70});
    sfSprite_setScale(data->buttons[5]->sprite, (sfVector2f){0.5, 0.5});
    sfSprite_setPosition(data->buttons[6]->sprite, (sfVector2f){0, 0});
    sfSprite_setScale(data->buttons[6]->sprite, (sfVector2f){4, 2.7});
    sfSprite_setPosition(data->buttons[7]->sprite, (sfVector2f){0, 50});
    data->buttons[7]->isactive = 0;
    sfSprite_setScale(data->buttons[7]->sprite, (sfVector2f){4, 2.7});
    sfSprite_setPosition(data->buttons[8]->sprite, (sfVector2f){0, 100});
    sfSprite_setScale(data->buttons[8]->sprite, (sfVector2f){4, 2.7});
    data->buttons[8]->isactive = 0;
    sfSprite_setPosition(data->buttons[9]->sprite, (sfVector2f){160, 0});
    sfSprite_setScale(data->buttons[9]->sprite, (sfVector2f){4, 2.7});
    sfSprite_setPosition(data->buttons[10]->sprite, (sfVector2f){80, 0});
    sfSprite_setScale(data->buttons[10]->sprite, (sfVector2f){4, 2.7});
    data->buttons[11]->isactive = 0;
    data->buttons[12]->isactive = 0;
}

static void set_buttons(data_t *data)
{
    char *but_names[13] = {"sprites/pen", "sprites/eraser", "sprites/bin",
    "sprites/resize", "sprites/color", "sprites/spectrum", "sprites/file",
    "sprites/save", "sprites/load", "sprites/exit", "sprites/help",
    "sprites/lumino", "sprites/saturation"};

    data->nb_buttons = 13;
    data->buttons = malloc(sizeof(button_t *) * data->nb_buttons);
    for (int i = 0; i < data->nb_buttons; i++) {
        set_button(data, i, but_names[i]);
        data->buttons[i]->status = 0;
    }
    data->color_rect = sfRectangleShape_create();
    data->buttons[11]->pos = (sfVector2f){400, 70};
    data->buttons[12]->pos = (sfVector2f){715, 70};
    set_callbacks(data);
    set_text(data);
    set_drop_down_menu(data);
    data->h = 0;
    data->s = 1;
    data->l = 0.5;
}

static void set_rgb(data_t *data)
{
    sfTexture *tectur = sfTexture_createFromFile("sprites/spectrum0.png",
    NULL);

    data->r = 0;
    data->g = 0;
    data->b = 0;
    data->a = 255;
    data->size = 5;
    data->spectrum_sprite = sfSprite_create();
    sfSprite_setTexture(data->spectrum_sprite, tectur, sfTrue);
    sfSprite_setScale(data->spectrum_sprite, (sfVector2f){0.5, 0.5});
}

data_t *init_data(void)
{
    data_t *data = malloc(sizeof(data_t));

    data->window = sfRenderWindow_create((sfVideoMode){1600, 900, 32},
    "my_paint", sfClose | sfResize, NULL);
    data->bg_sprite = sfSprite_create();
    data->bg_texture = sfTexture_createFromFile("sprites/ui.png", NULL);
    sfSprite_setTexture(data->bg_sprite, data->bg_texture, sfTrue);
    sfSprite_setScale(data->bg_sprite, (sfVector2f){0.83333, 0.83333});
    set_buttons(data);
    set_pixels(data);
    set_rgb(data);
    data->help = 0;
    data->help_sprite = sfSprite_create();
    data->help_texture = sfTexture_createFromFile("sprites/help.png", NULL);
    sfSprite_setTexture(data->help_sprite, data->help_texture, sfTrue);
    sfSprite_setScale(data->help_sprite, (sfVector2f){1.1, 1.1});
    sfSprite_setPosition(data->help_sprite, (sfVector2f){250, 20});
    return data;
}
