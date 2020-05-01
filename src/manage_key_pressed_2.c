/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** manage_key_pressed_2.c
*/

#include "../include/my.h"

void check_input2(all_t *store, game_object_t *object)
{
    if (sfKeyboard_isKeyPressed(store->keys_code[0]) && \
        store->nb_jump != 0 && object->pos.x >= 140 && \
        object->pos.x <= 280 && store->index_maps == 1) {
            store->scene = QUEST;
            printf("yo\n");
            return;
        }
    if (sfKeyboard_isKeyPressed(store->keys_code[2]) && store->scene == PLAYING) {
        store->velocity.x = -3;
        object->rect.top = change_rect(object, 2);
    }
    if (sfKeyboard_isKeyPressed(store->keys_code[3]) && store->scene == PLAYING) {
        store->velocity.x = 3;
        object->rect.top = change_rect(object, 1);
    }
    if (sfKeyboard_isKeyPressed(store->keys_code[5]) && \
    store->nb_jump != 0 && store->scene == PLAYING) {
        store->velocity.y = -10;
        store->nb_jump = 0;
        object->rect.top = (object->rect.top == 0) ? 762 : 889;
    }
}