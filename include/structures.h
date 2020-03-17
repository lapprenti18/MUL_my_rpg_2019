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
    PLAY,
    OPTIONS,
    ACHIEVEMENTS,
    EXTRAS,
    QUIT,
    OPTION_SHAPE,
    AUDIO,
    VIDEO,
    KEYBOARD,
    MANA_BAR,
    BACK
} SPRITES;

typedef struct game_object_s
{
    SPRITES type;
    sfSprite* sprite;
    sfTexture* texture;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    float seconds;
    int length;
    int height;
    void (*move_rect)(struct game_object_s *, int, int);
    void (*change_pos)(struct game_object_s *, sfVector2f);
    struct game_object_s *next;
} game_object_t;

typedef enum
{
    MENU,
    MENU_OPTIONS,
    PLAYING,
    TOTAL
} SCENE;

typedef struct all_s
{
    SCENE scene;
    sfRenderWindow *window;
    sfEvent event;
    game_object_t **objects;
}all_t;

#endif /* STRUCTURES_H_ */