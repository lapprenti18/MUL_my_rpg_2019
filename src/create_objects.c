/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_objects.c
*/

#include "../include/my.h"

game_object_t *complete_node(char *filepath, \
sfVector2f pos, sfIntRect rect)
{
    game_object_t *new_node = my_malloc(sizeof(game_object_t));

    new_node->clock = sfClock_create();
    new_node->pos = pos;
    new_node->rect = rect;
    new_node->seconds = 0.0;
    new_node->sprite = sfSprite_create();
    new_node->texture = sfTexture_createFromFile(filepath, NULL);
    new_node->change_pos = change_pos;
    new_node->move_rect = move_rect;
    new_node->next = NULL;
    sfSprite_setTexture(new_node->sprite, new_node->texture, sfTrue);
    sfSprite_setTextureRect(new_node->sprite, new_node->rect);
    sfSprite_setPosition(new_node->sprite, new_node->pos);
    return (new_node);
}

void add_node_back(game_object_t **nodes, char *filepath, \
sfVector2f pos, sfIntRect rect)
{
    game_object_t *new_node = complete_node(filepath, pos, rect);
    game_object_t *copy = *nodes;

    if (!(*nodes)) {
        *nodes = new_node;
        return;
    }
    while (copy->next)
        copy = copy->next;
    copy->next = new_node;
}

game_object_t *setup_menu_sprites(void)
{
    game_object_t *menu  = NULL;

    add_node_back(&menu, "assets/sprites/menu_background.png", \
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
    return (menu);
}

game_object_t **create_objects(void)
{
    game_object_t **objects = my_malloc(sizeof(game_object_t) * (TOTAL + 1));

    if (!objects)
        return (NULL);
    objects[MENU] = setup_menu_sprites();
    objects[TOTAL] = NULL;
    return (objects);
}