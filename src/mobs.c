/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** mobs.c
*/

#include "../include/my.h"

void add_mobs(all_t *store)
{
    int rng = rand() % 6 + 4;
    int rng_x = 0;
    int rng_y = 0;
    int index = 0;

    for (index = 0; index < rng; index += 1) {
        rng_x = rand() % 1700 + 100;
        rng_y = rand() % 500 + 300;
        store->mobs[index] = create_mob("assets/textures/mobs.png", \
        (sfVector2f){rng_x, rng_y}, (sfIntRect){0, 200, 97, 113}, 50);
    }
    for (; index < 10; index += 1)
        store->mobs[index].alive = false;
}

mob_t create_mob(char *filepath, sfVector2f pos, sfIntRect rect, int hp)
{
    mob_t mob;

    mob.hp = hp;
    mob.rect = rect;
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