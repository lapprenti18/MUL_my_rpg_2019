/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** set_structures.h
*/

#ifndef SET_STRUCTURES_H_
#define SET_STRUCTURES_H_

#include "./my.h"

sfRectangleShape **create_white_rectangles(void);
sfMusic **create_tab_music(void);
particles_t **create_particles(int *random);
sfRenderWindow *create_window(int fps, sfUint32 style, int width, int height);
void set_structures(all_t *store);

#endif /* LOOP_GAME_H_ */