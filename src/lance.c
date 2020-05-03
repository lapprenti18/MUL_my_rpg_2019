/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** loop_game.c
*/

#include "../include/my.h"

float angle(all_t *store, game_object_t *ob)
{
    double diff_x = (store->mobs[1].pos.x - ob->pos.x);
    double diff_y = (store->mobs[1].pos.y - ob->pos.y);
    float angle = atan2f(diff_y, diff_x) * (180.0 / M_PI);

    return (angle);
}

void clock_lance(all_t *store, game_object_t *ob)
{
    store->mobs[1].hp = 50;
    store->mobs[1].time = sfClock_getElapsedTime(store->mobs[1].clock);
    store->mobs[1].sec = store->mobs[1].time.microseconds / 1000000.0;
    if (store->mobs[1].sec < 5) {
        if (store->mobs[1].pos.x <= ob->pos.x)
            store->mobs[1].pos.x += 1;
        if (store->mobs[1].pos.x > ob->pos.x)
            store->mobs[1].pos.x -= 1;
        if (store->mobs[1].pos.y <= ob->pos.y)
            store->mobs[1].pos.y += 1;
        if (store->mobs[1].pos.y > ob->pos.y)
            store->mobs[1].pos.y -= 1;
        sfSprite_setRotation(store->mobs[1].sprite, angle(store, ob));
        return;
    }
    store->mobs[1].pos.y = store->mobs[0].pos.y;
    store->mobs[1].pos.x = store->mobs[0].pos.x;
    sfSprite_setRotation(store->mobs[1].sprite, angle(store, ob));
    sfClock_restart(store->mobs[1].clock);
}