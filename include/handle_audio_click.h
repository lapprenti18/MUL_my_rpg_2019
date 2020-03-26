/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** handle_audio_click.h
*/

#ifndef HANDLE_AUDIO_CLICK_H_
#define HANDLE_AUDIO_CLICK_H_

#include "./my.h"

void update_musics_volume(all_t *store, sfVector2f rect_pos);
void update_master_volume(all_t *store, sfVector2f rect_pos);
void handle_audio_click_next(all_t *store, game_object_t *copy);
void handle_audio_click(all_t *store, game_object_t *copy, sfVector2i mouse);

#endif /* HANDLE_AUDIO_CLICK_H */