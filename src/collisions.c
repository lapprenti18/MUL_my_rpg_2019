/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** collisions.c
*/

#include "../include/my.h"

int check_collision(all_t *store)
{
    sfVector2f pos = {0, 0};
    int y = 0;
    int x = 0;
    game_object_t *ob = NULL;

    if (store->scene != PLAYING)
        return (-1);
    for (ob = store->objects[PLAYING]; ob; ob = ob->next)
        if (ob->type == KNIGHT) {
            pos.x = ob->pos.x;
            pos.y = ob->pos.y;
            break;
        }
    y = (pos.y + ob->height / 2) / 20;
    x = (pos.x + ob->length / 2) / 20;
    if (x < 0 || y < 0 || x > 95 || y > 95)
        return (-1);
    printf("y : %d x : %d\n", y, x);
    for (; store->current[y]; y += 1) {
        printf("%c\n", store->current[y][x]);
        if (store->current[y][x] == '1')
            return (y * 20 - (ob->height / 2));
    }
    return (1200);
}