/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** handle_pause_click.c
*/

#include "../include/my.h"

void reset_struct(all_t *store)
{
    write_in_file(store);
    store->nb_golds = 0;
    store->index_maps = 0;
    store->current = get_array("assets/collisions/first_screen.txt");
    store->change_texture = true;
    for (int i = 0; i < 5; i += 1)
        store->buys[i] = false;
    for (game_object_t *obj = store->objects[PLAYING]; obj; obj = obj->next) {
        if (obj->type == KNIGHT)
            obj->change_pos(obj, (sfVector2f){200, 500});
        if (obj->type == HEALTH) {
            obj->rect.left = 0;
            obj->animated = true;
            sfSprite_setTextureRect(obj->sprite, obj->rect);
        }
    }
    store->show_quest = true;
    store->quest_status = 0;
    store->knight_hp = 5;
    store->show_enter = false;
    store->show_enter_2 = false;
}

void handle_pause_click(all_t *store, game_object_t *copy)
{
    if (copy->type == PAUSE_CONTINUE) {
        store->show_particules = false;
        store->scene = PLAYING;
        return;
    }
    if (copy->type == PAUSE_OPTIONS) {
        store->scene = MENU_OPTIONS;
        reset_struct(store);
    }
    if (copy->type == PAUSE_QUIT) {
        store->scene = MENU;
        reset_struct(store);
    }
}