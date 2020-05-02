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
        store->nb_jump != 0 && object->pos.x >= 975 && \
        object->pos.x <= 1050 && store->index_maps == 1)
            store->scene = SHOP;
        check_input2(store, object);
        sfSprite_setTextureRect(object->sprite, object->rect);
    }
    if (object->type == MANA_BAR)
        analyse_mana_bar(store, object);
}

void check_for_sword(all_t *store)
{
    if (sfKeyboard_isKeyPressed(store->keys_code[4])) {
        store->time = sfClock_getElapsedTime(store->clock);
        store->sec = store->time.microseconds / 1000000.0;
        if (store->sec > 0.5) {
            store->attack = 1;
            sfClock_restart(store->clock);
            sfClock_restart(store->clock_attack);
        }
    }
}

void check_inventory(all_t *store, int status)
{
    if (status == 1) {
        if (store->scene == QUEST && sfKeyboard_isKeyPressed(sfKeyF)) {
            store->show_quest = false;
            store->quest_status = 1;
            store->scene = PLAYING;
            return;
        }
        if (store->event.key.code == store->keys_code[6] && \
        store->in_inventory == 0 && store->scene == PLAYING) {
            store->scene = INVENTORY;
            store->in_inventory += 1;
        }
        if (store->event.key.code == store->keys_code[6] && \
        store->in_inventory == 0 && store->scene == INVENTORY)
                store->scene = PLAYING;
        store->in_inventory = 0;
    }
}

void manage_key_pressed(all_t *store, int status)
{
    if (store->scene == MENU_KEYBOARD)
        for (int i = 0; i < sfKeyCount; i++)
            if (store->event.key.code == i)
                store->key_press[i] = 1;
    if (store->scene == PLAYING) {
        check_for_sword(store);
        for (game_object_t *ob = store->objects[PLAYING]; ob; ob = ob->next)
            check_input(store, ob);
        if (store->event.key.code == sfKeyP) {
            store->show_particules = true;
            store->scene = PAUSE;
        }
    }
    check_inventory(store, status);
}