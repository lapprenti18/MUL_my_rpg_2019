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
#define GRAV 9.8

typedef enum
{
    BACKGROUND,
    CURSEUR,
    NAME,
    PLAY,
    OPTIONS,
    ACHIEVEMENTS,
    EXTRAS,
    QUIT,
    OPTION_SHAPE,
    AUDIO,
    VIDEO,
    KEYBOARD,
    AUDIO_SHAPE,
    MASTER_VOLUME,
    SOUND_VOLUME,
    MUSIC_VOLUME,
    CURSOR_1,
    CURSOR_2,
    CURSOR_3,
    RESET_DEFAULT,
    VIDEO_SHAPE,
    RESOLUTION,
    FULL_SCREEN,
    PARTICULES,
    FRAME_RATE,
    ON_OFF_1,
    ON_OFF_2,
    ON_OFF_3,
    RES_CURSOR,
    KEY_SHAPE,
    UP,
    DOWN,
    JUMP,
    LEFT,
    RIGHT,
    ATTACK,
    INVENTORY,
    PROFILE,
    SAVE_1,
    SAVE_2,
    SAVE_3,
    SAVE_4,
    CLEAR_1,
    CLEAR_2,
    CLEAR_3,
    CLEAR_4,
    MANA_BAR,
    HEALTH,
    KNIGHT,
    BACK
} SPRITES;

typedef enum
{
    MENU,
    MENU_OPTIONS,
    MENU_AUDIO,
    MENU_VIDEO,
    MENU_KEYBOARD,
    SAVES_SCREEN,
    PLAYING,
    TOTAL
} SCENE;

typedef struct game_object_s
{
    SPRITES type;
    sfSprite* sprite;
    sfTexture* texture;
    sfVector2f pos;
    sfVector2f save_pos;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    float seconds;
    int length;
    int height;
    void (*move_rect)(struct game_object_s *, int, int);
    void (*change_pos)(struct game_object_s *, sfVector2f);
    void (*manage_clock)(struct game_object_s *);
    int max_rect;
    double timing;
    bool move;
    bool animated;
    struct game_object_s *next;
} game_object_t;

typedef struct particles_s
{
    sfCircleShape *shape;
    sfVector2f position;
    float speed;
    int radius;
}particles_t;

typedef struct coding_style_s
{
    SPRITES type;
    sfFloatRect float_rect;
    sfIntRect rect;
    char *filepath;
    bool move;
    bool animated;
    int max_rect;
    double timing;
} coding_style_t;

typedef struct all_s
{
    SCENE scene;
    sfRenderWindow *window;
    sfEvent event;
    game_object_t **objects;
    particles_t **particules;
    sfMusic **musics;
    sfRectangleShape **rectangles;
    sfVector2f vel;
    bool show_particules;
    int fps;
    sfUint8 mode;
    float width;
    float height;
}all_t;

#endif /* STRUCTURES_H_ */