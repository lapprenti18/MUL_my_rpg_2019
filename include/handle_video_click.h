/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** handle_video_click.h
*/

#ifndef HANDLE_VIDEO_CLICK_H_
#define HANDLE_VIDEO_CLICK_H_

#include "./my.h"

void update_game_object(all_t *store, game_object_t *object);
void scale_sprites(all_t *store, int y);
void update_video(all_t *store, game_object_t *copy);
void handle_video_click(all_t *store, game_object_t *copy);

#endif /* HANDLE_VIDEO_CLICK_H_ */