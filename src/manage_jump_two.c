/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** manage_jump.c
*/

#include "../include/my.h"

col_t array[6] =
{
    {0, "assets/collisions/first_screen.txt"},
    {1, "assets/collisions/second_screen.txt"},
    {2, "assets/collisions/third_screen.txt"},
    {3, "assets/collisions/four_screen.txt"},
    {4, "assets/collisions/five_screen.txt"},
    {5, "assets/collisions/six_screen.txt"}
};

void norm_change_screen_last(all_t *store, game_object_t *object)
{
    if (store->quest_status != 1) {
        store->index_maps -= 1;
        store->spawn = 2;
        object->change_pos(object, (sfVector2f){1900, object->pos.y});
        store->change_texture = true;
        store->current = get_array(array\
        [store->index_maps].filepath);
        add_mobs(store);
        store->texture_plan = sfTexture_createFromFile(\
        store->first_plan[store->index_maps], NULL);
        sfSprite_setTexture(store->sprite_plan, store->texture_plan, sfTrue);
    }
    return;
}

void norm_change_screen_next(all_t *store, game_object_t *object)
{
    if (object->pos.x <= 20) {
        store->index_maps -= 1;
        store->spawn = 2;
        object->change_pos(object, (sfVector2f){1900, object->pos.y});
        store->change_texture = true;
        store->current = get_array(array[store->index_maps].filepath);
        add_mobs(store);
        store->texture_plan = sfTexture_createFromFile(\
        store->first_plan[store->index_maps], NULL);
        sfSprite_setTexture(store->sprite_plan, store->texture_plan, sfTrue);
    }
    return;
}

void change_screen_four(all_t *store, game_object_t *object)
{
    store->index_maps -= 1;
    object->change_pos(object, (sfVector2f){960, 1000});
    store->change_texture = true;
    store->current = get_array(array[store->index_maps].filepath);
}

void change_screen_zero(all_t *store, game_object_t *object)
{
    if (object->pos.x <= 10) {
        object->change_pos(object, (sfVector2f){10, object->pos.y});
        store->change_texture = false;
    }
    if (object->pos.x >= 1900) {
        store->index_maps += 1;
        store->spawn = 1;
        object->change_pos(object, (sfVector2f){50, object->pos.y});
        store->change_texture = true;
        store->current = get_array(array[1].filepath);
        add_mobs(store);
        store->texture_plan = sfTexture_createFromFile(\
        store->first_plan[store->index_maps], NULL);
        sfSprite_setTexture(store->sprite_plan, store->texture_plan, sfTrue);
    }
}