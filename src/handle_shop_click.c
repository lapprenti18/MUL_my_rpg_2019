/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** handle_shop_click.c
*/

#include "../include/my.h"

void handle_shop_click(all_t *store, game_object_t *object)
{
    if (object->type == BACK)
        store->scene = PLAYING;
}