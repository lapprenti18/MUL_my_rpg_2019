/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** loop_game.c
*/

#include "../include/my.h"

void clock_enn(all_t *store, int i)
{
    store->mobs[i].time = sfClock_getElapsedTime(store->mobs[i].clock);
    store->mobs[i].sec = store->mobs[i].time.microseconds / 1000000.0;
    if (store->mobs[i].sec > 0.1) {
        if (store->mobs[i].rec == 0)
        store->mobs[i].rect.left += 160;
        if (store->mobs[i].rec == 1)
            store->mobs[i].rect.left -= 160;
        sfSprite_setTextureRect(store->mobs[i].sprite, store->mobs[i].rect);
        if (store->mobs[i].rect.left >= 800)
            store->mobs[i].rec = 1;
        if (store->mobs[i].rect.left <= 0)
            store->mobs[i].rec = 0;
        sfClock_restart(store->mobs[i].clock);
    }
}

void move_enn(all_t *store, int i, game_object_t *ob)
{
    if (store->mobs[i].pos.x - ob->pos.x < 400 && store->mobs[i].pos.y -\
     ob->pos.y < 200 && store->mobs[i].pos.x - ob->pos.x > -400) {
        if (store->mobs[i].pos.x <= ob->pos.x - 30) {
            store->mobs[i].pos.x += 1;
            store->mobs[i].rect.top = 180;
        }
        if (store->mobs[i].pos.x > ob->pos.x - 10) {
            store->mobs[i].pos.x -= 1;
            store->mobs[i].rect.top = 0;
        }
        if (store->mobs[i].pos.y <= ob->pos.y - 100) {
            store->mobs[i].pos.y += 1;
        }
        if (store->mobs[i].pos.y > ob->pos.y - 100) {
            store->mobs[i].pos.y -= 1;
        }
        sfSprite_setPosition(store->mobs[i].sprite, store->mobs[i].pos);
        sfRenderWindow_drawSprite(store->window, store->mobs[i].sprite, NULL);
    }
}

void boss(all_t *store, game_object_t *ob)
{
    sfSprite_setPosition(store->mobs[0].sprite, store->mobs[0].pos);
    sfRenderWindow_drawSprite(store->window, store->mobs[0].sprite, NULL);
    if (ob->pos.y >= 700) {
        if (store->mobs[0].pos.x < ob->pos.x)
            store->mobs[0].pos.x += 5;
        else
            store->mobs[0].pos.x -= 5;
    }
}

void update_ennemy(all_t *store)
{
    game_object_t *ob = NULL;

    for (ob = store->objects[PLAYING]; ob; ob = ob->next)
        if (ob->type == KNIGHT) {
            break;
        }
    if (store->index_maps != 5) {
        for (int i = 0; i < 10; i += 1) {
            if (store->mobs[i].alive == true) {
                clock_enn(store, i);
                move_enn(store, i, ob);
            }
        }
    }
    if (store->index_maps == 5 && store->quest_status == 1)
        boss(store, ob);
}