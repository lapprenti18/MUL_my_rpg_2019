/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** manage_mouse_click.c
*/

#include "../include/my.h"

void handle_click(all_t *store, game_object_t *copy, sfVector2i mouse)
{
    if (store->scene == MENU_AUDIO)
        return (handle_audio_click(store, copy, mouse));
    if (store->scene == MENU)
        return (handle_menu_click(store, copy));
    if (store->scene == MENU_OPTIONS)
        return (handle_options_click(store, copy));
    if (store->scene == SAVES_SCREEN)
        return (handle_saves_click(store, copy));
    if (store->scene == MENU_VIDEO)
        return (handle_video_click(store, copy));
    if (store->scene == MENU_KEYBOARD)
        return (handle_keyboard_click(store, copy));
}

void manage_mouse_clicked(all_t *store)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(store->window);
    sfVector2f rect_pos;
    int temp_x = 0;

    for (game_object_t *copy = store->objects[store->scene]; \
    copy; copy = copy->next) {
        if (mouse.x >= copy->pos.x - (copy->length / 2) \
        && mouse.x <= copy->pos.x + (copy->length / 2) \
        && mouse.y >= copy->pos.y - (copy->height / 2) \
        && mouse.y <= copy->pos.y + (copy->height / 2))
            handle_click(store, copy, mouse);
        if (copy->type >= CURSOR_1 && copy->type <= CURSOR_3) {
            rect_pos = sfRectangleShape_getSize(store->\
            rectangles[copy->type - CURSOR_1]);
            temp_x = (store->width == 1920) ? 1045 : (store->width == 1600) ? 844 : 644;
            copy->change_pos(copy, (sfVector2f){rect_pos.x + \
            temp_x, copy->pos.y});
        }
    }
}