/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** set_structures.c
*/

#include "../include/my.h"

sfRectangleShape **create_white_rectangles(void)
{
    sfRectangleShape **rectangles = my_malloc(sizeof(sfRectangleShape *) * 4);
    int index = 0;
    int pos_y = 382;

    for (index = 0; index < 3; index += 1) {
        rectangles[index] = sfRectangleShape_create();
        sfRectangleShape_setFillColor(rectangles[index], sfWhite);
        sfRectangleShape_setSize(rectangles[index], (sfVector2f){160, 5});
        sfRectangleShape_setPosition(rectangles[index], (sfVector2f){1047, pos_y});
        pos_y += 63;
    }
    rectangles[index] = NULL;
    return (rectangles);
}

sfMusic **create_tab_music(void)
{
    sfMusic **musics = my_malloc(sizeof(sfMusic *) * (TOTAL + 1));

    if (!musics)
        return (NULL);
    for (int index = 0; index < PLAYING; index += 1)
        musics[index] = sfMusic_createFromFile("assets/musics/menu_theme.ogg");
    musics[PLAYING] = sfMusic_createFromFile("assets/musics/playing.ogg");
    musics[TOTAL] = NULL;
    for (int index = 0; musics[index]; index += 1) {
        sfMusic_setLoop(musics[index], sfTrue);
        sfMusic_setVolume(musics[index], 20);
    }
    return (musics);
}

particles_t **create_particles(int *random)
{
    particles_t **particules = my_malloc(sizeof(particles_t *) * 101);

    for (int index = 0; index < 100; index += 1) {
        particules[index] = my_malloc(sizeof(particles_t));
        particules[index]->shape = sfCircleShape_create();
        random[0] = rand() % (WIDTH - 200) + 200;
        random[1] = rand() % HEIGHT;
        particules[index]->position = (sfVector2f){(float)random[0], \
        (float)random[1]};
        random[0] = rand() % 10 + 1;
        random[1] = rand() % 5 + 1;
        particules[index]->radius = random[0];
        particules[index]->speed = random[1];
        sfCircleShape_setFillColor(particules[index]->shape, sfBlack);
        sfCircleShape_setRadius(particules[index]->shape, \
        particules[index]->radius);
        sfCircleShape_setPosition(particules[index]->shape, \
        particules[index]->position);
    }
    particules[100] = NULL;
    return (particules);
}

sfRenderWindow *create_window(int fps)
{
    sfRenderWindow* window;
    sfVideoMode mode = {WIDTH, HEIGHT, 32};

    window = sfRenderWindow_create(mode, "RPG", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, fps);
    return (window);
}

void set_structures(all_t *store)
{
    int random[2];

    store->scene = MENU;
    store->window = create_window(60);
    store->objects = create_objects();
    store->particules = create_particles(random);
    store->musics = create_tab_music();
    store->rectangles = create_white_rectangles();
}