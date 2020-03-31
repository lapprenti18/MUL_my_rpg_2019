/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** analyse_knight.h
*/

#ifndef ANALYSE_KNIGHT_H_
#define ANALYSE_KNIGHT_H_

#include "./my.h"

void analyse_knight(all_t *store);
void analyse_knight_2(all_t *store, game_object_t *knight);
void analyse_knight_right_left(all_t *store, game_object_t *knight);
void analyse_knight_jump(all_t *store);

#endif /* ANALYSE_KNIGHT_H_ */