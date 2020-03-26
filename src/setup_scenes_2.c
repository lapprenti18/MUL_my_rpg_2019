/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** setup_scenes_2.c
*/

#include "../include/my.h"

game_object_t *setup_video_next(game_object_t *video)
{
    add_node_back(&video, (coding_style_t){BACK, (sfFloatRect){960, 920, \
    309, 70}, (sfIntRect){0, 210, 309, 70}, \
    "assets/textures/menu_options.png", true, false, -1, -1});
    add_node_back(&video, (coding_style_t){RESET_DEFAULT, (sfFloatRect){960, \
    850, 372, 28}, (sfIntRect){0, 0, 372, 28}, \
    "assets/textures/button_reset_default.png", true, false, -1, -1});
    add_node_back(&video, (coding_style_t){ON_OFF_1, (sfFloatRect){1305, \
    462, 50, 20}, (sfIntRect){50, 0, 50, 20}, \
    "assets/textures/on_off.png", false, false, 50, -1});
    add_node_back(&video, (coding_style_t){ON_OFF_2, (sfFloatRect){1305, \
    535, 50, 20}, (sfIntRect){0, 0, 50, 20}, \
    "assets/textures/on_off.png", false, false, 50, -1});
    add_node_back(&video, (coding_style_t){ON_OFF_3, (sfFloatRect){1305, \
    610, 50, 20}, (sfIntRect){50, 0, 50, 20}, \
    "assets/textures/on_off.png", false, false, 50, -1});
    add_node_back(&video, (coding_style_t){RES_CURSOR, (sfFloatRect){1255, \
    388, 150, 20}, (sfIntRect){0, 0, 150, 20}, \
    "assets/textures/resolutions.png", false, false, 300, -1});
    return (video);
}

game_object_t *setup_video_sprites(void)
{
    game_object_t *video = NULL;

    add_node_back(&video, (coding_style_t){BACKGROUND, (sfFloatRect){960, 540, \
    1920, 1080}, (sfIntRect){0, 0, 1920, 1080}, "assets/textures/screen.png", \
    false, false, -1, -1});
    add_node_back(&video, (coding_style_t){VIDEO_SHAPE, (sfFloatRect){960, 240\
    , 724, 114}, (sfIntRect){0, 0, 724, 114}, "assets/textures/video.png", \
    false, false, -1, -1});
    add_node_back(&video, (coding_style_t){RESOLUTION, (sfFloatRect){960, 400\
    , 840, 63}, (sfIntRect){0, 0, 840, 63}, "assets/textures/menu_video.png", \
    true, false, -1, -1});
    add_node_back(&video, (coding_style_t){FULL_SCREEN, (sfFloatRect)\
    {960, 463, 840, 63}, (sfIntRect){0, 63, 840, 63}, \
    "assets/textures/menu_video.png", true, false, -1, -1});
    add_node_back(&video, (coding_style_t){PARTICULES, (sfFloatRect){960, 526, \
    840, 63}, (sfIntRect){0, 126, 840, 63}, "assets/textures/menu_video.png", \
    true, false, -1, -1});
    add_node_back(&video, (coding_style_t){FRAME_RATE, (sfFloatRect){960, 589, \
    840, 63}, (sfIntRect){0, 189, 840, 63}, "assets/textures/menu_video.png", \
    true, false, -1, -1});
    return (setup_video_next(video));
}

game_object_t *setup_saves_next(game_object_t *save)
{
    add_node_back(&save, (coding_style_t){CLEAR_1, (sfFloatRect){1600, 350, \
    342, 35}, (sfIntRect){0, 0, 342, 35}, \
    "assets/textures/clear_save.png", true, false, -1, -1});
    add_node_back(&save, (coding_style_t){CLEAR_2, (sfFloatRect){1600, 520, \
    342, 35}, (sfIntRect){0, 0, 342, 35}, \
    "assets/textures/clear_save.png", true, false, -1, -1});
    add_node_back(&save, (coding_style_t){CLEAR_3, (sfFloatRect){1600, 680, \
    342, 35}, (sfIntRect){0, 0, 342, 35}, \
    "assets/textures/clear_save.png", true, false, -1, -1});
    add_node_back(&save, (coding_style_t){CLEAR_4, (sfFloatRect){1600, 840, \
    342, 35}, (sfIntRect){0, 0, 342, 35}, \
    "assets/textures/clear_save.png", true, false, -1, -1});
    add_node_back(&save, (coding_style_t){BACK, (sfFloatRect){960, 920, \
    309, 70}, (sfIntRect){0, 210, 309, 70}, \
    "assets/textures/menu_options.png", true, false, -1, -1});
    return (save);
}

game_object_t *setup_saves_sprites(void)
{
    game_object_t *save = NULL;

    add_node_back(&save, (coding_style_t){BACKGROUND, (sfFloatRect){960, 540, \
    1920, 1080}, (sfIntRect){0, 0, 1920, 1080}, "assets/textures/screen.png", \
    false, false, -1, -1});
    add_node_back(&save, (coding_style_t){PROFILE, (sfFloatRect){960, 140, \
    712, 115}, (sfIntRect){0, 0, 712, 115}, \
    "assets/textures/select_profile.png", false, false, -1, -1});
    add_node_back(&save, (coding_style_t){SAVE_1, (sfFloatRect){850, 350, \
    1172, 155}, (sfIntRect){0, 0, 1172, 147}, \
    "assets/textures/select_save.png", true, false, -1, -1});
    add_node_back(&save, (coding_style_t){SAVE_2, (sfFloatRect){850, 505, \
    1172, 155}, (sfIntRect){0, 155, 1172, 147}, \
    "assets/textures/select_save.png", true, false, -1, -1});
    add_node_back(&save, (coding_style_t){SAVE_3, (sfFloatRect){850, 660, \
    1172, 155}, (sfIntRect){0, 310, 1172, 147}, \
    "assets/textures/select_save.png", true, false, -1, -1});
    add_node_back(&save, (coding_style_t){SAVE_4, (sfFloatRect){850, 815, \
    1172, 155}, (sfIntRect){0, 465, 1172, 147}, \
    "assets/textures/select_save.png", true, false, -1, -1});
    return (setup_saves_next(save));
}