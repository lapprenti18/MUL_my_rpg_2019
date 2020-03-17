/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** analyse_events.c
*/

#include "../include/my.h"

void analyse_events(all_t *store)
{
    if (store->event.type == sfEvtClosed || \
    store->event.key.code == sfKeyEscape)
        sfRenderWindow_close(store->window);
}