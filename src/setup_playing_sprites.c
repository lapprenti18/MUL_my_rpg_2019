/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** setup_playing_sprites.c
*/

#include "../include/my.h"

game_object_t *setup_playing_sprites_next(game_object_t *playing)
{
    add_node_back(&playing, (coding_style_t){ENTER_2, (sfFloatRect){200, \
    700, 160, 128}, (sfIntRect){0, 0, 160, 128}, \
    "assets/textures/panneau_enter.png", false, false, -1, -1});
    add_node_back(&playing, (coding_style_t){GOLDS, (sfFloatRect){1700, \
    100, 55, 57}, (sfIntRect){0, 0, 55, 57}, \
    "assets/textures/gold.png", false, false, -1, -1});
    return (playing);
}

game_object_t *setup_playing_sprites(void)
{
    int x = 325;
    game_object_t *playing  = NULL;

    add_node_back(&playing, (coding_style_t){BACKGROUND, (sfFloatRect){960, \
    540, 1920, 1080}, (sfIntRect){0, 0, 1920, 1080}, \
    "assets/textures/1er_map.png", false, false, 687, 0.2});
    add_node_back(&playing, (coding_style_t){MANA_BAR, (sfFloatRect){229, 146, \
    229, 146}, (sfIntRect){0, 0, 229, 146}, \
    "assets/textures/mana_bar_final-min.png", false, true, 687, 0.2});
    for (; x < 651; x += 75)
        add_node_back(&playing, (coding_style_t){HEALTH, (sfFloatRect){x, 146, \
    51, 66}, (sfIntRect){0, 0, 51, 66}, \
    "assets/textures/animation_vie_v5-min.png", false, true, 260, 0.15});
    add_node_back(&playing, (coding_style_t){KNIGHT, (sfFloatRect){201, 500, \
    89, 127}, (sfIntRect){0, 0, 89, 127}, \
    "assets/textures/Knight_final-min.png", false, false, 700, 0.2});
    add_node_back(&playing, (coding_style_t){ENTER, (sfFloatRect){1000, \
    700, 160, 128}, (sfIntRect){0, 0, 160, 128}, \
    "assets/textures/panneau_enter.png", false, false, -1, -1});
    return (setup_playing_sprites_next(playing));
}