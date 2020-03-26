/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** setup_keyboard.c
*/

#include "../include/my.h"

game_object_t *setup_keyboard_next(game_object_t *key)
{
    add_node_back(&key, (coding_style_t){LEFT, (sfFloatRect){750, \
    499, 508, 33}, (sfIntRect){0, 99, 508, 33}, \
    "assets/textures/inputs.png", true, false, -1, -1});
    add_node_back(&key, (coding_style_t){RIGHT, (sfFloatRect){1258, \
    499, 508, 33}, (sfIntRect){0, 132, 508, 33}, \
    "assets/textures/inputs.png", true, false, -1, -1});
    add_node_back(&key, (coding_style_t){ATTACK, (sfFloatRect){750, \
    598, 508, 33}, (sfIntRect){0, 165, 508, 33}, \
    "assets/textures/inputs.png", true, false, -1, -1});
    add_node_back(&key, (coding_style_t){JUMP, (sfFloatRect){1258, \
    598, 508, 33}, (sfIntRect){0, 66, 508, 33}, \
    "assets/textures/inputs.png", true, false, -1, -1});
    add_node_back(&key, (coding_style_t){INVENTORY, (sfFloatRect){960, \
    697, 508, 33}, (sfIntRect){0, 198, 508, 33}, \
    "assets/textures/inputs.png", true, false, -1, -1});
    return (key);
}

game_object_t *setup_keyboard_sprites(void)
{
    game_object_t *key = NULL;

    add_node_back(&key, (coding_style_t){BACKGROUND, (sfFloatRect){960, 540, \
    1920, 1080}, (sfIntRect){0, 0, 1920, 1080}, "assets/textures/screen.png", \
    false, false, -1, -1});
    add_node_back(&key, (coding_style_t){KEY_SHAPE, (sfFloatRect){960, 240\
    , 708, 114}, (sfIntRect){0, 0, 708, 114}, "assets/textures/keyboard.png", \
    false, false, -1, -1});
    add_node_back(&key, (coding_style_t){UP, (sfFloatRect){750, \
    400, 508, 33}, (sfIntRect){0, 0, 508, 33}, \
    "assets/textures/inputs.png", true, false, -1, -1});
    add_node_back(&key, (coding_style_t){DOWN, (sfFloatRect){1258, \
    400, 508, 33}, (sfIntRect){0, 33, 508, 33}, \
    "assets/textures/inputs.png", true, false, -1, -1});
    add_node_back(&key, (coding_style_t){RESET_DEFAULT, (sfFloatRect){960, \
    850, 372, 28}, (sfIntRect){0, 0, 372, 28}, \
    "assets/textures/button_reset_default.png", true, false, -1, -1});
    add_node_back(&key, (coding_style_t){BACK, (sfFloatRect){960, 920, \
    309, 70}, (sfIntRect){0, 210, 309, 70}, \
    "assets/textures/menu_options.png", true, false, -1, -1});
    return (setup_keyboard_next(key));
}