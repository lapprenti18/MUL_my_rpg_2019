/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** setup_pause_sprites.c
*/

#include "../include/my.h"

game_object_t *setup_pause_sprites(void)
{
    game_object_t *pause = NULL;

    add_node_back(&pause, (coding_style_t){SHAPE_PAUSE, (sfFloatRect)\
    {960, 540, 1920, 1080}, (sfIntRect){0, 0, 1920, 1080}, \
    "assets/textures/shape_pause.png", false, false, -1, -1});
    add_node_back(&pause, (coding_style_t){PAUSE_CONTINUE, (sfFloatRect)\
    {960, 490, 348, 62}, (sfIntRect){0, 0, 348, 62}, \
    "assets/textures/menu_pause.png", true, false, -1, -1});
    add_node_back(&pause, (coding_style_t){PAUSE_OPTIONS, (sfFloatRect)\
    {960, 552, 348, 62}, (sfIntRect){0, 62, 348, 124}, \
    "assets/textures/menu_pause.png", true, false, -1, -1});
    add_node_back(&pause, (coding_style_t){PAUSE_QUIT, (sfFloatRect)\
    {960, 614, 348, 62}, (sfIntRect){0, 124, 348, 186}, \
    "assets/textures/menu_pause.png", true, false, -1, -1});
    return (pause);
}