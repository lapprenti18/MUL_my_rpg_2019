/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** loop_game.c
*/

#include "../include/my.h"

void update_view_next(all_t *store, game_object_t *ob, game_object_t *copy)
{
    if (ob->type == KNIGHT) {
        if (ob->pos.x <= 200 || 1720 <= ob->pos.x * 1.5)
            copy->get_viewed = false;
        else {
            copy->get_viewed = true;
            store->view_pos = (sfVector2f){ob->pos.x - \
            store->width / 2, ob->pos.y - store->height / 2};
            sfView_reset(store->view, (sfFloatRect){store->view_pos.x, \
            store->view_pos.y, store->width, store->height});
            sfRenderWindow_setView(store->window, store->view);
            return;
        }
    }
}

void update_view(all_t *store)
{
    game_object_t *ob = store->objects[PLAYING];
    game_object_t *copy = store->objects[PLAYING];

    if (store->scene == PLAYING)
        for (; ob; ob = ob->next)
            update_view_next(store, ob, copy);
}

void loop_game(all_t *store)
{
    sfMusic_play(store->musics[MENU]);
    while (sfRenderWindow_isOpen(store->window)) {
        sfRenderWindow_clear(store->window, sfCyan);
        while (sfRenderWindow_pollEvent(store->window, &store->event))
            analyse_events(store);
        manage_all_clock(store);
        update_jump(store);
        draw_scene(store);
        update_view(store);
        sfRenderWindow_display(store->window);
    }
}