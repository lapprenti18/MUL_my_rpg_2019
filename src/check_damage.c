/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** check_damage.c
*/

#include "../include/my.h"

int check_touch(game_object_t *object, sfVector2f pos)
{
    if (object->pos.x - object->length / 2 <= pos.x && \
    object->pos.x + object->length / 2 >= pos.x && \
    object->pos.y - object->height / 2 <= pos.y && \
    object->pos.y + object->height / 2 >= pos.y)
        return (1);
    return (0);
}

int one_mob_only(game_object_t *ob, mob_t mob)
{
    for (int y = mob.pos.y + 35; y < mob.pos.y + 150; y += 1)
        for (int x = mob.pos.x + 35; x < mob.pos.x + 140; x += 1)
            if (check_touch(ob, (sfVector2f){x, y}))
                return (1);
    return (0);
}

void game_is_over(all_t *store, game_object_t *ob)
{
    store->knight_hp = 5;
    ob->change_pos(ob, (sfVector2f){200, 500});
    for (game_object_t *o = store->objects[PLAYING]; o; o = o->next)
        if (o->type == HEALTH) {
            o->animated = true;
            o->rect.left = 0;
            sfSprite_setTextureRect(o->sprite, o->rect);
        }
    store->index_maps = 0;
    store->change_texture = true;
    store->current = get_array("assets/collisions/first_screen.txt");
    store->mana_level = 1;
    store->nb_golds = 0;
    store->show_enter = false;
    store->show_enter_2 = false;
}

void update_hp(all_t *store, game_object_t *ob)
{
    store->no_damages = true;
    store->knight_hp -= 1;
    if (store->knight_hp == 0)
        return (game_is_over(store, ob));
    printf("%d\n", store->knight_hp);
    for (game_object_t *o = store->objects[PLAYING]; o; o = o->next)
        if (o->type == HEALTH && o->animated == true) {
            o->animated = false;
            o->rect.left = 306;
            sfSprite_setTextureRect(o->sprite, o->rect);
            return;
        }
}

void check_for_damage(all_t *store)
{
    game_object_t *ob = store->objects[PLAYING];

    for (; ob->type != KNIGHT; ob = ob->next);
    for (int index = 0; index < 10; index += 1) {
        if (store->mobs[index].alive == false)
            continue;
        if (one_mob_only(ob, store->mobs[index]))
            return (update_hp(store, ob));
    }
}