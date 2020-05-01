/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** manage_jump.c
*/

#include "../include/my.h"

void respawn_left(all_t *store, game_object_t *object)
{
    if (store->index_maps == 0)
        object->change_pos(object, (sfVector2f){200, 850});
    if (store->index_maps == 1)
        object->change_pos(object, (sfVector2f){200, 850});
    if (store->index_maps == 2)
        object->change_pos(object, (sfVector2f){200, 850});
    if (store->index_maps == 3)
        object->change_pos(object, (sfVector2f){200, 850});
    if (store->index_maps == 4)
        object->change_pos(object, (sfVector2f){960, 150});
    if (store->index_maps == 5)
        object->change_pos(object, (sfVector2f){100, 700});
}

void respawn_right(all_t *store, game_object_t *object)
{
    if (store->index_maps == 0)
        object->change_pos(object, (sfVector2f){1800, 850});
    if (store->index_maps == 1)
        object->change_pos(object, (sfVector2f){1800, 850});
    if (store->index_maps == 2)
        object->change_pos(object, (sfVector2f){1800, 850});
    if (store->index_maps == 3)
        object->change_pos(object, (sfVector2f){1800, 850});
    if (store->index_maps == 4)
        object->change_pos(object, (sfVector2f){1800, 700});
    if (store->index_maps == 5)
        object->change_pos(object, (sfVector2f){100, 700});
}

void respawn(all_t *store, game_object_t *object)
{
    if (store->spawn == 1)
        respawn_left(store, object);
    if (store->spawn == 2)
        respawn_right(store, object);
}