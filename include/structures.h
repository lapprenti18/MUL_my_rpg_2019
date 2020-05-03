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
    LEFT,
    RIGHT,
    ATTACK,
    JUMP,
    S_INVENTORY,
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
    SHAPE_PAUSE,
    PAUSE_CONTINUE,
    PAUSE_OPTIONS,
    PAUSE_QUIT,
    GOLDS,
    BACK,
    ENTER,
    ENTER_2,
    LISTEN,
    QUEST_BOX,
    SWORD_EFFECT,
    QUEST_BEGIN,
    LITTLE_QUEST,
    QUEST_END,
    QUEST_BOX_END,
    LIFE_CHARM, // rajouter aucun enum apres celui-ci, toujours en rajouter avant
    ATTACK_CHARM,
    MANA_CHARM,
    GOLD_CHARM,
    HEART_CHARM
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
    PAUSE,
    INVENTORY,
    SHOP,
    QUEST,
    CREDITS,
    TOTAL
} SCENE;

typedef struct mob_s
{
    int hp;
    int reward;
    int rec;
    float sec;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    bool alive;
} mob_t;

typedef struct charm_s
{
    int index;
    int price;
} charm_t;

typedef struct col_s
{
    int index;
    char *filepath;
} col_t;

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
    bool get_viewed;
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

typedef struct sounds_s
{
    sfSoundBuffer *buffer;
    sfSound *sound;
} sounds_t;

typedef struct all_s
{
    SCENE scene;
    sfRenderWindow *window;
    sfEvent event;
    game_object_t **objects;
    particles_t **particules;
    sfMusic **musics;
    sfRectangleShape **rectangles;
    sfVector2f velocity;
    bool show_particules;
    int fps;
    sfUint8 mode;
    float width;
    float height;
    sfText **keys_text;
    int *key_press;
    sfKeyCode *keys_code;
    int nb_jump;
    int mana_level;
    float gravity;
    int right_or_left;
    char **current;
    sfTexture **textures;
    int index_maps;
    bool change_texture;
    sfVector2f accel;
    float frottement;
    int save;
    int in_inventory;
    int nb_golds;
    int spawn;
    sfText *golds;
    bool *buys;
    bool show_enter;
    bool show_enter_2;
    mob_t *mobs;
    int quest_status;
    bool show_quest;
    bool show_sword;
    int knight_dgs;
    int more_golds;
    int more_mana;
    int attack;
    sfClock *clock;
    sfTime time;
    float sec;
    sfClock *clock_attack;
    sfTime time_attack;
    float sec_attack;
    int knight_hp;
    sounds_t *tab_sound;
    bool no_damages;
    char **first_plan;
    sfTexture *texture_plan;
    sfSprite *sprite_plan;
}all_t;

#endif /* STRUCTURES_H_ */