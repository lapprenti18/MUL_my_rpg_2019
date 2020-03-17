/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** manage_mouse_moved.c
*/

#include "../include/my.h"

void manage_moved_on_menu(all_t *store)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(store->window);

    (void)mouse;
}

void manage_mouse_moved(all_t *store)
{
    if (store->scene == MENU)
        manage_moved_on_menu(store);
}