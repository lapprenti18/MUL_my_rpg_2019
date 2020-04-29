/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** quest.c
*/

#include "../include/my.h"

game_object_t *setup_quest_sprites(void)
{
    game_object_t *quest = NULL;

    add_node_back(&quest, (coding_style_t){BACKGROUND, (sfFloatRect){960, \
    540, 1920, 1080}, (sfIntRect){0, 0, 1920, 1080}, \
    "assets/textures/house_quest.png", false, false, -1, -1});
    return (quest);
}