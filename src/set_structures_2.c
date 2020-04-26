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
    if (read(fd, buffer, 5200) == 0)
        return (NULL);
    printf("%s\n", buffer);
    close(fd);
    return (my_str_to_word_array(buffer, "\n"));
}

sfView *init_view(void)
{
    sfView *view = sfView_create();

    sfView_setSize(view, (sfVector2f){1920, 1080});
    sfView_setCenter(view, (sfVector2f){200, 500});
    return (view);
}

void set_structures_next(all_t *store)
{
    store->right_or_left = 0;
    store->view = init_view();
    store->view_pos = (sfVector2f){0, 0};
    store->current = get_array("assets/collisions/first_screen.txt");
}