/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** manage_mouse_click.c
*/

#include "../include/my.h"

void manage_click_on_audio(all_t *store)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(store->window);

    for (game_object_t *copy = store->objects[MENU_AUDIO]; \
    copy; copy = copy->next) {
        if (mouse.x >= copy->pos.x - (copy->length / 2) \
        && mouse.x <= copy->pos.x + (copy->length / 2) \
        && mouse.y >= copy->pos.y - (copy->height / 2) \
        && mouse.y <= copy->pos.y + (copy->height / 2) \
        && copy->type != AUDIO_SHAPE && copy->type != BACKGROUND) {
            if (copy->type == BACK)
                store->scene = MENU_OPTIONS;
        }
    }
}

void manage_click_on_options(all_t *store)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(store->window);

    for (game_object_t *copy = store->objects[MENU_OPTIONS]; \
    copy; copy = copy->next) {
        if (mouse.x >= copy->pos.x - (copy->length / 2) \
        && mouse.x <= copy->pos.x + (copy->length / 2) \
        && mouse.y >= copy->pos.y - (copy->height / 2) \
        && mouse.y <= copy->pos.y + (copy->height / 2) \
        && copy->type != BACKGROUND) {
            if (copy->type == BACK)
                store->scene = MENU;
            if (copy->type == AUDIO)
                store->scene = MENU_AUDIO;
        }
    }
}

void manage_click_on_menu(all_t *store)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(store->window);

    for (game_object_t *copy = store->objects[MENU]; copy; copy = copy->next) {
        if (mouse.x >= copy->pos.x - (copy->length / 2) \
        && mouse.x <= copy->pos.x + (copy->length / 2) \
        && mouse.y >= copy->pos.y - (copy->height / 2) \
        && mouse.y <= copy->pos.y + (copy->height / 2) \
        && copy->type != BACKGROUND) {
            if (copy->type == QUIT)
                sfRenderWindow_close(store->window);
            if (copy->type == OPTIONS)
                store->scene = MENU_OPTIONS;
            if (copy->type == PLAY) {
                sfMusic_pause(store->musics[MENU]);
                store->scene = PLAYING;
                sfMusic_play(store->musics[PLAYING]);
            }
        }
    }
}

void manage_mouse_clicked(all_t *store)
{
    if (store->scene == MENU)
        return (manage_click_on_menu(store));
    if (store->scene == MENU_OPTIONS)
        return (manage_click_on_options(store));
    if (store->scene == MENU_AUDIO)
        return (manage_click_on_audio(store));
}