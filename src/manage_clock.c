/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** manage_clock.c
*/

#include "../include/my.h"

void manage_particules_clock(all_t *store, game_object_t *copy)
{
    copy->time = sfClock_getElapsedTime(copy->clock);
    copy->seconds = copy->time.microseconds / 1000000.0;
    if (copy->seconds > 0.05) {
        for (int index = 0; store->particules[index]; index += 1) {
            store->particules[index]->position.y -= \
            store->particules[index]->speed;
            if (store->particules[index]->position.y < \
            -store->particules[index]->radius)
                store->particules[index]->position.y += HEIGHT;
            sfCircleShape_setPosition(store->particules[index]->shape, \
            store->particules[index]->position);
        }
        sfClock_restart(copy->clock);
    }
}

void manage_clock(game_object_t *objects)
{
    if (objects->animated) {
        objects->time = sfClock_getElapsedTime(objects->clock);
        objects->seconds = objects->time.microseconds / 1000000.0;
        if (objects->type == MANA_BAR && objects->rect.left >= \
        687 && objects->rect.top == 0)
            return;
        if (objects->seconds > objects->timing) {
            objects->move_rect(objects, objects->length, objects->max_rect);
            sfClock_restart(objects->clock);
        }
    }
}

void refresh_no_damages(all_t *store, game_object_t *object)
{
    object->time = sfClock_getElapsedTime(object->clock);
    object->seconds = object->time.microseconds / 1000000.0;
    if (object->seconds > 3) {
        sfClock_restart(object->clock);
        store->no_damages = false;
    } else
        store->no_damages = true;
}

void manage_all_clock(all_t *store)
{
    for (game_object_t *copy = store->objects[store->scene]; copy; \
    copy = copy->next) {
        if (copy->type == BACKGROUND)
            manage_particules_clock(store, copy);
        if (copy->type == ENTER && store->no_damages == true)
            refresh_no_damages(store, copy);
        copy->manage_clock(copy);
    }
}