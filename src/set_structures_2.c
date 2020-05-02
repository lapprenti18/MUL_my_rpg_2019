/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** set_structures_2.c
*/

#include "../include/my.h"

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
    sfTexture **tab = my_malloc(sizeof(sfTexture *) * 6);

    if (!tab)
        return (NULL);
    tab[0] = sfTexture_createFromFile("assets/textures/1er_map.png", NULL);
    tab[1] = sfTexture_createFromFile("assets/textures/town.png", NULL);
    tab[2] = sfTexture_createFromFile("assets/textures/3eme_map.png", NULL);
    tab[3] = sfTexture_createFromFile("assets/textures/4eme_map.png", NULL);
    tab[4] = sfTexture_createFromFile("assets/textures/5eme_map.png", NULL);
    tab[5] = sfTexture_createFromFile("assets/textures/6eme_map.png", NULL);
    return (tab);
}

bool *is_that_buy(void)
{
    bool *tab = my_malloc(sizeof(bool) * 5);

    for (int index = 0; index < 6; index += 1)
        tab[index] = false;
    return (tab);
}

void set_structures_last(all_t *store)
{
    store->show_sword = false;
    store->knight_dgs = 1;
    store->more_golds = 1;
    store->more_mana = 1;
    store->mobs = init_mobs();
    store->quest_status = 0;
    store->spawn = 1;
    store->attack = 0;
    store->sec = 0;
    store->clock = sfClock_create();
    store->sec_attack = 0;
    store->clock_attack = sfClock_create();
    store->show_quest = true;
    store->knight_hp = 5;
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
    store->buys = is_that_buy();
    store->show_enter = false;
    store->show_enter_2 = false;
    set_structures_last(store);
}