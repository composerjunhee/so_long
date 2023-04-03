/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:18:49 by junheeki          #+#    #+#             */
/*   Updated: 2023/04/03 14:54:51 by junheeki         ###   ########.fr       */
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
	game->validity = 0;
	game->reach_exit = 0;

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

void	map_check_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i < ft_strleni(game->str_line))
	{
		if (i < game->wid)
		{
			if (game->str_line[i] != '1')
				print_err("Map must be closed/surrounded by walls\n");
		}
		else if (i % game->wid == 0 || i % game->wid == game->wid - 1)
		{
			if (game->str_line[i] != '1')
				print_err("Map must be closed/surrounded by walls\n");
		}
		else if (i > ft_strleni(game->str_line) - game->wid)
		{
			if (game->str_line[i] != '1')
				print_err("Map must be closed/surrounded by walls\n");
		}
		i++;
	}
}

