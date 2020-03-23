/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** setup_scenes_2.c
*/

#include "../include/my.h"

game_object_t *setup_saves_next(game_object_t *save)
{
    add_node_back(&save, (coding_style_t){CLEAR_1, (sfFloatRect){1600, 350, \
    342, 35}, (sfIntRect){0, 0, 342, 35}, \
    "assets/textures/clear_save.png", true});
    add_node_back(&save, (coding_style_t){BACK, (sfFloatRect){960, 920, \
    309, 70}, (sfIntRect){0, 210, 309, 70}, \
    "assets/textures/menu_options.png", true});
    return (save);
}

game_object_t *setup_saves_sprites(void)
{
    game_object_t *save = NULL;

    add_node_back(&save, (coding_style_t){BACKGROUND, (sfFloatRect){960, 540, \
    1920, 1080}, (sfIntRect){0, 0, 1920, 1080}, "assets/textures/screen.png", \
    false});
    add_node_back(&save, (coding_style_t){PROFILE, (sfFloatRect){960, 140, \
    712, 115}, (sfIntRect){0, 0, 712, 115}, \
    "assets/textures/select_profile.png", false});
    add_node_back(&save, (coding_style_t){SAVE_1, (sfFloatRect){850, 350, \
    1172, 147}, (sfIntRect){0, 0, 1172, 147}, \
    "assets/textures/select_save.png", true});
    add_node_back(&save, (coding_style_t){SAVE_2, (sfFloatRect){850, 500, \
    1172, 147}, (sfIntRect){0, 150, 1172, 147}, \
    "assets/textures/select_save.png", true});
    add_node_back(&save, (coding_style_t){SAVE_3, (sfFloatRect){850, 650, \
    1172, 150}, (sfIntRect){0, 320, 1172, 147}, \
    "assets/textures/select_save.png", true});
    add_node_back(&save, (coding_style_t){SAVE_4, (sfFloatRect){850, 800, \
    1172, 150}, (sfIntRect){0, 470, 1172, 147}, \
    "assets/textures/select_save.png", true});
    return (setup_saves_next(save));
}