/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** update_structures.c
*/

#include "../include/my.h"

void update(all_t *store, game_object_t *object, sfVector2i mouse)
{
    (void)store;
    if (object->type == CURSEUR)
        object->change_pos(object, (sfVector2f){mouse.x, mouse.y});
}