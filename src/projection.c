/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** projection.c
*/

#include "../include/my.h"

int proj_y(all_t *store, game_object_t *copy, float y_temp)
{
    int y[2] = {0};
    int x = 0;

    if (store->scene != PLAYING)
        return (1);
    y[0] = (int)(y_temp - copy->height / 2) / 20;
    y[1] = (int)(y_temp + copy->height / 2) / 20;
    x = (int)(copy->pos.x + copy->length / 2) / 20 - 3;
    if (x < 0 || y[0] < 0 || x > 95 || y[1] > 54)
        return (1);
    for (int index = y[0]; index < y[1]; index += 1)
        if (store->current[index][x] == '1')
            return (0);
    return (1);
}

int proj_x(all_t *store, game_object_t *copy, float x_temp)
{
    int y[2] = {0};
    int x = 0;

    if (store->scene != PLAYING)
        return (1);
    y[0] = (int)(copy->pos.y - copy->height / 2) / 20;
    y[1] = (int)(copy->pos.y + copy->height / 2) / 20;
    x = (int)(x_temp + copy->length / 2) / 20 - 3;
    if (x < 0 || y[0] < 0 || x > 95 || y[1] > 54)
        return (1);
    for (int index = y[0]; index < y[1]; index += 1)
        if (store->current[index][x] == '1')
            return (0);
    return (1);
}

void update_and_check(all_t *store, game_object_t *copy)
{
    store->accel.x = 0;
    store->accel.y = store->gravity;
    store->accel.x += store->velocity.x * store->frottement;
    store->velocity.x += store->accel.x;
    store->velocity.y += store->accel.y;
    if (proj_x(store, copy, copy->pos.x + \
    store->velocity.x + 0.5 * store->accel.x))
        copy->pos.x += store->velocity.x + 0.5 * store->accel.x;
    if (proj_y(store, copy, copy->pos.y + \
    store->velocity.y + 0.5 * store->accel.y))
        copy->pos.y += store->velocity.y + 0.5 * store->accel.y;
}