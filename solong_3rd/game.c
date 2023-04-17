/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:09:39 by junheeki          #+#    #+#             */
/*   Updated: 2023/04/12 14:47:05 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/solong.h"

void	game_init(t_game *game, char *map)
{
	game->mlx = mlx_init();
	game->img = img_init(game->mlx);
	map_read(map, game);
	game->m.all_col = 0;
	game->m.col_cnt = 0;
	game->m.validity = 0;
	game->m.reach_exit = 0;
	game->num_e = 0;
	game->num_p = 0;
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	game_window(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->m.wid * 32, game->m.hei * 32,
			"so_long");
	setting_img(game);
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
