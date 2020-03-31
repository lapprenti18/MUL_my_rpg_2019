/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_scene.c
*/

#include "../include/my.h"

void draw_scene(all_t *store)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(store->window);

    for (game_object_t *temp = store->objects[store->scene]; \
    temp; temp = temp->next) {
        update(store, temp, mouse);
        sfRenderWindow_drawSprite(store->window, temp->sprite, NULL);
        for (int index = 0; store->scene == MENU_AUDIO && \
        store->rectangles[index]; index += 1)
            sfRenderWindow_drawRectangleShape(store->window, \
            store->rectangles[index], NULL);
        for (int index = 0; store->scene == MENU_KEYBOARD && \
        store->keys_text[index]; index += 1)
            sfRenderWindow_drawText(store->window, store->keys_text[index], NULL);
        for (int index = 0; store->scene < PLAYING && \
        store->particules[index] && store->show_particules; index += 1)
            sfRenderWindow_drawCircleShape(store->window, \
            store->particules[index]->shape, NULL);
    }
}