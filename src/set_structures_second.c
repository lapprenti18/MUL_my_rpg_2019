/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** set_structures_second.c
*/

#include "../include/my.h"

sfText *create_text(sfVector2f pos, char *str)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/fonts/keys.ttf");

    sfText_setFont(text, font);
    sfText_setPosition(text, pos);
    sfText_setString(text, str);
    sfText_setCharacterSize(text, 40);
    return (text);
}

sfText **create_keys(void)
{
    sfText **keys = my_malloc(sizeof(sfText *) * 8);

    if (!keys)
        return (NULL);
    keys[0] = create_text((sfVector2f){920, 375}, "Z");
    keys[1] = create_text((sfVector2f){1420, 375}, "S");
    keys[2] = create_text((sfVector2f){920, 473}, "Q");
    keys[3] = create_text((sfVector2f){1420, 473}, "D");
    keys[4] = create_text((sfVector2f){920, 570}, "M");
    keys[5] = create_text((sfVector2f){1420, 570}, " ");
    keys[6] = create_text((sfVector2f){1120, 670}, "I");
    keys[7] = NULL;
    return (keys);
}