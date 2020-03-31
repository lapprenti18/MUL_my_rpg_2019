/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** analyse_mana.c
*/

#include "../include/my.h"

all_t *analyse_mana_bar(all_t *store)
{
    game_object_t *mana = store->objects[PLAYING];

    for (; mana->type != MANA_BAR; mana = mana->next);
    if (store->event.type == sfEvtKeyPressed) {
        analyse_mana_bar_3(store);
    }
    if (mana->rect.left >= 687 && store->mana_level == 0) {
        mana->rect.left = 0;
        mana->rect.top = 146;
    }
    return (analyse_mana_bar_2(store, mana));
}

all_t *analyse_mana_bar_2(all_t *store, game_object_t *mana)
{
    if (store->mana_level == 1)
        mana->rect.top = 292;
    if (store->mana_level == 2)
        mana->rect.top = 438;
    if (store->mana_level == 3)
        mana->rect.top = 584;
    if (store->mana_level == 4)
        mana->rect.top = 730;
    if (store->mana_level == 5)
        mana->rect.top = 876;
    if (store->mana_level == 6) 
        mana->rect.top = 1022;
    if (store->mana_level == 7) 
        mana->rect.top = 1168;
    if (store->mana_level == 8)
        mana->rect.top = 1314;
    sfSprite_setTextureRect(mana->sprite, mana->rect);
    return (store);
}

void analyse_mana_bar_3(all_t *store)
{
    if (sfKeyboard_isKeyPressed(sfKeyL)) {
        store->mana_level += 1;
        if (store->mana_level >= 8)
            store->mana_level = 8;
    }
    if (sfKeyboard_isKeyPressed(sfKeyK)) {
        store->mana_level -= 1;
        if (store->mana_level <= 0)
            store->mana_level = 0;
    }
}