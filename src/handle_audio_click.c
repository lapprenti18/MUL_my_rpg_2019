/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** handle_audio_click.c
*/

#include "../include/my.h"

void update_musics_volume(all_t *store, sfVector2f rect_pos)
{
    for (int temp = 0; store->musics[temp]; temp += 1)
        sfMusic_setVolume(store->musics[temp], rect_pos.x / 10);
}

void update_master_volume(all_t *store, sfVector2f rect_pos)
{
    float vol = 0.0;

    for (int temp = 0; store->musics[temp]; temp += 1) {
        vol = sfMusic_getVolume(store->musics[temp]);
        if ((rect_pos.x / 100) != 0)
            sfMusic_setVolume(store->musics[temp], vol * (rect_pos.x / 100));
        else
            sfMusic_setVolume(store->musics[temp], 0);
    }
}

void handle_audio_click_next(all_t *store, game_object_t *copy)
{
    sfVector2f rect_pos = {0, 0};

    if (copy->type == BACK)
        store->scene = MENU_OPTIONS;
    for (int index = 2; index >= 0; index -= 1) {
        if (copy->type == RESET_DEFAULT)
            sfRectangleShape_setSize(store->rectangles[index], \
            (sfVector2f){160, 5});
        rect_pos = sfRectangleShape_getSize(store->rectangles[index]);
        if (index == 2)
            update_musics_volume(store, rect_pos);
        if (index == 0)
            update_master_volume(store, rect_pos);
    }
}

void handle_audio_click(all_t *store, game_object_t *copy, sfVector2i mouse)
{
    sfVector2f rect_pos = {0, 0};

    if (copy->type >= MASTER_VOLUME && copy->type <= MUSIC_VOLUME) {
        rect_pos = sfRectangleShape_getSize(store->rectangles[copy->type \
        - MASTER_VOLUME]);
        if (mouse.x >= copy->pos.x - (copy->length / 2) \
        && mouse.x <= copy->pos.x - (copy->length / 2) + 20 \
        && mouse.y >= copy->pos.y - (copy->height / 2) \
        && mouse.y <= copy->pos.y + (copy->height / 2) && rect_pos.x >= 10)
            sfRectangleShape_setSize(store->rectangles[copy->type - \
            MASTER_VOLUME], (sfVector2f){rect_pos.x - 10, rect_pos.y});
        if (mouse.x >= copy->pos.x + (copy->length / 2) - 20 \
        && mouse.x <= copy->pos.x + (copy->length / 2) \
        && mouse.y >= copy->pos.y - (copy->height / 2) \
        && mouse.y <= copy->pos.y + (copy->height / 2) && rect_pos.x <= 150)
            sfRectangleShape_setSize(store->rectangles[copy->type - \
            MASTER_VOLUME], (sfVector2f){rect_pos.x + 10, rect_pos.y});
    }
    handle_audio_click_next(store, copy);
}