/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** handle_inventory_click.c
*/

#include "../include/my.h"

void desable_effect(all_t *store, game_object_t *object)
{
    object->change_pos(object, (sfVector2f){object->pos.x , 580});
    if (object->type - LIFE_CHARM == 1)
        store->knight_dgs = 1;
    if (object->type - LIFE_CHARM == 2)
        store->more_mana = 1;
    if (object->type - LIFE_CHARM == 3)
        store->more_golds = 1;
}

void update_effect(all_t *store, game_object_t *object)
{
    object->change_pos(object, (sfVector2f){object->pos.x , 300});
    if (object->type - LIFE_CHARM == 1)
        store->knight_dgs = 2;
    if (object->type - LIFE_CHARM == 2)
        store->more_mana = 1.5;
    if (object->type - LIFE_CHARM == 3)
        store->more_golds = 1.5;
}

void handle_inventory_click(all_t *store, game_object_t *object, \
sfVector2i mouse)
{
    (void)mouse;
    if (object->type >= LIFE_CHARM && object->type <= HEART_CHARM && \
    store->buys[object->type - LIFE_CHARM] == true) {
        if (object->pos.y == 580)
            update_effect(store, object);
        else
            desable_effect(store, object);
    }
}