/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** set_structures_2.c
*/

#include "../include/my.h"

char **get_array(char *filepath)
{
    char *buffer = my_malloc(sizeof(char) * 5200);
    int fd = open(filepath, O_RDONLY);

    if (!fd)
        return (NULL);
    my_memset(buffer, 0, 5200);
    if (read(fd, buffer, 5200) <= 0)
        return (NULL);
    close(fd);
    return (my_str_to_word_array(buffer, "\n"));
}

sfText *init_text(sfVector2f pos, char *str)
{
    sfText *text = sfText_create();
    static sfFont *font = NULL;

    if (!font)
        font = sfFont_createFromFile("assets/fonts/pointfree.ttf");
    sfText_setFont(text, font);
    sfText_setPosition(text, pos);
    sfText_setString(text, str);
    sfText_setCharacterSize(text, 40);
    return (text);
}

sfTexture **init_backgrounds(void)
{
    sfTexture **tab = my_malloc(sizeof(sfTexture *) * 3);

    if (!tab)
        return (NULL);
    tab[0] = sfTexture_createFromFile("assets/textures/1er_map.png", NULL);
    tab[1] = sfTexture_createFromFile("assets/textures/town.png", NULL);
    tab[2] = sfTexture_createFromFile("assets/textures/3eme_map.png", NULL);
    return (tab);
}

void set_structures_next(all_t *store)
{
    store->right_or_left = 0;
    store->current = get_array("assets/collisions/first_screen.txt");
    store->textures = init_backgrounds();
    store->index_maps = 0;
    store->change_texture = false;
    store->accel.x = 0;
    store->accel.y = store->gravity;
    store->frottement = -0.09;
    store->save = 0;
    store->key_press = my_malloc(sizeof(int) * (sfKeyCount));
    store->in_inventory = 0;
    store->nb_golds = 0;
    store->golds = init_text((sfVector2f){1750, 75}, "0");
}