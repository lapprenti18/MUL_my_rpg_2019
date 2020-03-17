/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** structures.h
*/

#ifndef STRUCTURES_H_
#define STRUCTURES_H_

#define WIDTH 1920
#define HEIGHT 1080

typedef enum
{
    MENU
} SCENE;

typedef struct all_s
{
    SCENE scene;
    sfRenderWindow *window;
    sfEvent event;
}all_t;

#endif /* STRUCTURES_H_ */