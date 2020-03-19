/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_scene.c
*/

#include "../include/my.h"

void draw_scene(all_t *store)
{
    for (game_object_t *temp = store->objects[store->scene]; \
    temp; temp = temp->next) {
        sfRenderWindow_drawSprite(store->window, temp->sprite, NULL);
        for (int index = 0; store->scene < PLAYING && \
        store->particules[index]; index += 1)
            sfRenderWindow_drawCircleShape(store->window, \
            store->particules[index]->shape, NULL);
    }
}