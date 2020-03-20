/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** manage_mouse_clicked.h
*/

#ifndef MANAGE_MOUSE_CLICKED_H_
#define MANAGE_MOUSE_CLICKED_H_

#include "./my.h"

void handle_audio_click(all_t *store, game_object_t *copy);
void handle_options_click(all_t *store, game_object_t *copy);
void handle_menu_click(all_t *store, game_object_t *copy);
void handle_click(all_t *store, game_object_t *object);
void manage_mouse_clicked(all_t *store);

#endif /* MANAGE_MOUSE_CLICKED_H_ */