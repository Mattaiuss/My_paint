/*
** EPITECH PROJECT, 2024
** B-MUL-200-MPL-2-1-mypaint-matteo.aufiero
** File description:
** save_image
*/

#include "my.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int open_file_menu(data_t *data)
{
    data->buttons[7]->isactive = 1;
    data->buttons[8]->isactive = 1;
    return 0;
}

int save_image(data_t *data)
{
    sfImage *image = sfTexture_copyToImage(data->canvas_texture);

    if (data->buttons[7]->isactive == 0) {
        return 0;
    }
    sfImage_saveToFile(image, "save.png");
    return 0;
}

int load_image(data_t *data)
{
    sfImage *image = sfImage_createFromFile("save.png");

    if (data->buttons[8]->isactive == 0) {
        return 0;
    }
    data->pix_tab = malloc(sizeof(sfUint8) * 1920 * 1080 * 4);
    data->pix_tab = (sfUint8 *)sfImage_getPixelsPtr(image);
    return 0;
}
