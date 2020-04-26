/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** lopp_game.h
*/

#ifndef LOOP_GAME_H_
#define LOOP_GAME_H_

#include "./my.h"

void loop_game(all_t *store);
void update_view(all_t *store);
void update_view_next(all_t *store, game_object_t *ob, game_object_t *copy);


#endif /* LOOP_GAME_H_ */