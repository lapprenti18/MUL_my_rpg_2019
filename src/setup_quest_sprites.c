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
    add_node_back(&quest, (coding_style_t){QUEST_BOX, (sfFloatRect){1560, \
    575, 434, 614}, (sfIntRect){0, 0, 434, 614}, \
    "assets/textures/quest_box1.png", false, false, -1, -1});
    add_node_back(&quest, (coding_style_t){BACK, (sfFloatRect){150, 950, \
    309, 70}, (sfIntRect){0, 210, 309, 70}, \
    "assets/textures/menu_options.png", true, false, -1, -1});
    add_node_back(&quest, (coding_style_t){LISTEN, (sfFloatRect){860, 575, \
    165, 130}, (sfIntRect){0, 0, 165, 130}, \
    "assets/textures/panneau_listen.png", false, false, -1, -1});
    add_node_back(&quest, (coding_style_t){QUEST_BOX_END, (sfFloatRect){1560, \
    575, 434, 614}, (sfIntRect){0, 0, 434, 614}, \
    "assets/textures/quest_box_end.png", false, false, -1, -1});
    return (quest);
}