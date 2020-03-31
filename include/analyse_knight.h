/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** analyse_knight.h
*/

#ifndef ANALYSE_KNIGHT_H_
#define ANALYSE_KNIGHT_H_

#include "./my.h"

all_t *analyse_knight(all_t *store);
all_t *analyse_knight_2(all_t *store, game_object_t *knight);
all_t *analyse_knight_right_left(all_t *store, game_object_t *knight);
all_t *analyse_knight_jump(all_t *store, game_object_t *knight);

#endif /* ANALYSE_KNIGHT_H_ */