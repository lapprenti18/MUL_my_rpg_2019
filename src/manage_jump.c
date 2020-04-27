/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** manage_jump.c
*/

#include "../include/my.h"

void change_screen_next(all_t *store, game_object_t *object)
{
    if (store->index_maps == 1) {
        if (object->pos.x >= 1900) {
            object->change_pos(object, (sfVector2f){1900, object->pos.y});
            store->change_texture = false;
        }
        if (object->pos.x <= 0) {
            store->index_maps = 0;
            object->change_pos(object, (sfVector2f){1900, object->pos.y});
            store->change_texture = true;
        }
    }
}

void change_screen(all_t *store, game_object_t *object)
{
    if (store->index_maps == 0) {
        if (object->pos.x <= 0) {
            object->change_pos(object, (sfVector2f){0, object->pos.y});
            store->change_texture = false;
        }
        if (object->pos.x >= 1900) {
            store->index_maps = 1;
            object->change_pos(object, (sfVector2f){50, object->pos.y});
            store->change_texture = true;
        }
        return;
    }
    change_screen_next(store, object);
}

void update_jump(all_t *store)
{
    game_object_t *copy = store->objects[PLAYING];
    int check = check_collision(store);

    for (; copy->type != KNIGHT; copy = copy->next);
    if (store->velocity.x > 2)
        store->velocity.x = 2;
    if (store->velocity.x < -2)
        store->velocity.x = -2;
    copy->pos.x -= store->velocity.x;
    copy->pos.y += store->velocity.y;
    change_screen(store, copy);
    if (copy->pos.y < 980) {
        store->velocity.y += store->gravity;
    } else {
        store->velocity.y = 0;
        copy->pos.y = 980;
        store->nb_jump = 1;
    }
    sfSprite_setPosition(copy->sprite, copy->pos);
}