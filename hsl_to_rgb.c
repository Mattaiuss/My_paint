/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-mypaint-matteo.aufiero
** File description:
** HSLtoRGB
*/

#include "my.h"
#include <math.h>

int luminosity(data_t *data)
{
    float x_souris = data->mouse_pos.x;
    hsl_t *hsl = malloc(sizeof(hsl_t));

    if (data->spectrum == 0)
        return 0;
    hsl->l = (x_souris - data->buttons[11]->pos.x) * 1 /
    (sfTexture_getSize(data->buttons[11]->texture[0]).x *
    sfSprite_getScale(data->buttons[11]->sprite).x);
    hsl->s = data->s;
    hsl->h = data->h;
    data->l = hsl->l;
    hsl_to_rgb(hsl, &data->r, &data->g, &data->b);
    return 0;
}

int saturation(data_t *data)
{
    float x_souris = data->mouse_pos.x;
    hsl_t *hsl = malloc(sizeof(hsl_t));

    if (data->spectrum == 0)
        return 0;
    hsl->s = (x_souris - data->buttons[12]->pos.x) * 1 /
    (sfTexture_getSize(data->buttons[12]->texture[0]).x *
    sfSprite_getScale(data->buttons[12]->sprite).x);
    hsl->l = data->l;
    hsl->h = data->h;
    data->s = hsl->s;
    hsl_to_rgb(hsl, &data->r, &data->g, &data->b);
    return 0;
}

static void quadruple_if(hsl_t *hsl)
{
    if (hsl->h >= 0 && hsl->h < 60) {
        hsl->rp = hsl->c;
        hsl->gp = hsl->x;
        hsl->bp = 0;
    }
    if (hsl->h >= 60 && hsl->h < 120) {
        hsl->rp = hsl->x;
        hsl->gp = hsl->c;
        hsl->bp = 0;
    }
    if (hsl->h >= 120 && hsl->h < 180) {
        hsl->rp = 0;
        hsl->gp = hsl->c;
        hsl->bp = hsl->x;
    }
    if (hsl->h >= 180 && hsl->h < 240) {
        hsl->rp = 0;
        hsl->gp = hsl->x;
        hsl->bp = hsl->c;
    }
}

void hsl_to_rgb(hsl_t *hsl, int *r, int *g, int *b)
{
    hsl->c = (1 - fabs(2 * hsl->l - 1)) * hsl->s;
    hsl->x = hsl->c * (1 - fabs(fmod(hsl->h / 60.0, 2) - 1));
    hsl->m = hsl->l - hsl->c / 2.0;
    quadruple_if(hsl);
    if (hsl->h >= 240 && hsl->h < 300) {
        hsl->rp = hsl->x;
        hsl->gp = 0;
        hsl->bp = hsl->c;
    }
    if (hsl->h >= 300 && hsl->h < 360) {
        hsl->rp = hsl->c;
        hsl->gp = 0;
        hsl->bp = hsl->x;
    }
    *r = (hsl->rp + hsl->m) * 255;
    *g = (hsl->gp + hsl->m) * 255;
    *b = (hsl->bp + hsl->m) * 255;
}
