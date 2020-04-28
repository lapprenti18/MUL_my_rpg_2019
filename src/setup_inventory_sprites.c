/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** setup_inventory_sprites.c
*/

#include "../include/my.h"

game_object_t *setup_inventory_sprites(void)
{
    game_object_t *inventory = NULL;

    add_node_back(&inventory, (coding_style_t){BACKGROUND, (sfFloatRect)\
    {960, 540, 1920, 1080}, (sfIntRect){0, 0, 1920, 1080}, \
    "assets/textures/screen.png", false, false, -1, -1});
    add_node_back(&inventory, (coding_style_t){INVENTORY, (sfFloatRect)\
    {960, 540, 1920, 1080}, (sfIntRect){0, 0, 1920, 1080}, \
    "assets/textures/inventory.png", false, false, -1, -1});
    return (inventory);
}