/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** draw_quest.c
*/

#include "../include/my.h"

int draw_sprites_quest(all_t *store, game_object_t *temp)
{
    if (store->scene == PLAYING && store->quest_status != 0 && \
    temp->type == QUEST_BEGIN)
        return (1);
    if ((store->scene == QUEST && store->show_quest == false \
    && temp->type == QUEST_BOX) || (store->scene == PLAYING && \
    store->quest_status != 1 && temp->type == LITTLE_QUEST))
        return (1);
    if (store->scene == PLAYING && store->quest_status != 2 && \
    temp->type == QUEST_END)
        return (1);
    if (store->scene == QUEST && store->quest_status != 2 && \
    temp->type == QUEST_BOX_END)
        return (1);
    return (0);
}