/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** mobs.c
*/

#include "../include/my.h"

void spawn_mob(all_t *store)
{
    int rng = rand() % 6 + 4;
    int rng_x = 0;
    int rng_y = 0;
    int index = 0;

    for (index = 0; index < rng; index += 1) {
        rng_x = rand() % 1700 + 100;
        rng_y = rand() % 500 + 300;
        store->mobs[index] = create_mob("assets/textures/boosito.png", \
        (sfVector2f){rng_x, rng_y}, (sfIntRect){0, 0, 160, 180}, 50);
        store->mobs[index].sec = 0;
        store->mobs[index].rec = 0;
    }
    for (; index < 10; index += 1)
        store->mobs[index].alive = false;
}

void spawn_boss(all_t *store)
{
    int rng_x = 0;
    int rng_y = 0;

    for (int i = 0; i < 10; i += 1)
        store->mobs[i].alive = false;
    if (store->quest_status == 1) {
        store->mobs[0].alive = true;
        rng_x = rand() % 1700 + 100;
        rng_y = 650;
        store->mobs[0] = create_mob("assets/textures/boosito.png", \
        (sfVector2f){rng_x, rng_y}, (sfIntRect){0, 0, 160, 180}, 50);
        store->mobs[0].sec = 0;
        store->mobs[0].rec = 0;
    }
}

void add_mobs(all_t *store)
{
    if (store->index_maps != 5)
        spawn_mob(store);
    if (store->index_maps == 5)
        spawn_boss(store);
}

mob_t create_mob(char *filepath, sfVector2f pos, sfIntRect rect, int hp)
{
    mob_t mob;

    mob.hp = hp;
    mob.rect = rect;
    mob.reward = 10;
    mob.pos = pos;
    mob.texture = sfTexture_createFromFile(filepath, NULL);
    mob.sprite = sfSprite_create();
    mob.alive = true;
    mob.clock = sfClock_create();
    sfSprite_setTexture(mob.sprite, mob.texture, sfTrue);
    sfSprite_setTextureRect(mob.sprite, mob.rect);
    sfSprite_setPosition(mob.sprite, mob.pos);
    return (mob);
}

mob_t *init_mobs(void)
{
    mob_t *mobs = my_malloc(sizeof(mob_t) * 10);

    for (int index = 0; index < 10; index += 1) {
        mobs[index].sprite = NULL;
        mobs[index].texture = NULL;
        mobs[index].clock = NULL;
        mobs[index].alive = false;
    }
    return (mobs);
}