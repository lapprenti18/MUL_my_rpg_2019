/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** handle_saves_click.c
*/

#include "../include/my.h"

col_t tab_spe[6] =
{
    {0, "assets/collisions/first_screen.txt"},
    {1, "assets/collisions/second_screen.txt"},
    {2, "assets/collisions/third_screen.txt"},
    {3, "assets/collisions/four_screen.txt"},
    {4, "assets/collisions/five_screen.txt"},
    {5, "assets/collisions/six_screen.txt"}

};

void update_save_next(all_t *store, char **array)
{
    int save_hp = 0;

    for (int index = 4; index < 9; index += 1)
        if (my_getnbr(array[index]) == 1)
            store->buys[index - 4] = true;
    store->quest_status = my_getnbr(array[9]);
    if (store->quest_status >= 1)
        store->show_quest = false;
    store->knight_hp = my_getnbr(array[10]);
    save_hp = 5 - store->knight_hp;
    for (game_object_t *ob = store->objects[PLAYING]; ob; ob = ob->next) {
        if (ob->type == HEALTH) {
            ob->rect.left = 306;
            ob->animated = false;
            sfSprite_setTextureRect(ob->sprite, ob->rect);
            save_hp -= 1;
        }
        if (save_hp == 0)
            break;
    }
}

void update_save(all_t *store, char *filepath, int save_index)
{
    char **array = get_array(filepath);
    game_object_t *object = store->objects[PLAYING];

    if (!array || !array[0])
        return;
    save_index = my_getnbr(array[2]);
    store->nb_golds = my_getnbr(array[3]);
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
    update_save_next(store, array);
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
    update_save(store, filepath, 0);
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
    if (copy->type >= CLEAR_1 && copy->type <= CLEAR_2)
        clear_save(copy->type - CLEAR_1);
}