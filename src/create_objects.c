/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_objects.c
*/

#include "../include/my.h"

game_object_t *complete_node(coding_style_t code)
{
    game_object_t *new_node = my_malloc(sizeof(game_object_t));

    new_node->type = code.type;
    new_node->clock = sfClock_create();
    new_node->pos = (sfVector2f){code.float_rect.left, code.float_rect.top};
    new_node->length = (int)code.float_rect.width;
    new_node->height = (int)code.float_rect.height;
    new_node->rect = code.rect;
    new_node->sprite = sfSprite_create();
    new_node->texture = sfTexture_createFromFile(code.filepath, NULL);
    new_node->change_pos = change_pos;
    new_node->move_rect = move_rect;
    new_node->manage_clock = manage_clock;
    new_node->next = NULL;
    sfSprite_setTexture(new_node->sprite, new_node->texture, sfTrue);
    sfSprite_setTextureRect(new_node->sprite, new_node->rect);
    sfSprite_setPosition(new_node->sprite, new_node->pos);
    if (new_node->type != CURSEUR)
        sfSprite_setOrigin(new_node->sprite, (sfVector2f)\
        {new_node->length / 2, new_node->height / 2});
    return (new_node);
}

void add_node_back(game_object_t **nodes, coding_style_t coding)
{
    game_object_t *new_node = NULL;
    game_object_t *copy = *nodes;

    new_node = complete_node(coding);
    new_node->move = coding.move;
    new_node->animated = coding.animated;
    new_node->max_rect = coding.max_rect;
    new_node->timing = coding.timing;
    new_node->seconds = 0.0;
    new_node->save_pos = new_node->pos;
    new_node->get_viewed = false;
    if (*nodes) {
        while (copy->next)
            copy = copy->next;
        copy->next = new_node;
    } else
        *nodes = new_node;
}

game_object_t **create_objects(sfRenderWindow *window)
{
    game_object_t **objects = my_malloc(sizeof(game_object_t) * (TOTAL + 1));
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    objects[MENU] = setup_menu_sprites(NULL);
    objects[MENU_OPTIONS] = setup_options_sprites();
    objects[MENU_AUDIO] = setup_audio_sprites();
    objects[MENU_VIDEO] = setup_video_sprites();
    objects[MENU_KEYBOARD] = setup_keyboard_sprites();
    objects[SAVES_SCREEN] = setup_saves_sprites();
    objects[PLAYING] = setup_playing_sprites();
    objects[PAUSE] = setup_pause_sprites();
    objects[INVENTORY] = setup_inventory_sprites();
    objects[SHOP] = setup_shop_sprites();
    for (int index = MENU; index < TOTAL; index += 1)
        add_node_back(&objects[index], (coding_style_t){CURSEUR, \
        (sfFloatRect){mouse.x, mouse.y, 25, 25}, \
        (sfIntRect){0, 0, 25, 25}, "assets/textures/curseur.png", \
        false, false, -1, -1});
    objects[TOTAL] = NULL;
    return (objects);
}