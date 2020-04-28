/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** analyse_events.c
*/

#include "../include/my.h"

void check_animated(game_object_t *knight)
{
    if (knight->rect.top == 0 || knight->rect.top == 127)
        knight->animated = false;
    else
        knight->animated = true;
}

void analyse_events(all_t *store)
{
    if (store->event.type == sfEvtClosed || \
    store->event.key.code == sfKeyEscape)
        sfRenderWindow_close(store->window);
    if (store->event.type == sfEvtKeyPressed)
        manage_key_pressed(store, 1);
    handle_keyboard_click(store, NULL);
    if (store->event.type == sfEvtMouseButtonPressed)
        manage_mouse_clicked(store);
    if (store->event.type == sfEvtMouseMoved)
        manage_mouse_moved(store);
}