/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** handle_inventory_click.c
*/

#include "../include/my.h"

void handle_inventory_click(all_t *store, game_object_t *object, \
sfVector2i mouse)
{
    (void)mouse;
    if (object->type >= LIFE_CHARM && object->type <= HEART_CHARM && \
    store->buys[object->type - LIFE_CHARM] == true) {
        if (object->pos.y == 580)
            object->change_pos(object, (sfVector2f){object->pos.x , 300});
        else
            object->change_pos(object, (sfVector2f){object->pos.x , 580});
    }
}