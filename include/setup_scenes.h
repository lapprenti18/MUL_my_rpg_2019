/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** setup_scenes.h
*/

#ifndef SETUP_SCENES_H_
#define SETUP_SCENES_H_

#include "./my.h"

game_object_t *setup_audio_sprites_next(game_object_t *audio);
game_object_t *setup_audio_sprites(void);
game_object_t *setup_options_sprites(void);
game_object_t *setup_menu_sprites(game_object_t *menu);

#endif /* SETUP_SCENES_H_ */