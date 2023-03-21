/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:55:27 by junheeki          #+#    #+#             */
/*   Updated: 2023/03/21 17:00:58 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/solong.h"

void	print_err(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strleni(message));
	exit(1);
}

void	game_init(t_game *g, char *map)
{
	g->mlx = mlx_init();
	g->img = img_init(g->mlx);
	map_read(map, g);
	map_check(g);
	g->win = mlx_new_window(g->mlx, g->wid * 32, g->hei * 32, "so_long");
	setting_img(g);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	press_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit_game(game);
	if (key_code == KEY_W)
		move_w(game);
	if (key_code == KEY_A)
		move_a(game);
	if (key_code == KEY_S)
		move_s(game);
	if (key_code == KEY_D)
		move_d(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		print_err("Map is missing. \n");
	game = malloc(sizeof(t_game));
	game_init(game, argv[1]);
	mlx_hook(game->win, KEY_PRESS, 0, &press_key, game);
	mlx_hook(game->win, PRESS_RED_BUTTON, 0, &exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}
