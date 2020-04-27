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

sfTexture **init_backgrounds(void)
{
    sfTexture **tab = my_malloc(sizeof(sfTexture *) * 2);

    if (!tab)
        return (NULL);
    tab[0] = sfTexture_createFromFile("assets/textures/1er_map.png", NULL);
    tab[1] = sfTexture_createFromFile("assets/textures/town.png", NULL);
    return (tab);
}

void set_structures_next(all_t *store)
{
    store->right_or_left = 0;
    store->current = get_array("assets/collisions/first_screen.txt");
    store->textures = init_backgrounds();
    store->index_maps = 0;
    store->change_texture = false;
}