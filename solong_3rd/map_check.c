/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:51:21 by junheeki          #+#    #+#             */
/*   Updated: 2023/04/11 18:18:54 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/solong.h"

void	map_check_params(t_game *game)
{
	int	i;
	int	num_e;
	int	num_p;

	i = 0;
	num_e = 0;
	num_p = 0;
	game->m.all_col = 0;
	game->m.col_cnt = 0;
	game->m.validity = 0;
	game->m.reach_exit = 0;

	while (i++ < ft_strleni(game->map_line))
	{
		if (game->map_line[i] == 'E')
			num_e++;
		else if (game->map_line[i] == 'P')
		{
			num_p++;
			{
				if (num_p != 1)
					print_err("Map must have one starting position\n");
			}
		}
		else if (game->map_line[i] == 'C')
			game->m.all_col++;
	}
	if (num_e != 1)
		print_err("Map must have at least one exit\n");
	else if (game->m.all_col == 0)
		print_err("Map must have at least one collectible\n");
	else if (num_p != 1)
		print_err("Map must have one starting position\n");
}

void	map_check_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i < ft_strleni(game->map_line))
	{
		if (i < game->m.wid)
		{
			if (game->map_line[i] != '1')
				print_err("Map must be closed/surrounded by walls\n");
		}
		else if (i % game->m.wid == 0 || i % game->m.wid == game->m.wid - 1)
		{
			if (game->map_line[i] != '1')
				print_err("Map must be closed/surrounded by walls\n");
		}
		else if (i > ft_strleni(game->map_line) - game->m.wid)
		{
			if (game->map_line[i] != '1')
				print_err("Map must be closed/surrounded by walls\n");
		}
		i++;
	}
}

void	map_check_chracter(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_line[i])
	{
		if (game->map_line[i] != 'C' && game->map_line[i] != 'E' && game->map_line[i] != 'P'
			&& game->map_line[i] != '1' && game->map_line[i] != '0' && game->map_line[i] != '\n')
			print_err("Wrong Character included\n");
		else
			i++;
	}
}

void	check_valid_path(int y, int x, int **map, t_game *g)
{
	if (g->m.reach_exit == 1 && g->m.all_col == g->m.col_cnt)
		g->m.validity = 1;
	if (g->map2d[y][x] == 4)
		g->m.reach_exit = 1;
	if (g->map2d[y][x] == 0 || g->map2d[y][x] == 3 || g->map2d[y][x] == 2)
	{
		if (g->map2d[y][x] == 3)
			g->m.col_cnt += 1;
		g->map2d[y][x] = 5;
		if (x < g->m.wid - 1) //right
			check_valid_path (y + 1, x, map, g);
		if (y < g->m.hei - 1) //bottom
			check_valid_path (y, x + 1, map, g);
		if (x > 0) //left
			check_valid_path(y - 1, x, map, g);
		if (y > 0) //up
			check_valid_path(y, x - 1, map, g);
	}
}

void	map_check(t_game *game)
{
	if (game->m.hei * game->m.wid != ft_strleni(game->map_line))
		print_err("Map must be rectangular.\n");
	map_check_chracter(game);
	map_check_wall(game);
	map_check_params(game);
	check_valid_path(game->p.player_y, game->p.player_x, game->map2d, game);
	game->m.col_cnt = 0;
	if (game->m.validity == 0)
		print_err("Player cannot reach the exit or all the collectibles.\n");
}

