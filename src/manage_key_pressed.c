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
}

void check_for_sword(all_t *store)
{
    game_object_t *object = store->objects[PLAYING];
    game_object_t *copy = store->objects[PLAYING];

    for (; object->type != KNIGHT ; object = object->next);
    for (; copy->type != SWORD_EFFECT ; copy = copy->next);
    if (sfKeyboard_isKeyPressed(store->keys_code[4])) {
        store->show_sword = true;
        if (object->rect.top == 0 || object->rect.top == 762) {
            copy->rect.left = 0;
            sfSprite_setTextureRect(copy->sprite, copy->rect);
            copy->change_pos(copy, (sfVector2f){object->pos.x + 50, object->pos.y});
            return;
        }
        if (object->rect.top == 127 || object->rect.top == 889) {
            copy->rect.left = 179;
            sfSprite_setTextureRect(copy->sprite, copy->rect);
            copy->change_pos(copy, (sfVector2f){object->pos.x - 90, object->pos.y});
            return;
        }
    }
}

void check_inventory(all_t *store, int status)
{
    if (status == 1) {
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
        if (sfKeyboard_isKeyPressed(sfKeyA))
            store->nb_golds += 1;
        if (sfKeyboard_isKeyPressed(sfKeyE))
            store->nb_golds -= 1;
    }
    if (store->scene == QUEST && store->event.key.code == sfKeyF \
    && store->show_quest == false) {
        store->show_quest = true;
        store->quest_status = 1;
        store->scene = PLAYING;
    }
    check_inventory(store, status);
}