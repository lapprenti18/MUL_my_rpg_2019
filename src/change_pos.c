/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** manage_jump.c
*/

#include "../include/my.h"

void change_position(all_t *store, game_object_t *object)
{
    if (store->index_maps == 4)
        object->change_pos(object, (sfVector2f){object->pos.x, 11});
    else
        object->change_pos(object, (sfVector2f){50, object->pos.y});
}