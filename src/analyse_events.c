/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** analyse_events.c
*/

#include "../include/my.h"

game_object_t *check_animated(game_object_t *knight)
{
    if (knight->rect.top == 0 || knight->rect.top == 127)
        knight->animated = false;
    else 
        knight->animated = true;
    return (knight);
}

void analyse_events(all_t *store)
{
    game_object_t *copy = store->objects[PLAYING];

    for (; copy->type != KNIGHT; copy = copy->next);
    if (store->event.type == sfEvtClosed || \
    store->event.key.code == sfKeyEscape)
        sfRenderWindow_close(store->window);
    if (store->event.type == sfEvtMouseButtonPressed)
        manage_mouse_clicked(store);
    if (store->event.type == sfEvtMouseMoved)
        manage_mouse_moved(store);
    store = analyse_mana_bar(store);
    store = analyse_knight(store);
    //if (store->event.type == sfEvtKeyPressed) {
    //    if (sfKeyboard_isKeyPressed(sfKeySpace) && store->nb_jump == 1) {
            //store->nb_jump = 0;
            //store->velocity.y -= 30;
            //if (sfKeyboard_isKeyPressed(sfKeyD)) { 
            //    store->velocity.x -= 5;
            //    if ((copy->rect.left >= 0 && copy->rect.left < 89) || (copy->rect.left >= 178 && copy->rect.left < 373)) {
            //        copy->rect.left = 5682;
            //        copy->rect.width = 89;
            //        sfSprite_setTextureRect(copy->sprite, (sfIntRect){5682, 0, 89, 127});
            //    }
            //}
    //        if (sfKeyboard_isKeyPressed(sfKeyQ)) {
    //            store->velocity.x += 5;
    //            if ((copy->rect.left >= 89 && copy->rect.left < 178) || (copy->rect.left >= 373 && copy->rect.left < 633)) {
    //                copy->rect.left = 6928;
    //                copy->rect.width = 89;
    //                sfSprite_setTextureRect(copy->sprite, (sfIntRect){6928, 0, 89, 127});
    //            }
    //        }
    //    }
}