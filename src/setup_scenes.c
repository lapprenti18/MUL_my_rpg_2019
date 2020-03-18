/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** setup_scenes.c
*/

#include "../include/my.h"

game_object_t *setup_playing_sprites(void)
{
    game_object_t *playing  = NULL;

    add_node_back(&playing, (coding_style_t){MANA_BAR, (sfFloatRect){229, 146, \
    229, 146}, (sfIntRect){0, 0, 229, 146}, "assets/textures/mana_bar.png"});
    return (playing);
}

game_object_t *setup_options_sprites(void)
{
    game_object_t *options  = NULL;

    add_node_back(&options, (coding_style_t){BACKGROUND, (sfFloatRect){960, \
    1080 / 2, 1920, 1080}, (sfIntRect){0, 0, 1920, 1080}, \
    "assets/textures/screen.png"});
    add_node_back(&options, (coding_style_t){OPTION_SHAPE, \
    (sfFloatRect){960, 383, 726, 127}, (sfIntRect){0, 0, 726, 127}, \
    "assets/textures/option_and_shape.png"});
    add_node_back(&options, (coding_style_t){AUDIO, (sfFloatRect){960, 510, \
    309, 70}, (sfIntRect){0, 0, 309, 70}, "assets/textures/menu_options.png"});
    add_node_back(&options, (coding_style_t){VIDEO, (sfFloatRect){960, 580, 309\
    , 70}, (sfIntRect){0, 70, 309, 70}, "assets/textures/menu_options.png"});
    add_node_back(&options, (coding_style_t){KEYBOARD, (sfFloatRect){960, \
    650, 309, 70}, (sfIntRect){0, 140, 309, 70}, \
    "assets/textures/menu_options.png"});
    add_node_back(&options, (coding_style_t){BACK, (sfFloatRect){960, 920, \
    309, 70}, (sfIntRect){0, 210, 309, 70}, \
    "assets/textures/menu_options.png"});
    return (options);
}

game_object_t *setup_menu_sprites(void)
{
    game_object_t *menu  = NULL;

    add_node_back(&menu, (coding_style_t){BACKGROUND, (sfFloatRect){960, 540, \
    1920, 1080}, (sfIntRect){0, 0, 1920, 1080}, "assets/textures/screen.png"});
    add_node_back(&menu, (coding_style_t){PLAY, (sfFloatRect){960, 651, \
    344, 59}, (sfIntRect){0, 0, 344, 59}, "assets/textures/menu.png"});
    add_node_back(&menu, (coding_style_t){OPTIONS, (sfFloatRect){960, 710, \
    344, 59}, (sfIntRect){0, 59, 344, 59}, "assets/textures/menu.png"});
    add_node_back(&menu, (coding_style_t){ACHIEVEMENTS, (sfFloatRect){960, \
    769, 344, 59}, (sfIntRect){0, 118, 344, 59}, "assets/textures/menu.png"});
    add_node_back(&menu, (coding_style_t){EXTRAS, (sfFloatRect){960, 828, \
    344, 59}, (sfIntRect){0, 177, 344, 59}, "assets/textures/menu.png"});
    add_node_back(&menu, (coding_style_t){QUIT, (sfFloatRect){960, 887, \
    344, 59}, (sfIntRect){0, 236, 344, 59}, "assets/textures/menu.png"});
    add_node_back(&menu, (coding_style_t){NAME, (sfFloatRect){960, 300, \
    1206, 457}, (sfIntRect){0, 0, 1206, 457}, \
    "assets/textures/game_name.png"});
    return (menu);
}