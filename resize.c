/*
** EPITECH PROJECT, 2024
** resize button
** File description:
** mypaint
*/

#include "my.h"

static int my_atoi(char *str)
{
    int res = 0;
    int i = 0;

    while (str[i] != '\0') {
        res = res * 10 + str[i] - '0';
        i++;
    }
    return res;
}

static void convert_and_set_size(data_t *data, char *sizeStr)
{
    int size = data->size;
    int i = 0;
    char temp = 0;

    while (size > 0) {
        sizeStr[i] = '0' + (size % 10);
        size /= 10;
        i++;
    }
    sizeStr[i] = '\0';
    for (int j = 0; j < i / 2; j++) {
        temp = sizeStr[j];
        sizeStr[j] = sizeStr[i - j - 1];
        sizeStr[i - j - 1] = temp;
    }
    sfText_setString(data->current, sizeStr);
}

static void handle_text_input(data_t *data)
{
    size_t len = my_strlen(data->input);

    if (len < sizeof(data->input) - 1) {
        data->input[len] = '0' + (data->event.text.unicode - '0');
        data->input[len + 1] = '\0';
        sfText_setString(data->text, data->input);
    }
}

static void handle_size_input(data_t *data, int status)
{
    char sizeStr[10];

    if (my_atoi(data->input) > 0 && my_atoi(data->input) <= 50 && status == 1)
        data->size = my_atoi(data->input);
    if (status == 1) {
        convert_and_set_size(data, sizeStr);
        data->isResizing = sfFalse;
    } else {
        sfText_setString(data->tsave, data->input);
        data->isSaved = sfTrue;
    }
}

void handleresizing(data_t *data)
{
    if (!data->text) {
        data->text = sfText_create();
        sfText_setFont(data->text, sfFont_createFromFile("sprites/RS.ttf"));
        sfText_setCharacterSize(data->text, 23);
        sfText_setPosition(data->text, data->pos_button);
        sfText_setColor(data->text, sfColor_fromRGB(0, 0, 0));
    }
    if (data->event.type == sfEvtTextEntered) {
        if (IS_NUM(data->event.text.unicode) && my_strlen(data->input) < 2)
            handle_text_input(data);
        if (data->event.text.unicode == '\r') {
            handle_size_input(data, 1);
            sfText_destroy(data->text);
            data->text = NULL;
            memset(data->input, 0, sizeof(data->input));
        }
    }
}

void destroytext(data_t *data)
{
    if (data->text && data->isResizing == sfFalse) {
        sfText_destroy(data->text);
        data->text = NULL;
        memset(data->input, 0, sizeof(data->input));
    }
}
