/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** set_structures_2.c
*/

#include "../include/my.h"

sfView *init_view(void)
{
    sfView *view = sfView_create();

    sfView_setSize(view, (sfVector2f){1920, 1080});
    sfView_setCenter(view, (sfVector2f){200, 500});
    return (view);
}

void set_structures_next(all_t *store)
{
    store->right_or_left = 0;
    store->view = init_view();
    store->view_pos = (sfVector2f){0, 0};
}