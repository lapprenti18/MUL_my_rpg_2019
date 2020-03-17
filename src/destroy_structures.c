/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** destroy_structures.c
*/

#include "../include/my.h"

void destroy_structures(all_t *store)
{
    for (int index = 0; store->objects[index]; index += 1) {
        for (game_object_t *copy = store->objects[index]; copy; \
        copy = copy->next) {
            sfSprite_destroy(copy->sprite);
            sfTexture_destroy(copy->texture);
            sfClock_destroy(copy->clock);
        }
    }
    sfRenderWindow_destroy(store->window);
}