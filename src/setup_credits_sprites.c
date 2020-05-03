/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** setup_credits_sprites.c
*/

#include "../include/my.h"

game_object_t *setup_credits_sprites(void)
{
    game_object_t *credits = NULL;

    add_node_back(&credits, (coding_style_t){BACKGROUND, (sfFloatRect)\
    {960, 540, 1920, 1080}, (sfIntRect){0, 0, 1920, 1080}, \
    "assets/textures/credits.png", false, false, -1, -1});
    return (credits);
}