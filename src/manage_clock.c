/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** manage_clock.c
*/

#include "../include/my.h"

void manage_clock(game_object_t *objects)
{
    if (objects->type == MANA_BAR && objects->rect.left != 687) {
        objects->time = sfClock_getElapsedTime(objects->clock);
        objects->seconds = objects->time.microseconds / 1000000.0;
        if (objects->seconds > 0.15) {
            objects->move_rect(objects, 229, 687);
            sfClock_restart(objects->clock);
        }
    }
}

void manage_all_clock(all_t *store)
{
    for (game_object_t *copy = store->objects[store->scene]; copy; \
    copy = copy->next)
        copy->manage_clock(copy);
}