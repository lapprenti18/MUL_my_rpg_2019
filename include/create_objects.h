/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_objects.h
*/

#ifndef CREATE_OBJECTS_H_
#define CREATE_OBJECTS_H_

#include "./my.h"

game_object_t *complete_node(coding_style_t coding);
void add_node_back(game_object_t **nodes, coding_style_t coding);
game_object_t **create_objects(sfRenderWindow *window);

#endif /* CREATE_OBJECT_H */
