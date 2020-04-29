/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** setup_shop_sprites.c
*/

#include "../include/my.h"

game_object_t *setup_shop_sprites_next(game_object_t *shop)
{
    add_node_back(&shop, (coding_style_t){MANA_CHARM, \
    (sfFloatRect){1470, 522, 870, 136}, (sfIntRect){0, 272, 870, 136}, \
    "assets/textures/shop_charms.png", true, false, -1, -1});
    add_node_back(&shop, (coding_style_t){GOLD_CHARM, \
    (sfFloatRect){1470, 658, 870, 136}, (sfIntRect){0, 408, 870, 136}, \
    "assets/textures/shop_charms.png", true, false, -1, -1});
    add_node_back(&shop, (coding_style_t){HEART_CHARM, \
    (sfFloatRect){1470, 794, 870, 136}, (sfIntRect){0, 544, 870, 136}, \
    "assets/textures/shop_charms.png", true, false, -1, -1});
    return (shop);
}

game_object_t *setup_shop_sprites(void)
{
    game_object_t *shop = NULL;

    add_node_back(&shop, (coding_style_t){BACKGROUND, (sfFloatRect){960, \
    1080 / 2, 1920, 1080}, (sfIntRect){0, 0, 1920, 1080}, \
    "assets/textures/SHOP.png", false, false, -1, -1});
    add_node_back(&shop, (coding_style_t){GOLDS, (sfFloatRect){100, \
    100, 55, 57}, (sfIntRect){0, 0, 55, 57}, \
    "assets/textures/gold.png", false, false, -1, -1});
    add_node_back(&shop, (coding_style_t){BACK, (sfFloatRect){200, 920, \
    309, 70}, (sfIntRect){0, 210, 309, 70}, \
    "assets/textures/menu_options.png", true, false, -1, -1});
    add_node_back(&shop, (coding_style_t){LIFE_CHARM, \
    (sfFloatRect){1470, 250, 870, 136}, (sfIntRect){0, 0, 870, 136}, \
    "assets/textures/shop_charms.png", true, false, -1, -1});
    add_node_back(&shop, (coding_style_t){ATTACK_CHARM, \
    (sfFloatRect){1470, 386, 870, 136}, (sfIntRect){0, 136, 870, 136}, \
    "assets/textures/shop_charms.png", true, false, -1, -1});
    return (setup_shop_sprites_next(shop));
}