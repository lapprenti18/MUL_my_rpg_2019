##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	lib/my/my_putnbr_base.c	\
		lib/my/my_compute_power_rec.c	\
		lib/my/my_compute_square_root.c	\
		lib/my/my_find_prime_sup.c	\
		lib/my/my_getnbr.c	\
		lib/my/my_isneg.c	\
		lib/my/my_is_prime.c	\
		lib/my/my_putchar.c	\
		lib/my/my_put_nbr.c	\
		lib/my/my_putstr.c	\
		lib/my/my_revstr.c	\
		lib/my/my_showmem.c	\
		lib/my/my_showstr.c	\
		lib/my/my_strcapitalize.c	\
		lib/my/my_strcat.c	\
		lib/my/my_strcmp.c	\
		lib/my/my_strcpy.c	\
		lib/my/my_strdup.c	\
		lib/my/my_str_isalpha.c	\
		lib/my/my_str_islower.c	\
		lib/my/my_str_isprintable.c	\
		lib/my/my_str_isupper.c	\
		lib/my/my_strlen.c	\
		lib/my/my_strlowcase.c	\
		lib/my/my_strncat.c	\
		lib/my/my_strncmp.c	\
		lib/my/my_strncpy.c	\
		lib/my/my_strstr.c	\
		lib/my/my_strupcase.c	\
		lib/my/my_swap.c	\
		lib/my/my_delete_neg.c	\
		lib/my/my_str_is_negative.c	\
		lib/my/my_str_to_word_array.c	\
		lib/my/my_supr_same.c	\
		lib/my/my_mult_zero.c	\
		lib/my/my_add_x_zero.c	\
		lib/my/my_delete_mult.c	\
		lib/my/my_zeroo.c	\
		lib/my/my_infin_tol.c	\
		lib/my/my_bistro_error.c	\
		lib/my/my_occ.c	\
		lib/my/my_str_isnum.c	\
		lib/my/my_print_b.c	\
		lib/my/my_print_c.c	\
		lib/my/my_print_caps.c	\
		lib/my/my_print_capx.c	\
		lib/my/my_print_d.c	\
		lib/my/my_print_o.c	\
		lib/my/my_print_p.c	\
		lib/my/my_print_s.c	\
		lib/my/my_print_u.c	\
		lib/my/my_print_x.c	\
		lib/my/my_printf.c	\
		lib/my/my_getfloat.c	\
		lib/my/my_memset.c	\

NAME	=	my_rpg

COMP	=	src/main.c	\
			src/collisions.c	\
			src/mobs.c	\
			src/projection.c	\
			src/manage_key_pressed.c	\
			src/set_structures.c	\
			src/set_structures_2.c	\
			src/update_sword.c	\
			src/set_structures_second.c	\
			src/loop_game.c	\
			src/check_damage.c	\
			src/analyse_events.c	\
			src/draw_scene.c	\
			src/setup_shop_sprites.c	\
			src/create_objects.c	\
			src/destroy_structures.c	\
			src/setup_functions.c	\
			src/manage_mouse_click.c	\
			src/manage_mouse_moved.c	\
			src/setup_scenes.c	\
			src/manage_clock.c	\
			src/handle_audio_click.c	\
			src/handle_inventory_click.c	\
			src/handle_menu_click.c	\
			src/handle_options_click.c	\
			src/handle_saves_click.c	\
			src/handle_video_click.c	\
			src/handle_shop_click.c	\
			src/handle_keyboard_click.c	\
			src/setup_scenes_2.c	\
			src/blend_mode.c	\
			src/setup_keyboard.c	\
			src/update_structures.c	\
			src/garbage_collector.c	\
			src/manage_jump.c	\
			src/analyse_mana.c	\
			src/analyse_knight.c	\
			src/setup_pause_sprites.c	\
			src/setup_playing_sprites.c	\
			src/handle_pause_click.c	\
			src/setup_inventory_sprites.c	\
			src/setup_quest_sprites.c	\
			src/manage_key_pressed_2.c	\
			src/handle_quest_click.c	\
			src/respawn.c	\
			src/manage_jump_two.c	\
			src/change_pos.c	\
			src/update_enn.c	\
			src/draw_quest.c	\
			src/setup_credits_sprites.c	\
			src/handle_credits_click.c	\
			src/lance.c 	\
			src/set_structures_3.c	\

CFLAGS  =	-W -Wall -Wextra -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm -Iinclude -g3

OBJ	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	: $(OBJ)
	gcc -o $(NAME) $(OBJ) $(COMP) $(CFLAGS)

clean	:
	rm -f *.o $(OBJ)

fclean	: clean
	rm -f $(NAME)

re	: fclean all
