/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** setup_functions.c
*/

#include "../include/my.h"

void move_rect(game_object_t *object, int offset, int size_max)
{
    object->rect.left += offset;
    if (object->rect.left > size_max)
        object->rect.left = 0;
    if (object->rect.left < 0)
        object->rect.left = size_max;
    sfSprite_setTextureRect(object->sprite, object->rect);
}

void change_pos(game_object_t *object, sfVector2f new_pos)
{
    object->pos.x = new_pos.x;
    object->pos.y = new_pos.y;
    sfSprite_setPosition(object->sprite, object->pos);
}