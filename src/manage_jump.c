/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** manage_jump.c
*/

#include "../include/my.h"

void update_jump(all_t *store)
{
    game_object_t *copy = store->objects[PLAYING];

    for (; copy->type != KNIGHT; copy = copy->next);
    if (store->velocity.x > 2)
        store->velocity.x = 2;
    if (store->velocity.x < -2)
        store->velocity.x = -2;
    copy->pos.x -= store->velocity.x;
    copy->pos.y += store->velocity.y;
    if (copy->pos.y < 800) {
        store->velocity.y += store->gravity;
    } else {
        store->velocity.y = 0;
        copy->pos.y = 800;
        store->nb_jump = 1;
    }
    sfSprite_setPosition(copy->sprite, copy->pos);
}