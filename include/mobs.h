/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** mobs.c
*/

#ifndef MOBS_H_
#define MOBS_H_

#include "./my.h"

mob_t create_mob(char *filepath, sfVector2f pos, sfIntRect rect, int hp);
mob_t *init_mobs(void);
void add_mobs(all_t *store);
void spawn_mob(all_t *store);
void spawn_boss(all_t *store);

#endif /* MOBS_H_ */