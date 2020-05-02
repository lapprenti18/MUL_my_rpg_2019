/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** setup_shop_sprites.h
*/

#ifndef UPDATE_ENN_H_
#define UPDATE_ENN_H_

#include "./my.h"

void update_ennemy(all_t *store);
void boss(all_t *store, game_object_t *ob);
void move_enn(all_t *store, int i, game_object_t *ob);
void clock_enn(all_t *store, int i);
void clock_boss(all_t *store);

#endif /* UPDATE_ENN_H_ */