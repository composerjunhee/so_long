/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:18:49 by junheeki          #+#    #+#             */
/*   Updated: 2023/03/30 20:21:10 by junheeki         ###   ########.fr       */
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
	game->all_col = 0;
	game->col_cnt = 0;
	while (i++ < ft_strleni(game->str_line))
	{
		if (game->str_line[i] == 'E')
			num_e++;
		else if (game->str_line[i] == 'P')
		{
			num_p++;
			{
				if (num_p != 1)
					print_err("Map must have one starting position\n");
			}
		}
		else if (game->str_line[i] == 'C')
			game->all_col++;
	}
	if (num_e != 1)
		print_err("Map must have at least one exit\n");
	else if (game->all_col == 0)
		print_err("Map must have at least one collectible\n");
	else if (num_p != 1)
		print_err("Map must have one starting position\n");
}

// void	check_valid_path(int column, int row, char **map, t_game *game)
// {
// 	if (game->map2d->reach_exit == 1 && game->all_col == game->col_cnt)
// 		game->map2d->validity = 1;
// 	if (game->map2d[x][y] == 'E')
// 		game->map2d->reach_exit = 1;
// 	if (game->map2d[x][y] == '0' || maze[column][row] == 'C'
// 		|| maze[column][row] == 'P')
// 	{
// 		if (maze[column][row] == 'C')
// 			map->collectible_check += 1;
// 		maze[column][row] = 'X';
// 		if (column < game->hei - 1)
// 			check_valid_path (column + 1, row, maze, map);
// 		if (row < game->wid-1)
// 			check_valid_path (column, row + 1, maze, map);
// 		if (column > 0)
// 			check_valid_path(column - 1, row, maze, map);
// 		if (row > 0)
// 			check_valid_path(column, row - 1, maze, map);
// 	}
// }
