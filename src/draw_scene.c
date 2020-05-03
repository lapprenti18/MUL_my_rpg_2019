/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_scene.c
*/

#include "../include/my.h"

void check_for_enter(all_t *store, game_object_t *temp)
{
    if (store->scene == PLAYING && temp->type == KNIGHT \
    && store->index_maps == 1) {
        if (store->nb_jump != 0 && temp->pos.x >= 155 && temp->pos.x <= 285)
            store->show_enter_2 = true;
        else
            store->show_enter_2 = false;
    }
    if (store->scene == PLAYING && temp->type == ENTER_2 \
    && store->show_enter_2 == false)
        return;
    if (temp->type == SWORD_EFFECT && store->show_sword == false)
        return;
    sfRenderWindow_drawSprite(store->window, temp->sprite, NULL);
}

void check_for_charms(all_t *store, game_object_t *temp)
{
    if (store->scene == INVENTORY && temp->type >= LIFE_CHARM && \
    !store->buys[temp->type - LIFE_CHARM])
        return;
    if (store->scene == SHOP && temp->type >= LIFE_CHARM && \
    store->buys[temp->type - LIFE_CHARM])
        return;
    if (store->scene == PLAYING && temp->type == KNIGHT \
    && store->index_maps == 1) {
        if (store->nb_jump != 0 && temp->pos.x >= 975 && temp->pos.x <= 1050)
            store->show_enter = true;
        else
            store->show_enter = false;
    }
    if (store->scene == PLAYING && temp->type == ENTER \
    && store->show_enter == false)
        return;
    check_for_enter(store, temp);
}

void draw_single_sprite(all_t *store, game_object_t *temp)
{
    if (temp->type == BACKGROUND) {
        if (store->scene == PLAYING && store->change_texture)
            sfSprite_setTexture(temp->sprite, \
            store->textures[store->index_maps], sfTrue);
        sfRenderWindow_drawSprite(store->window, temp->sprite, NULL);
        sfText_setString(store->golds, my_int_to_ascii(store->nb_golds));
        if (store->scene == PLAYING) {
            sfText_setPosition(store->golds, (sfVector2f){1750, 75});
            sfRenderWindow_drawText(store->window, store->golds, NULL);
        }
        if (store->scene == SHOP) {
            sfText_setPosition(store->golds, (sfVector2f){140, 75});
            sfRenderWindow_drawText(store->window, store->golds, NULL);
        }
        return;
    }
    if (draw_sprites_quest(store, temp) == 1)
        return;
    check_for_charms(store, temp);
}

void draw_other(all_t *store)
{
    for (int index = 0; store->scene == MENU_AUDIO && \
        store->rectangles[index]; index += 1)
        sfRenderWindow_drawRectangleShape(store->window, \
        store->rectangles[index], NULL);
    for (int index = 0; store->scene == MENU_KEYBOARD && \
    store->keys_text[index]; index += 1)
        sfRenderWindow_drawText(store->window, \
        store->keys_text[index], NULL);
    for (int index = 0; store->particules[index] \
    && store->show_particules; index += 1)
        sfRenderWindow_drawCircleShape(store->window, \
        store->particules[index]->shape, NULL);
    for (int index = 0; store->scene == PLAYING && index < 10; index += 1)
        if (store->mobs[index].alive == true)
            sfRenderWindow_drawSprite(store->window, \
            store->mobs[index].sprite, NULL);
    if (store->scene == PLAYING)
        sfRenderWindow_drawSprite(store->window, store->sprite_plan, NULL);
}

void draw_scene(all_t *store)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(store->window);

    for (game_object_t *temp = store->objects[store->scene]; \
    temp; temp = temp->next) {
        update(store, temp, mouse);
        draw_single_sprite(store, temp);
    }
    draw_other(store);
}