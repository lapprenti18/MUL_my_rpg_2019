/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** setup_inventory_sprites.c
*/

#include "../include/my.h"

game_object_t *setup_inventory_sprites_next(game_object_t *inventory)
{
    add_node_back(&inventory, (coding_style_t){GOLD_CHARM, \
    (sfFloatRect){490, 580, 135, 135}, (sfIntRect){720, 587, 135, 135}, \
    "assets/textures/charms.png", false, false, -1, -1});
    add_node_back(&inventory, (coding_style_t){HEART_CHARM, \
    (sfFloatRect){588, 580, 135, 135}, (sfIntRect){690, 907, 135, 135}, \
    "assets/textures/charms.png", false, false, -1, -1});
    for (game_object_t *copy = inventory; copy; copy = copy->next)
        if (copy->type >= LIFE_CHARM)
            sfSprite_setScale(copy->sprite, (sfVector2f){0.6, 0.6});
    return (inventory);
}

game_object_t *setup_inventory_sprites(void)
{
    game_object_t *inventory = NULL;

    add_node_back(&inventory, (coding_style_t){BACKGROUND, (sfFloatRect)\
    {960, 540, 1920, 1080}, (sfIntRect){0, 0, 1920, 1080}, \
    "assets/textures/screen.png", false, false, -1, -1});
    add_node_back(&inventory, (coding_style_t){INVENTORY, (sfFloatRect)\
    {960, 540, 1920, 1080}, (sfIntRect){0, 0, 1920, 1080}, \
    "assets/textures/inventory.png", false, false, -1, -1});
    add_node_back(&inventory, (coding_style_t){LIFE_CHARM, \
    (sfFloatRect){217, 580, 135, 135}, (sfIntRect){295, 148, 135, 135}, \
    "assets/textures/charms.png", false, false, -1, -1});
    add_node_back(&inventory, (coding_style_t){ATTACK_CHARM, \
    (sfFloatRect){308, 580, 135, 135}, (sfIntRect){0, 148, 135, 135}, \
    "assets/textures/charms.png", false, false, -1, -1});
    add_node_back(&inventory, (coding_style_t){MANA_CHARM, \
    (sfFloatRect){399, 580, 135, 135}, (sfIntRect){430, 296, 135, 135}, \
    "assets/textures/charms.png", false, false, -1, -1});
    return (setup_inventory_sprites_next(inventory));
}