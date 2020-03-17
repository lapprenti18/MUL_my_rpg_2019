/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** setup_functions.h
*/

#ifndef SETUP_FUNCTIONS_H_
#define SETUP_FUNCTIONS_H_

#include "./my.h"

void move_rect(game_object_t *object, int offset, int size_max);
void change_pos(game_object_t *object, sfVector2f new_pos);

#endif /* SETUP_FUNCTIONS_H_ */