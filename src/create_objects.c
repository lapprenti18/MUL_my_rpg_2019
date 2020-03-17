/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_objects.c
*/

#include "../include/my.h"

game_object_t *complete_node(char *filepath, \
sfFloatRect pos, sfIntRect rect)
{
    game_object_t *new_node = my_malloc(sizeof(game_object_t));

    new_node->clock = sfClock_create();
    new_node->pos = (sfVector2f){pos.left, pos.top};
    new_node->length = (int)pos.width;
    new_node->height = (int)pos.height;
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
    sfSprite_setOrigin(new_node->sprite, (sfVector2f){new_node->length / 2, \
    new_node->height / 2});
    return (new_node);
}

void add_node_back(game_object_t **nodes, char *filepath, \
sfFloatRect pos, sfIntRect rect)
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

    add_node_back(&menu, "assets/textures/menu.png", \
    (sfFloatRect){960, 651, 344, 59}, (sfIntRect){0, 0, 344, 59});
    add_node_back(&menu, "assets/textures/menu.png", \
    (sfFloatRect){960, 710, 344, 59}, (sfIntRect){0, 59, 344, 59});
    add_node_back(&menu, "assets/textures/menu.png", \
    (sfFloatRect){960, 769, 344, 59}, (sfIntRect){0, 118, 344, 59});
    add_node_back(&menu, "assets/textures/menu.png", \
    (sfFloatRect){960, 828, 344, 59}, (sfIntRect){0, 177, 344, 59});
    add_node_back(&menu, "assets/textures/menu.png", \
    (sfFloatRect){960, 887, 344, 59}, (sfIntRect){0, 236, 344, 59});
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