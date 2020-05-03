/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** setup_functions.c
*/

#include "../include/my.h"

void check_for_heal(all_t *store, int status)
{
    if (sfKeyboard_isKeyPressed(sfKeyH) && store->knight_hp != 5 && \
    store->mana_level > 2 && store->buys[0] && status == 1) {
        store->knight_hp += 1;
        store->mana_level -= 2;
        for (game_object_t *ob = store->objects[PLAYING]; ob; ob = ob->next)
            if (ob->type == HEALTH && !ob->animated && \
            ob->next->type == HEALTH && ob->next->animated) {
                ob->animated = true;
                ob->rect.left = 0;
                sfSprite_setTextureRect(ob->sprite, ob->rect);
                return;
            }
    }
}

void move_rect(game_object_t *object, int offset, int size_max)
{
    object->rect.left += offset;
    if (object->rect.left > size_max)
        object->rect.left = 0;
    if (object->rect.left < 0)
        object->rect.left = size_max;
    sfSprite_setTextureRect(object->sprite, object->rect);
}

void change_pos(game_object_t *object, sfVector2f new_pos)
{
    object->pos.x = new_pos.x;
    object->pos.y = new_pos.y;
    sfSprite_setPosition(object->sprite, object->pos);
}