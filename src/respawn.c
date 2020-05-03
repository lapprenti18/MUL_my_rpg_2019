/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** manage_jump.c
*/

#include "../include/my.h"

char **get_array(char *filepath)
{
    char *buffer = my_malloc(sizeof(char) * 6000);
    int fd = open(filepath, O_RDONLY);

    if (!fd)
        return (NULL);
    my_memset(buffer, 0, 6000);
    if (read(fd, buffer, 6000) <= 0)
        return (NULL);
    close(fd);
    return (my_str_to_word_array(buffer, "\n"));
}

void respawn_left(all_t *store, game_object_t *object)
{
    if (store->index_maps == 0)
        object->change_pos(object, (sfVector2f){200, 850});
    if (store->index_maps == 1)
        object->change_pos(object, (sfVector2f){200, 850});
    if (store->index_maps == 2)
        object->change_pos(object, (sfVector2f){200, 850});
    if (store->index_maps == 3)
        object->change_pos(object, (sfVector2f){200, 850});
    if (store->index_maps == 4)
        object->change_pos(object, (sfVector2f){960, 150});
    if (store->index_maps == 5)
        object->change_pos(object, (sfVector2f){100, 700});
}

void respawn_right(all_t *store, game_object_t *object)
{
    if (store->index_maps == 0)
        object->change_pos(object, (sfVector2f){1800, 850});
    if (store->index_maps == 1)
        object->change_pos(object, (sfVector2f){1800, 850});
    if (store->index_maps == 2)
        object->change_pos(object, (sfVector2f){1800, 850});
    if (store->index_maps == 3)
        object->change_pos(object, (sfVector2f){1800, 850});
    if (store->index_maps == 4)
        object->change_pos(object, (sfVector2f){1800, 700});
    if (store->index_maps == 5)
        object->change_pos(object, (sfVector2f){100, 700});
}

void update_damage(all_t *store, game_object_t *object)
{
    if (store->knight_hp == 0) {
        store->nb_golds = 0;
        store->mana_level = 0;
        store->knight_hp = 5;
        store->spawn = 1;
        store->index_maps = 0;
        store->change_texture = true;
        for (game_object_t *ob = store->objects[PLAYING]; ob; ob = ob->next) {
            if (ob->type == HEALTH) {
                ob->rect.left = 0;
                ob->animated = true;
                sfSprite_setTextureRect(ob->sprite, ob->rect);
            }
        }
        for (int index = 0; index < 10; index += 1)
            store->mobs[index].alive = false;
        object->change_pos(object, (sfVector2f){50, 800});
        store->current = get_array("assets/collisions/first_screen.txt");
        return;
    }
}

void respawn(all_t *store, game_object_t *object)
{
    if (store->knight_hp != 0) {
        store->knight_hp -= 1;
        for (game_object_t *ob = store->objects[PLAYING]; ob; ob = ob->next) {
            if (ob->type == HEALTH && ob->rect.left != 306) {
                ob->rect.left = 306;
                ob->animated = false;
                sfSprite_setTextureRect(ob->sprite, ob->rect);
                break;
            }
        }
        update_damage(store, object);
    }
    if (store->spawn == 1)
        respawn_left(store, object);
    if (store->spawn == 2)
        respawn_right(store, object);
}