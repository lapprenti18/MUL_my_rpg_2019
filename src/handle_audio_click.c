/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** handle_audio_click.c
*/

#include "../include/my.h"

void handle_audio_click_next(all_t *store, game_object_t *copy)
{
    if (copy->type == BACK)
        store->scene = MENU_OPTIONS;
    if (copy->type == RESET_DEFAULT) {
        for (int index = 0; store->rectangles[index]; index += 1)
            sfRectangleShape_setSize(store->rectangles[index], \
            (sfVector2f){160, 5});
    }
}

void handle_audio_click(all_t *store, game_object_t *copy, sfVector2i mouse)
{
    sfVector2f rect_pos = {0, 0};

    if (copy->type >= MASTER_VOLUME && copy->type <= MUSIC_VOLUME) {
        rect_pos = sfRectangleShape_getSize(store->rectangles[copy->type \
        - 12]);
        if (mouse.x >= copy->pos.x - (copy->length / 2) \
        && mouse.x <= copy->pos.x - (copy->length / 2) + 20 \
        && mouse.y >= copy->pos.y - (copy->height / 2) \
        && mouse.y <= copy->pos.y + (copy->height / 2) && rect_pos.x >= 10)
            sfRectangleShape_setSize(store->rectangles[copy->type - 12], \
            (sfVector2f){rect_pos.x - 10, rect_pos.y});
        if (mouse.x >= copy->pos.x + (copy->length / 2) - 20 \
        && mouse.x <= copy->pos.x + (copy->length / 2) \
        && mouse.y >= copy->pos.y - (copy->height / 2) \
        && mouse.y <= copy->pos.y + (copy->height / 2) && rect_pos.x <= 150)
            sfRectangleShape_setSize(store->rectangles[copy->type - 12], \
            (sfVector2f){rect_pos.x + 10, rect_pos.y});
    }
    handle_audio_click_next(store, copy);
}