/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** collisions.c
*/

#include "../include/my.h"

int check_left_collision(all_t *store)
{
    sfVector2f pos = {0, 0};
    int y[2] = {0};
    int x = 0;
    game_object_t *ob = NULL;

    for (ob = store->objects[PLAYING]; ob; ob = ob->next)
        if (ob->type == KNIGHT) {
            pos.x = ob->pos.x;
            pos.y = ob->pos.y;
            break;
        }
    y[0] = (int)(pos.y - ob->height / 2) / 20;
    y[1] = (int)(pos.y + ob->height / 2) / 20;
    x = (int)(pos.x + ob->length / 2) / 20 - 3;
    if (x < 1 || y[0] < 0 || x > 95 || y[0] > 54)
        return (0);
    for (int y_temp = y[0]; y_temp < y[1]; y_temp += 1)
        if (store->current[y_temp][x - 1] == '1')
            return (1);
    return (0);
}

int check_right_collision(all_t *store)
{
    sfVector2f pos = {0, 0};
    int y[2] = {0};
    int x = 0;
    game_object_t *ob = NULL;

    for (ob = store->objects[PLAYING]; ob; ob = ob->next)
        if (ob->type == KNIGHT) {
            pos.x = ob->pos.x;
            pos.y = ob->pos.y;
            break;
        }
    y[0] = (int)(pos.y - ob->height / 2) / 20;
    y[1] = (int)(pos.y + ob->height / 2) / 20;
    x = (int)(pos.x + ob->length / 2) / 20 - 3;
    if (x < 0 || y[0] < 0 || x > 94 || y[0] > 54)
        return (0);
    for (int y_temp = y[0]; y_temp < y[1]; y_temp += 1)
        if (store->current[y_temp][x + 1] == '1')
            return (1);
    return (0);
}

int check_collision(all_t *store)
{
    sfVector2f pos = {0, 0};
    int y = 0;
    int x = 0;
    game_object_t *ob = NULL;

    if (store->scene != PLAYING)
        return (50);
    for (ob = store->objects[PLAYING]; ob; ob = ob->next)
        if (ob->type == KNIGHT) {
            pos.x = ob->pos.x;
            pos.y = ob->pos.y;
            break;
        }
    y = (int)(pos.y + ob->height / 2) / 20;
    x = (int)(pos.x + ob->length / 2) / 20 - 3;
    if (x < 0 || y < 0 || x > 95 || y > 54)
        return (pos.y);
    for (; store->current[y]; y += 1)
        if (store->current[y][x] == '1')
            return (y * 20 - (ob->height / 2));
    return (1200);
}