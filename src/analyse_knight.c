/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** analyse_knight.c
*/

#include "../include/my.h"

all_t *analyse_knight(all_t *store)
{
    game_object_t *knight = store->objects[PLAYING];

    for(; knight->type != KNIGHT; knight = knight->next);
    knight = check_animated(knight);
    if (store->right_or_left == 1) {
        if (knight->rect.left >= 620)
            knight->rect.left = 0;
        knight->rect.top = 0;
    }
    if (store->right_or_left == 2) {
        if (knight->rect.left >= 620)
            knight->rect.left = 0;
        knight->rect.top = 127;
    }
    if (store->event.type == sfEvtKeyPressed) {
        store = analyse_knight_right_left(store, knight);
        store = analyse_knight_jump(store, knight);
    }
    return (analyse_knight_2(store, knight));
}

all_t *analyse_knight_2(all_t *store, game_object_t *knight)
{
    if (store->event.type == sfEvtKeyReleased) {
        if (store->event.key.code == store->keys_code[3]) {
            store->velocity.x = 0;
            knight->rect.top = 0;
        }
        if (store->event.key.code == store->keys_code[2]) {
            store->velocity.x = 0;
            knight->rect.top = 127;
        }
    }
    knight = check_animated(knight);
    store->right_or_left = 0;
    sfSprite_setTextureRect(knight->sprite, knight->rect);
    return (store);
}

all_t *analyse_knight_jump(all_t *store, game_object_t *knight)
{
    if (sfKeyboard_isKeyPressed(store->keys_code[5]) && store->nb_jump == 1) {
        store->nb_jump = 0;
        store->velocity.y -= 30;
    }
    return (store);
}

all_t *analyse_knight_right_left(all_t *store, game_object_t *knight)
{
    if (sfKeyboard_isKeyPressed(store->keys_code[3])) {
        store->velocity.x -= 3;
        store->right_or_left = 1;
        if (knight->rect.left >= 620)
            knight->rect.left = 0;
        knight->rect.top = 254;
    }
    if (sfKeyboard_isKeyPressed(store->keys_code[2])) {
        store->velocity.x += 3;
        store->right_or_left = 2;
        if (knight->rect.left >= 620)
            knight->rect.left = 0;
        knight->rect.top = 381;
    }
    return (store);
}
