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
    buffer = my_int_to_ascii(store->quest_status);
    write(fd, buffer, my_strlen(buffer));
    write(fd, "\n", 1);
    buffer = my_int_to_ascii(store->knight_hp);
    write(fd, buffer, my_strlen(buffer));
    write(fd, "\n", 1);
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
        if (store->scene == PLAYING)
            update_jump(store);
        update_ennemy(store);
        update_sword(store);
        if (store->no_damages == false)
            check_for_damage(store);
        manage_all_clock(store);
        draw_scene(store);
        sfRenderWindow_display(store->window);
    }
    write_in_file(store);
}