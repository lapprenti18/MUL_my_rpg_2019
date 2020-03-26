/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** handle_video_click.c
*/

#include "../include/my.h"

void update_video(all_t *store, game_object_t *copy)
{
    if (copy->type == ON_OFF_2)
        store->show_particules = (copy->rect.left == 0) ? true : false;
    if (copy->type == ON_OFF_1) {
        store->mode = (copy->rect.left == 0) ? sfFullscreen : sfResize;
        sfRenderWindow_destroy(store->window);
        store->window = create_window(store->fps, \
        store->mode, store->width, store->height);
    }
    if (copy->type == ON_OFF_3) {
        store->fps = (copy->rect.left == 0) ? 30: 300;
        sfRenderWindow_setFramerateLimit(store->window, store->fps);
    }
    if (copy->type == RES_CURSOR) {
        sfRenderWindow_destroy(store->window);
        store->width = (copy->rect.left == 0) ? 1920 : \
        (copy->rect.left == 150) ? 1600 : 1280;
        store->height = (copy->rect.left == 0) ? 1080 : \
        (copy->rect.left == 150) ? 900 : 720;
        store->window = create_window(store->fps, \
        store->mode, store->width, store->height);
    }
}

void handle_video_click(all_t *store, game_object_t *copy)
{
    game_object_t *temp = NULL;

    if (copy->type >= ON_OFF_1 && copy->type <= ON_OFF_3)
        copy->move_rect(copy, copy->length, copy->max_rect);
    if (copy->type == RES_CURSOR)
        copy->move_rect(copy, copy->length, copy->max_rect);
    if (copy->type == RESET_DEFAULT) {
        temp = store->objects[MENU_VIDEO];
        for (; temp; temp = temp->next) {
            if (temp->type == ON_OFF_1 || temp->type == ON_OFF_3)
                temp->rect.left = 50;
            if (temp->type == ON_OFF_2 \
            || temp->type == RES_CURSOR)
                temp->rect.left = 0;
            sfSprite_setTextureRect(temp->sprite, temp->rect);
            update_video(store, temp);
        }
        return;
    }
    update_video(store, copy);
    store->scene = (copy->type == BACK) ? MENU_OPTIONS : store->scene;
}