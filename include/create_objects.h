/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_objects.h
*/

#ifndef CREATE_OBJECTS_H_
#define CREATE_OBJECTS_H_

#include "./my.h"

game_object_t *complete_node(SPRITES type, char *filepath, \
sfFloatRect pos, sfIntRect rect);
void add_node_back(game_object_t **nodes, coding_style_t coding);
game_object_t *setup_menu_sprites(void);
game_object_t **create_objects(void);

#endif /* CREATE_OBJECT_H */
