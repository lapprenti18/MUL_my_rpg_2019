/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** analyse_events.c
*/

#include "../include/my.h"

game_object_t *check_animated(game_object_t *knight)
{
    if (knight->rect.top == 0 || knight->rect.top == 127)
        knight->animated = false;
    else
        knight->animated = true;
    return (knight);
}

void analyse_events(all_t *store)
{
    game_object_t *copy = store->objects[PLAYING];

    for (; copy->type != KNIGHT; copy = copy->next);
    if (store->event.type == sfEvtClosed || \
    store->event.key.code == sfKeyEscape)
        sfRenderWindow_close(store->window);
    if (store->event.type == sfEvtMouseButtonPressed)
        manage_mouse_clicked(store);
    if (store->event.type == sfEvtMouseMoved)
        manage_mouse_moved(store);
    analyse_mana_bar(store);
    analyse_knight(store);
}