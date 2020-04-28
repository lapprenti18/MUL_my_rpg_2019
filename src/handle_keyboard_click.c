/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** handle_keyboard_click.c
*/

#include "../include/my.h"

void handle_keyboard_click(all_t *store, game_object_t *copy)
{
    static int selec = -1;
    char *c = my_malloc(sizeof(char) * 2);

    if (copy) {
        if (copy->type == BACK)
            store->scene = MENU_OPTIONS;
        for (unsigned int i = 30; i < 37; i++)
            if (copy->type == i)
                selec = i - 30;
    }
    if (selec != -1)
        for (int j = 0; j < sfKeyCount; j++)
            if (store->key_press[j] == 1) {
                store->keys_code[selec] = j;
                c[0] = j + 65;
                c[1] = '\0';
                sfText_setString(store->keys_text[selec], c);
                selec = -1;
            }
}