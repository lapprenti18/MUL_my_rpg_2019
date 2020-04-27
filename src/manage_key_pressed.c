/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** manage_key_pressed.c
*/

#include "../include/my.h"

void check_left(all_t *store, game_object_t *object)
{
    if (object->type == KNIGHT) {
        store->velocity.x = -15;
    }
}

void check_jump(all_t *store, game_object_t *object)
{
    if (object->type == KNIGHT) {
        store->velocity.y = -0.5;
    }
}

void check_right(all_t *store, game_object_t *object)
{
    if (object->type == KNIGHT) {
        store->velocity.x = 15;
    }
}

void manage_key_pressed(all_t *store)
{
    if (store->scene != PLAYING)
        return;
    if (store->event.key.code == store->keys_code[3]) {
        for (game_object_t *ob = store->objects[PLAYING]; ob; ob = ob->next)
            check_right(store, ob);
    }
    if (store->event.key.code == store->keys_code[2]) {
        for (game_object_t *ob = store->objects[PLAYING]; ob; ob = ob->next)
            check_left(store, ob);
    }
    if (store->event.key.code == store->keys_code[5]) {
        for (game_object_t *ob = store->objects[PLAYING]; ob; ob = ob->next)
            check_jump(store, ob);
    }
}