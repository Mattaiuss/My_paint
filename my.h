/*
** EPITECH PROJECT, 2024
** bspaint
** File description:
** my
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define IS_NUM(x) (x >= '0' && x <= '9')
#define PNG(x) (x[i + 1] == 'p' && x[i + 2] == 'n' && x[i + 3] == 'g')
#define JPG(x) (x[i + 1] == 'j' && x[i + 2] == 'p' && x[i + 3] == 'g')

typedef struct data_s data_t;

typedef struct hsl_s {
    float h;
    float s;
    float l;
    float c;
    float x;
    float m;
    float rp;
    float gp;
    float bp;
} hsl_t;

typedef struct temp_s {
    int x1;
    int x2;
    int y1;
    int y2;
    int dx;
    int dy;
    int sx;
    int sy;
    int err;
    int e2;
} temp_t;

typedef struct save_s {
    int id;
    sfUint8 *pix_tab;
    struct save_s *next;
    struct save_s *prev;
} save_t;

typedef struct button_s {
    sfTexture **texture;
    sfSprite *sprite;
    int status;
    int isactive;

    sfVector2f pos;

    int (*callback)(data_t *data);
} button_t;

typedef struct data_s {
    sfRenderWindow *window;
    sfEvent event;
    sfBool isResizing;
    sfText *text;
    sfText *current;
    sfText *tsave;
    sfBool isSaved;
    char input[4];
    sfVector2f pos_button;
    sfVector2f mouse_pos;

    sfTexture *bg_texture;
    sfSprite *bg_sprite;

    int help;
    sfTexture *help_texture;
    sfSprite *help_sprite;

    int nb_buttons;
    button_t **buttons;

    int nb_menus;
    button_t **menus;

    sfUint8 *pix_tab;
    save_t *save;
    sfSprite *canvas;
    sfTexture *canvas_texture;
    int r;
    int g;
    int b;
    int a;
    float h;
    float s;
    float l;
    int size;
    int tool;
    int spectrum;
    sfSprite *spectrum_sprite;
    sfRectangleShape *color_rect;

    sfVector2f old_pos;
    sfVector2f new_pos;
} data_t;

int my_strlen(char *str);
char *my_strdup(char *src);
char *my_strcat(char *dest, char *src);
char *my_super_str_cat_int(char *string, int value, char *ext);
char *my_strcpy(char *dest, char *src);
char *my_strncpy(char *dest, char *src, int n);

void manage_events(data_t *data);
data_t *init_data(void);
void is_pixel_pressed(data_t *data);
void set_pixels(data_t *data);

void display_window(data_t *data);
const char *window_ask(data_t *data, int choice);;
int fill(data_t *data);
void fill_between(data_t *data);

int erase_canvas(data_t *data);
int pencil(data_t *data);
int size(data_t *data);
int eraser(data_t *data);
int save_image(data_t *data);
int open_file_menu(data_t *data);
int load_image(data_t *data);
int exit_window(data_t *data);
int display_help(data_t *data);
int saturation(data_t *data);
int luminosity(data_t *data);

void check_buttons(data_t *data);
sfBool is_clicked(button_t *button, data_t *data);

void destroytext(data_t *data);
void handleresizing(data_t *data);
void handleInput(data_t *data, int check);

void hsl_to_rgb(hsl_t *hsl, int *r, int *g, int *b);

int destroy_all(data_t *data);
