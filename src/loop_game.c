/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** loop_game.c
*/

#include "../include/my.h"

col_t spe_tab[4] =
{
    {1, "saves/save_1"},
    {2, "saves/save_2"},
    {3, "saves/save_3"},
    {4, "saves/save_4"}
};

void write_in_file_next(all_t *store, int fd, char *buffer)
{
    buffer = my_int_to_ascii(store->nb_golds);
    write(fd, buffer, my_strlen(buffer));
    write(fd, "\n", 1);
    for (int index = 0; index < 5; index += 1) {
        if (store->buys[index] == true)
            write(fd, "1", 1);
        else
            write(fd, "0", 1);
        write(fd, "\n", 1);
    }
}

void write_in_file(all_t *store)
{
    char *filepath = spe_tab[store->save - 1].filepath;
    int fd = open(filepath, O_WRONLY | O_TRUNC);
    char *buffer = my_malloc(sizeof(char) * 40);
    game_object_t *object = store->objects[PLAYING];

    if (!fd)
        return;
    for (; object->type != KNIGHT; object = object->next);
    my_memset(buffer, 0, 40);
    buffer = my_ftoa(object->pos.x, buffer, 6);
    write(fd, buffer, my_strlen(buffer));
    write(fd, "\n", 1);
    buffer = my_ftoa(object->pos.y, buffer, 6);
    write(fd, buffer, my_strlen(buffer));
    write(fd, "\n", 1);
    buffer = my_int_to_ascii(store->index_maps);
    write(fd, buffer, my_strlen(buffer));
    write(fd, "\n", 1);
    write_in_file_next(store, fd, buffer);
}

void clear_keypress(all_t *store)
{
    for (int i = 0; i < sfKeyCount; i++)
        store->key_press[i] = 0;
}

void update_ennemy(all_t *store)
{
    game_object_t *ob = NULL;

    for (ob = store->objects[PLAYING]; ob; ob = ob->next)
        if (ob->type == KNIGHT) {
            break;
        }
    if (store->index_maps != 5) {
        for (int i = 0; i < 10; i += 1) {
            if (store->mobs[i].alive == true) {


                store->mobs[i].time = sfClock_getElapsedTime(store->mobs[i].clock);
                store->mobs[i].sec = store->mobs[i].time.microseconds / 1000000.0;
                if (store->mobs[i].sec > 0.1) {
                    if (store->mobs[i].rec == 0)
                    store->mobs[i].rect.left += 160;
                    if (store->mobs[i].rec == 1)
                        store->mobs[i].rect.left -= 160;
                    sfSprite_setTextureRect(store->mobs[i].sprite, store->mobs[i].rect);
                    if (store->mobs[i].rect.left >= 800)
                        store->mobs[i].rec = 1;
                    if (store->mobs[i].rect.left <= 0)
                        store->mobs[i].rec = 0;
                    sfClock_restart(store->mobs[i].clock);
                }


                if (store->mobs[i].pos.x - ob->pos.x < 400 && store->mobs[i].pos.y - ob->pos.y < 200 && store->mobs[i].pos.x - ob->pos.x > -400) {
                    if (store->mobs[i].pos.x <= ob->pos.x - 30) {
                        store->mobs[i].pos.x += 1;
                        store->mobs[i].rect.top = 180;
                    }
                    if (store->mobs[i].pos.x > ob->pos.x - 10) {
                        store->mobs[i].pos.x -= 1;
                        store->mobs[i].rect.top = 0;
                    }
                    if (store->mobs[i].pos.y <= ob->pos.y - 100) {
                        store->mobs[i].pos.y += 1;
                    }
                    if (store->mobs[i].pos.y > ob->pos.y - 100) {
                        store->mobs[i].pos.y -= 1;
                    }
                    sfSprite_setPosition(store->mobs[i].sprite, store->mobs[i].pos);
                    sfRenderWindow_drawSprite(store->window, store->mobs[i].sprite, NULL);
                }
            }
        }
    }
    if (store->index_maps == 5) {
        for (int i = 1; i < 10; i += 1)
            store->mobs[i].alive = false;
        store->mobs[0].alive = true;
        store->mobs[0].pos.y = 650;
        sfSprite_setPosition(store->mobs[0].sprite, store->mobs[0].pos);
        sfRenderWindow_drawSprite(store->window, store->mobs[0].sprite, NULL);
        if (ob->pos.y >= 700) {
            if (store->mobs[0].pos.x < ob->pos.x)
                store->mobs[0].pos.x += 5;
            else
                store->mobs[0].pos.x -= 5;
        }
    }
}

void loop_game(all_t *store)
{
    sfMusic_play(store->musics[MENU]);
    while (sfRenderWindow_isOpen(store->window)) {
        sfRenderWindow_clear(store->window, sfCyan);
        clear_keypress(store);
        store->show_sword = false;
        while (sfRenderWindow_pollEvent(store->window, &store->event))
            analyse_events(store);
        manage_key_pressed(store, 0);
        manage_all_clock(store);
        if (store->scene == PLAYING)
            update_jump(store);
        update_ennemy(store);
        draw_scene(store);
        sfRenderWindow_display(store->window);
    }
    write_in_file(store);
}