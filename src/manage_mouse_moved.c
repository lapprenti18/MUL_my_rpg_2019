/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** manage_mouse_moved.c
*/

#include "../include/my.h"

void manage_mouse_moved(all_t *store)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(store->window);

    for (game_object_t *copy = store->objects[store->scene]; \
    copy; copy = copy->next) {
        if (mouse.x >= copy->pos.x - (copy->length / 2) \
        && mouse.x <= copy->pos.x + (copy->length / 2) \
        && mouse.y >= copy->pos.y - (copy->height / 2) \
        && mouse.y <= copy->pos.y + (copy->height / 2) \
        && copy->move) {
            copy->rect.left = copy->length;
        } else
            copy->rect.left = 0;
        sfSprite_setTextureRect(copy->sprite, copy->rect);
    }
}