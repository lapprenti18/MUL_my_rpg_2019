/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** manage_jump.c
*/

#include "../include/my.h"

col_t spe_array[3] =
{
    {0, "assets/collisions/first_screen.txt"},
    {1, "assets/collisions/second_screen.txt"},
    {2, "assets/collisions/third_screen.txt"}
};

void change_screen_last(all_t *store, game_object_t *object)
{
    if (store->index_maps == 2) {
        if (object->pos.x >= 1900) {
            object->change_pos(object, (sfVector2f){1900, object->pos.y});
            store->change_texture = false;
        }
        if (object->pos.x <= 0) {
            store->index_maps -= 1;
            object->change_pos(object, (sfVector2f){1900, object->pos.y});
            store->change_texture = true;
            store->current = get_array(spe_array[1].filepath);
        }
    }
}

void change_screen_next(all_t *store, game_object_t *object)
{
    if (store->index_maps == 1) {
        if (object->pos.x >= 1900) {
            store->index_maps += 1;
            object->change_pos(object, (sfVector2f){50, object->pos.y});
            store->change_texture = true;
            store->current = get_array(spe_array[2].filepath);
        }
        if (object->pos.x <= 0) {
            store->index_maps -= 1;
            object->change_pos(object, (sfVector2f){1900, object->pos.y});
            store->change_texture = true;
            store->current = get_array(spe_array[0].filepath);
        }
        return;
    }
    change_screen_last(store, object);
}

void change_screen(all_t *store, game_object_t *object)
{
    if (object->pos.y >= 1000)
        object->change_pos(object, (sfVector2f){200, 500});
    if (store->index_maps == 0) {
        if (object->pos.x <= 10) {
            object->change_pos(object, (sfVector2f){10, object->pos.y});
            store->change_texture = false;
        }
        if (object->pos.x >= 1900) {
            store->index_maps += 1;
            object->change_pos(object, (sfVector2f){50, object->pos.y});
            store->change_texture = true;
            store->current = get_array(spe_array[1].filepath);
        }
        return;
    }
    change_screen_next(store, object);
}

void update_jump(all_t *store)
{
    game_object_t *copy = store->objects[PLAYING];
    int check = 0;

    for (; copy->type != KNIGHT; copy = copy->next);
    check = check_collision(store);
    update_and_check(store, copy);
    if (copy->pos.y > check) {
        store->nb_jump = 1;
        store->velocity.y = 0;
        copy->pos.y = check;
        copy->rect.top = (copy->rect.top <= 127) ? \
        copy->rect.top : copy->rect.top - 762;
        sfSprite_setTextureRect(copy->sprite, copy->rect);
    }
    change_screen(store, copy);
    sfSprite_setPosition(copy->sprite, copy->pos);
}