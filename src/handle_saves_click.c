/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** handle_saves_click.c
*/

#include "../include/my.h"

col_t tab_spe[3] =
{
    {0, "assets/collisions/first_screen.txt"},
    {1, "assets/collisions/second_screen.txt"},
    {2, "assets/collisions/third_screen.txt"}
};

void update_save(all_t *store, char *filepath)
{
    char **array = get_array(filepath);
    game_object_t *object = store->objects[PLAYING];
    int save_index = 0;

    if (!array || !array[0])
        return;
    save_index = my_getnbr(array[2]);
    for (; object; object = object->next) {
        if (object->type == KNIGHT) {
            object->pos.x = my_getfloat(array[0]);
            object->pos.y = my_getfloat(array[1]);
            sfSprite_setPosition(object->sprite, object->pos);
        }
        if (object->type == BACKGROUND) {
            store->current = get_array(tab_spe[save_index].filepath);
            sfSprite_setTexture(object->sprite, \
            store->textures[save_index], sfTrue);
            store->index_maps = save_index;
        }
    }
}

void get_save(all_t *store, game_object_t *copy)
{
    char *filepath = NULL;

    if (copy->type == SAVE_1) {
        filepath = "saves/save_1";
        store->save = 1;
    }
    if (copy->type == SAVE_2) {
        filepath = "saves/save_2";
        store->save = 2;
    }
    if (copy->type == SAVE_3) {
        filepath = "saves/save_3";
        store->save = 3;
    }
    if (copy->type == SAVE_4) {
        filepath = "saves/save_4";
        store->save = 4;
    }
    update_save(store, filepath);
}

void handle_saves_click(all_t *store, game_object_t *copy)
{
    if (copy->type == BACK)
        store->scene = MENU;
    if (copy->type >= SAVE_1 && copy->type <= SAVE_4) {
        sfMusic_pause(store->musics[MENU]);
        sfMusic_play(store->musics[PLAYING]);
        store->show_particules = false;
        get_save(store, copy);
        store->scene = PLAYING;
    }
}