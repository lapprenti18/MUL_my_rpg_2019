/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** manage_key_pressed_2.c
*/

#include "../include/my.h"

void analyse_right(all_t *store, game_object_t *knight, mob_t *mob)
{
    if (knight->pos.y - knight->height / 2 - 40 <= mob->pos.y && \
    knight->pos.y + knight->height / 2 >= mob->pos.y && \
    knight->pos.x - knight->length / 2 <= mob->pos.x && \
    knight->pos.x + knight->length / 2 + 100 >= mob->pos.x) {
        mob->hp -= store->knight_dgs;
        mob->pos.x += 10;
        sfSprite_setPosition(mob->sprite, mob->pos);
        if (mob->hp <= 0) {
            if (store->quest_status == 1 && store->index_maps == 5)
                store->quest_status = 2;
            mob->hp = 50;
            mob->alive = false;
            store->nb_golds += mob->reward * store->more_golds;
            store->mana_level += 1 * store->more_mana;
            if (store->mana_level > 8)
                store->mana_level = 8;
        }
    }
}

void analyse_left(all_t *store, game_object_t *knight, mob_t *mob)
{
    if (knight->pos.y - knight->height / 2 - 40 <= mob->pos.y && \
    knight->pos.y + knight->height / 2 >= mob->pos.y && \
    knight->pos.x + knight->length / 2 >= mob->pos.x && \
    knight->pos.x - knight->length / 2 - 150 <= mob->pos.x) {
        mob->hp -= store->knight_dgs;
        mob->pos.x -= 10;
        sfSprite_setPosition(mob->sprite, mob->pos);
        if (mob->hp <= 0) {
            if (store->index_maps == 5 && store->quest_status == 2)
                store->quest_status = 3;
            mob->hp = 50;
            mob->alive = false;
            store->nb_golds += mob->reward * store->more_golds;
            store->mana_level += store->more_mana;
            if (store->mana_level > 8)
                store->mana_level = 8;
        }
    }
}

void check_a_mob(all_t *store, game_object_t *knight, \
game_object_t *temp, mob_t *mob)
{
    if (mob->alive == false)
        return;
    if (temp->rect.left == 0)
        analyse_right(store, knight, mob);
    else
        analyse_left(store, knight, mob);
}

void hitbox_on_mobs(all_t *store)
{
    game_object_t *ob = store->objects[PLAYING];
    game_object_t *temp = store->objects[PLAYING];

    if (store->scene != PLAYING)
        return;
    for (; ob->type != KNIGHT; ob = ob->next);
    for (; temp->type != SWORD_EFFECT; temp = temp->next);
    if (store->show_sword == true) {
        for (int index = 0; index < 10; index += 1)
            check_a_mob(store, ob, temp, &(store->mobs[index]));
        return;
    }
}

void check_input2(all_t *store, game_object_t *object)
{
    if (sfKeyboard_isKeyPressed(store->keys_code[0]) && \
        store->nb_jump != 0 && object->pos.x >= 140 && \
        object->pos.x <= 280 && store->index_maps == 1)
            store->scene = QUEST;
    if (sfKeyboard_isKeyPressed(store->keys_code[2]) && \
    store->scene == PLAYING) {
        store->velocity.x = -3;
        object->rect.top = change_rect(object, 2);
    }
    if (sfKeyboard_isKeyPressed(store->keys_code[3]) && \
    store->scene == PLAYING) {
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