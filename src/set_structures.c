/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** set_structures.c
*/

#include "../include/my.h"

sfRenderWindow *create_window(int fps)
{
    sfRenderWindow* window;
    sfVideoMode mode = {WIDTH, HEIGHT, 32};

    window = sfRenderWindow_create(mode, "RPG", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, fps);
    return (window);
}

void set_structures(all_t *store)
{
    store->scene = MENU;
    store->window = create_window(60);
    store->objects = create_objects();
}