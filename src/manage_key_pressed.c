/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** manage_key_pressed.c
*/

#include "../include/my.h"

int change_rect(game_object_t *object, int right)
{
    if (right == 1) {
        if (object->rect.top == 0 || object->rect.top == 127)
            return (0);
        if (object->rect.top == 889)
            return (762);
    } else {
        if (object->rect.top == 0 || object->rect.top == 127)
            return (127);
        if (object->rect.top == 762)
            return (889);
    }
    return (object->rect.top);
}

void check_input(all_t *store, game_object_t *object)
{
    if (object->type == KNIGHT) {
        if (sfKeyboard_isKeyPressed(store->keys_code[0]) && \
        store->nb_jump != 0 && object->pos.x >= 975 && object->pos.x <= 1050)
            store->scene = SHOP;
        if (sfKeyboard_isKeyPressed(store->keys_code[2])) {
            store->velocity.x = -3;
            object->rect.top = change_rect(object, 2);
        }
        if (sfKeyboard_isKeyPressed(store->keys_code[3])) {
            store->velocity.x = 3;
            object->rect.top = change_rect(object, 1);
        }
        if (sfKeyboard_isKeyPressed(store->keys_code[5]) && \
        store->nb_jump != 0) {
            store->velocity.y = -10;
            store->nb_jump = 0;
            object->rect.top = (object->rect.top == 0) ? 762 : 889;
        }
        sfSprite_setTextureRect(object->sprite, object->rect);
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
        if (sfKeyboard_isKeyPressed(sfKeyA))
            store->nb_golds += 1;
        if (sfKeyboard_isKeyPressed(sfKeyE))
            store->nb_golds -= 1;
    }
    if (sfKeyboard_isKeyPressed(store->keys_code[6]))
        if (store->in_inventory == false && store->scene == PLAYING) {
            store->scene = INVENTORY;
            store->in_inventory = true;
        }
    if (sfKeyboard_isKeyPressed(store->keys_code[6]))
        if (store->in_inventory == false && store->scene == INVENTORY)
            store->scene = PLAYING;
    store->in_inventory = false;
}