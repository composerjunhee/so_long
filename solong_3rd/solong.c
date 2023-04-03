/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:55:27 by junheeki          #+#    #+#             */
/*   Updated: 2023/04/03 14:58:29 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/solong.h"

void	game_init(t_game *g, char *map)
{
	g->mlx = mlx_init();
	g->img = img_init(g->mlx);
	map_read(map, g);
	map_check(g);
}

void	game_window(t_game *g)
{
	g->win = mlx_new_window(g->mlx, g->wid * 32, g->hei * 32, "so_long");
	setting_img(g);
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
	//int		**map;

	if (argc != 2)
		print_err("ex) ./solong map.ber <- Follow the Format \n");
	game = malloc(sizeof(t_game));
	game_init(game, argv[1]);
	game->map2d = map_array(argv[1], game);
	//check validity path
	//game->map2d = map;
	check_valid_path(game->player_x, game->player_y, game->map2d, game);
	if (game->validity != 1)
		print_err("Error: Player cannot reach the exit.\n");
	game_window(game);
	mlx_hook(game->win, KEY_PRESS, 0, &press_key, game);
	mlx_hook(game->win, PRESS_RED_BUTTON, 0, &exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}