/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** setup_functions.c
*/

#include "../include/my.h"

int manage_click(SCENE scene, SPRITES type, sfMusic **musics)
{
    if (scene == MENU_AUDIO)
        if (type == BACK)
            return (MENU_OPTIONS);
    if (scene == MENU) {
        if (type == OPTIONS)
            return (MENU_OPTIONS);
        if (type == PLAY) {
            sfMusic_pause(musics[MENU]);
            sfMusic_play(musics[PLAYING]);
            return (PLAYING);
        }
        if (type == QUIT)
            return (-1);
    }
    if (scene == MENU_OPTIONS) {
        if (type == BACK)
            return (MENU);
        if (type == AUDIO)
            return (MENU_AUDIO);
    }
    return (scene);
}

void move_rect(game_object_t *object, int offset, int size_max)
{
    object->rect.left += offset;
    if (object->rect.left > size_max)
        object->rect.left = 0;
    sfSprite_setTextureRect(object->sprite, object->rect);
}

void change_pos(game_object_t *object, sfVector2f new_pos)
{
    object->pos.x = new_pos.x;
    object->pos.y = new_pos.y;
    sfSprite_setPosition(object->sprite, object->pos);
}