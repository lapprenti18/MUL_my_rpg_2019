/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** handle_shop_click.c
*/

#include "../include/my.h"

charm_t tab_charm[5] =
{
    {0, 100},
    {1, 200},
    {2, 150},
    {3, 250},
    {4, 500}
};

void handle_shop_click(all_t *store, game_object_t *object)
{
    int index = object->type - LIFE_CHARM;

    if (object->type == BACK)
        store->scene = PLAYING;
    if (object->type >= LIFE_CHARM) {
        if (store->nb_golds >= tab_charm[index].price) {
            store->buys[index] = true;
            store->nb_golds -= tab_charm[index].price;
        }
    }
}