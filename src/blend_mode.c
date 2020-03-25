/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** blend_mode.c
*/

#include "../include/my.h"

sfRenderStates *blend_mode(sfTexture *texture)
{
    sfRenderStates *states = malloc(sizeof(sfRenderStates));

    states->blendMode = sfBlendAdd;
    states->transform = (sfTransform) {{1, 1, 0, 0, 1, 0, 0, 0, 1}};
    states->shader = NULL;
    states->texture = texture;
    return (states);
}