/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** manage_key_pressed.c
*/

#include "../include/my.h"

void check_input(all_t *store, game_object_t *object)
{
    if (object->type == KNIGHT) {
        if (sfKeyboard_isKeyPressed(store->keys_code[2]))
            store->velocity.x = -3;
        if (sfKeyboard_isKeyPressed(store->keys_code[3]))
            store->velocity.x = 3;
        if (sfKeyboard_isKeyPressed(store->keys_code[5]) && \
        store->nb_jump != 0) {
            store->velocity.y = -10;
            store->nb_jump = 0;
        }
    }
}

void change_key(all_t *store)
{
    for (int i = 0; i < sfKeyCount; i++)
        if (store->event.key.code == i)
            store->key_press[i] = 1;
}

void manage_key_pressed(all_t *store)
{
    if (store->scene == MENU_KEYBOARD) {
        change_key(store);
        return;
    }
    if (store->scene == PLAYING) {
        for (game_object_t *ob = store->objects[PLAYING]; ob; ob = ob->next)
            check_input(store, ob);
        if (store->event.key.code == sfKeyP) {
            store->show_particules = true;
            store->scene = PAUSE;
        }
    }
}