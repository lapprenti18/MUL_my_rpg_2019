/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** loop_game.c
*/

#include "../include/my.h"

void show_sword(all_t *store)
{
    game_object_t *object = store->objects[PLAYING];
    game_object_t *copy = store->objects[PLAYING];

    for (; object->type != KNIGHT ; object = object->next);
    for (; copy->type != SWORD_EFFECT ; copy = copy->next);

    if (object->rect.top == 0 || object->rect.top == 762) {
        copy->rect.left = 0;
        sfSprite_setTextureRect(copy->sprite, copy->rect);
        copy->change_pos(copy, (sfVector2f){object->pos.x + 50, \
        object->pos.y});
    }
    if (object->rect.top == 127 || object->rect.top == 889) {
        copy->rect.left = 179;
        sfSprite_setTextureRect(copy->sprite, copy->rect);
        copy->change_pos(copy, (sfVector2f){object->pos.x - 90, \
        object->pos.y});
    }
}

void update_sword(all_t *store)
{
    store->time_attack = sfClock_getElapsedTime(store->clock_attack);
    store->sec_attack = store->time_attack.microseconds / 1000000.0;
    if (store->sec_attack < 0.2 && store->attack == 1) {
        store->show_sword = true;
        show_sword(store);
        hitbox_on_mobs(store);
        return;
    }
    store->attack = 0;
    sfClock_restart(store->clock_attack);
}
