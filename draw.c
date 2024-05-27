/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-mypaint-matteo.aufiero
** File description:
** draw
*/

#include "my.h"

temp_t set_temp(data_t *data)
{
    temp_t temp;

    temp.x1 = data->old_pos.x;
    temp.x2 = data->new_pos.x;
    temp.y1 = data->old_pos.y;
    temp.y2 = data->new_pos.y;
    temp.dx = abs(temp.x2 - temp.x1);
    temp.dy = abs(temp.y2 - temp.y1);
    temp.sx = temp.x1 < temp.x2 ? 1 : -1;
    temp.sy = temp.y1 < temp.y2 ? 1 : -1;
    temp.err = (temp.dx > temp.dy ? temp.dx : -temp.dy) / 2;
    return temp;
}

int loop2(temp_t temp, data_t *data, int i)
{
    int x;
    int y;
    int index;

    for (int j = 0; j < data->size * 2; j++) {
        x = temp.x1 + i;
        y = temp.y1 + j;
        if (x < 0 || x > 1196 || y < 0 || y > 677)
            return 1;
        index = (x + y * 1196) * 4;
        data->pix_tab[index] = data->r;
        data->pix_tab[index + 1] = data->g;
        data->pix_tab[index + 2] = data->b;
        data->pix_tab[index + 3] = data->a;
    }
    return 0;
}

int loop(temp_t temp, data_t *data)
{
    for (int i = 0; i < data->size * 2; i++) {
        if (loop2(temp, data, i) == 1)
            return 1;
    }
    return 0;
}

int fill(data_t *data)
{
    (void)data;
    return 0;
}

void fill_between(data_t *data)
{
    temp_t temp = set_temp(data);

    while (1) {
        if (loop(temp, data) == 1)
            return;
        if ((temp.x1 == temp.x2 && temp.y1 == temp.y2) || temp.x1 < 0 ||
        temp.x1 > 1196 || temp.y1 < 0 || temp.y1 > 677)
            return;
        temp.e2 = temp.err;
        if (temp.e2 > -temp.dx) {
            temp.err -= temp.dy;
            temp.x1 += temp.sx;
        }
        if (temp.e2 < temp.dy) {
            temp.err += temp.dx;
            temp.y1 += temp.sy;
        }
    }
}
