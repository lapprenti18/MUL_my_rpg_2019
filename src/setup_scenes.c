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

    add_node_back(&playing, MANA_BAR, \
    (sfFloatRect){229, 146, 229, 146}, (sfIntRect){0, 0, 229, 146});
    return (playing);
}

game_object_t *setup_options_sprites(void)
{
    game_object_t *options  = NULL;

    add_node_back(&options, OPTION_SHAPE, \
    (sfFloatRect){960, 383, 726, 127}, (sfIntRect){0, 0, 726, 127});
    add_node_back(&options, AUDIO, \
    (sfFloatRect){960, 510, 309, 70}, (sfIntRect){0, 0, 309, 70});
    add_node_back(&options, VIDEO, \
    (sfFloatRect){960, 580, 309, 70}, (sfIntRect){0, 70, 309, 70});
    add_node_back(&options, KEYBOARD, \
    (sfFloatRect){960, 650, 309, 70}, (sfIntRect){0, 140, 309, 70});
    add_node_back(&options, BACK, \
    (sfFloatRect){960, 720, 309, 70}, (sfIntRect){0, 210, 309, 70});
    return (options);
}

game_object_t *setup_menu_sprites(void)
{
    game_object_t *menu  = NULL;

    add_node_back(&menu, PLAY, \
    (sfFloatRect){960, 651, 344, 59}, (sfIntRect){0, 0, 344, 59});
    add_node_back(&menu, OPTIONS, \
    (sfFloatRect){960, 710, 344, 59}, (sfIntRect){0, 59, 344, 59});
    add_node_back(&menu, ACHIEVEMENTS, \
    (sfFloatRect){960, 769, 344, 59}, (sfIntRect){0, 118, 344, 59});
    add_node_back(&menu, EXTRAS, \
    (sfFloatRect){960, 828, 344, 59}, (sfIntRect){0, 177, 344, 59});
    add_node_back(&menu, QUIT, \
    (sfFloatRect){960, 887, 344, 59}, (sfIntRect){0, 236, 344, 59});
    return (menu);
}