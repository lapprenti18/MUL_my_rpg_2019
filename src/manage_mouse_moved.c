/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** manage_mouse_moved.c
*/

#include "../include/my.h"

void manage_moved_on_options(all_t *store)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(store->window);

    for (game_object_t *copy = store->objects[MENU_OPTIONS]; \
    copy; copy = copy->next) {
        if (mouse.x >= copy->pos.x - (copy->length / 2) \
        && mouse.x <= copy->pos.x + (copy->length / 2) \
        && mouse.y >= copy->pos.y - (copy->height / 2) \
        && mouse.y <= copy->pos.y + (copy->height / 2) \
        && copy->type != OPTION_SHAPE && copy->type != BACKGROUND) {
            copy->rect.left = 309;
        } else
            copy->rect.left = 0;
        sfSprite_setTextureRect(copy->sprite, copy->rect);
    }
}

void manage_moved_on_menu(all_t *store)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(store->window);

    for (game_object_t *copy = store->objects[MENU]; copy; copy = copy->next) {
        if (mouse.x >= copy->pos.x - (copy->length / 2) \
        && mouse.x <= copy->pos.x + (copy->length / 2) \
        && mouse.y >= copy->pos.y - (copy->height / 2) \
        && mouse.y <= copy->pos.y + (copy->height / 2) \
        && copy->type != BACKGROUND) {
            copy->rect.left = 344;
        } else
            copy->rect.left = 0;
        sfSprite_setTextureRect(copy->sprite, copy->rect);
    }
}

void manage_mouse_moved(all_t *store)
{
    if (store->scene == MENU)
        manage_moved_on_menu(store);
    if (store->scene == MENU_OPTIONS)
        manage_moved_on_options(store);
}