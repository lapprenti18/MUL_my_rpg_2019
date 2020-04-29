/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** blend_mode.c
*/

#include "../include/my.h"

void clear_save(int file)
{
    char *filepath = NULL;
    int fd = 0;

    if (file == 0)
        filepath = "saves/save_1";
    if (file == 1)
        filepath = "saves/save_2";
    if (file == 2)
        filepath = "saves/save_3";
    if (file == 3)
        filepath = "saves/save_4";
    fd = open(filepath, O_WRONLY | O_TRUNC);
    close(fd);
}

sfRenderStates *blend_mode(sfTexture *texture)
{
    sfRenderStates *states = malloc(sizeof(sfRenderStates));

    states->blendMode = sfBlendAdd;
    states->transform = (sfTransform) {{1, 1, 0, 0, 1, 0, 0, 0, 1}};
    states->shader = NULL;
    states->texture = texture;
    return (states);
}