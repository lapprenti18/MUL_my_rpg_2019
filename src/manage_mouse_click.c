/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** manage_mouse_click.c
*/

#include "../include/my.h"

void manage_mouse_clicked(all_t *store)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(store->window);

    for (game_object_t *copy = store->objects[store->scene]; \
    copy; copy = copy->next) {
        if (mouse.x >= copy->pos.x - (copy->length / 2) \
        && mouse.x <= copy->pos.x + (copy->length / 2) \
        && mouse.y >= copy->pos.y - (copy->height / 2) \
        && mouse.y <= copy->pos.y + (copy->height / 2))
            store->scene = copy->on_click(store->scene, \
            copy->type, store->musics);
        if ((int)store->scene == -1) {
            sfRenderWindow_close(store->window);
            store->scene = 0;
            return;
        }
    }
}