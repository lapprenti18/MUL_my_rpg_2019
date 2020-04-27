/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** setup_scenes.c
*/

#include "../include/my.h"

game_object_t *setup_audio_sprites_next(game_object_t *audio)
{
    add_node_back(&audio, (coding_style_t){RESET_DEFAULT, (sfFloatRect){960, \
    850, 372, 28}, (sfIntRect){0, 0, 372, 28}, \
    "assets/textures/button_reset_default.png", true, false, -1, -1});
    add_node_back(&audio, (coding_style_t){CURSOR_1, (sfFloatRect){1205, \
    360, 21, 19}, (sfIntRect){0, 0, 21, 19}, \
    "assets/textures/petite_fleche.png", false, false, -1, -1});
    add_node_back(&audio, (coding_style_t){CURSOR_2, (sfFloatRect){1205, \
    420, 21, 19}, (sfIntRect){0, 0, 21, 19}, \
    "assets/textures/petite_fleche.png", false, false, -1, -1});
    add_node_back(&audio, (coding_style_t){CURSOR_3, (sfFloatRect){1205, \
    480, 21, 19}, (sfIntRect){0, 0, 21, 19}, \
    "assets/textures/petite_fleche.png", false, false, -1, -1});
    return (audio);
}

game_object_t *setup_audio_sprites(void)
{
    game_object_t *audio  = NULL;

    add_node_back(&audio, (coding_style_t){BACKGROUND, (sfFloatRect){960, \
    1080 / 2, 1920, 1080}, (sfIntRect){0, 0, 1920, 1080}, \
    "assets/textures/screen.png", false, false, -1, -1});
    add_node_back(&audio, (coding_style_t){AUDIO_SHAPE, \
    (sfFloatRect){960, 200, 722, 118}, (sfIntRect){0, 0, 722, 118}, \
    "assets/textures/title_audio.png", false, false, -1, -1});
    add_node_back(&audio, (coding_style_t){MASTER_VOLUME, \
    (sfFloatRect){960, 400, 720, 49}, (sfIntRect){0, 0, 720, 49}, \
    "assets/textures/params_volume.png", true, false, -1, -1});
    add_node_back(&audio, (coding_style_t){SOUND_VOLUME, \
    (sfFloatRect){960, 449, 720, 49}, (sfIntRect){0, 49, 720, 49}, \
    "assets/textures/params_volume.png", true, false, -1, -1});
    add_node_back(&audio, (coding_style_t){MUSIC_VOLUME, \
    (sfFloatRect){960, 498, 720, 49}, (sfIntRect){0, 98, 720, 49}, \
    "assets/textures/params_volume.png", true, false, -1, -1});
    add_node_back(&audio, (coding_style_t){BACK, (sfFloatRect){960, 920, \
    309, 70}, (sfIntRect){0, 210, 309, 70}, \
    "assets/textures/menu_options.png", true, false, -1, -1});
    return (setup_audio_sprites_next(audio));
}

game_object_t *setup_playing_sprites(void)
{
    int x = 325;
    game_object_t *playing  = NULL;

    add_node_back(&playing, (coding_style_t){BACKGROUND, (sfFloatRect){960, \
    525, 1920, 1080}, (sfIntRect){0, 0, 1920, 1080}, \
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
    "assets/textures/Knight_final-min.png", false, false, 1157, 0.2});
    return (playing);
}

game_object_t *setup_options_sprites(void)
{
    game_object_t *options  = NULL;

    add_node_back(&options, (coding_style_t){BACKGROUND, (sfFloatRect){960, \
    1080 / 2, 1920, 1080}, (sfIntRect){0, 0, 1920, 1080}, \
    "assets/textures/screen.png", false, false, -1, -1});
    add_node_back(&options, (coding_style_t){OPTION_SHAPE, \
    (sfFloatRect){960, 383, 726, 127}, (sfIntRect){0, 0, 726, 127}, \
    "assets/textures/option_and_shape.png", false, false, -1, -1});
    add_node_back(&options, (coding_style_t){AUDIO, (sfFloatRect){960, 510, \
    309, 70}, (sfIntRect){0, 0, 309, 70}, "assets/textures/menu_options.png", \
    true, false, -1, -1});
    add_node_back(&options, (coding_style_t){VIDEO, (sfFloatRect){960, 580, 309\
    , 70}, (sfIntRect){0, 70, 309, 70}, "assets/textures/menu_options.png", \
    true, false, -1, -1});
    add_node_back(&options, (coding_style_t){KEYBOARD, (sfFloatRect){960, \
    650, 309, 70}, (sfIntRect){0, 140, 309, 70}, \
    "assets/textures/menu_options.png", true, false, -1, -1});
    add_node_back(&options, (coding_style_t){BACK, (sfFloatRect){960, 920, \
    309, 70}, (sfIntRect){0, 210, 309, 70}, \
    "assets/textures/menu_options.png", true, false, -1, -1});
    return (options);
}

game_object_t *setup_menu_sprites(game_object_t *menu)
{
    add_node_back(&menu, (coding_style_t){BACKGROUND, (sfFloatRect){960, 540, \
    1920, 1080}, (sfIntRect){0, 0, 1920, 1080}, "assets/textures/screen.png", \
    false, false, -1, -1});
    add_node_back(&menu, (coding_style_t){PLAY, (sfFloatRect){960, 651, \
    344, 59}, (sfIntRect){0, 0, 344, 59}, "assets/textures/menu.png", true, \
    false, -1, -1});
    add_node_back(&menu, (coding_style_t){OPTIONS, (sfFloatRect){960, 710, \
    344, 59}, (sfIntRect){0, 59, 344, 59}, "assets/textures/menu.png", true, \
    false, -1, -1});
    add_node_back(&menu, (coding_style_t){ACHIEVEMENTS, (sfFloatRect){960, \
    769, 344, 59}, (sfIntRect){0, 118, 344, 59}, "assets/textures/menu.png", \
    true, false, -1, -1});
    add_node_back(&menu, (coding_style_t){EXTRAS, (sfFloatRect){960, 828, \
    344, 59}, (sfIntRect){0, 177, 344, 59}, "assets/textures/menu.png", true, \
    false, -1, -1});
    add_node_back(&menu, (coding_style_t){QUIT, (sfFloatRect){960, 887, \
    344, 59}, (sfIntRect){0, 236, 344, 59}, "assets/textures/menu.png", true, \
    false, -1, -1});
    add_node_back(&menu, (coding_style_t){NAME, (sfFloatRect){960, 300, \
    1206, 457}, (sfIntRect){0, 0, 1206, 457}, \
    "assets/textures/game_name.png", false, false, -1, -1});
    return (menu);
}