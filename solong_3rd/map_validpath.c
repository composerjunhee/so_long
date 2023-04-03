/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validpath.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:49:30 by junheeki          #+#    #+#             */
/*   Updated: 2023/04/03 14:32:04 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/solong.h"

void	check_valid_path(int column, int row, int **map, t_game *g)
{
	if (g->reach_exit == 1 && g->all_col2d == g->col_cnt)
		g->validity = 1;
	if (g->map2d[column][row] == 4)
		g->reach_exit = 1;
	if (g->map2d[column][row] == 0 || g->map2d[column][row] == 3 || g->map2d[column][row] == 2)
	{
		if (g->map2d[column][row] == 3)
			g->all_col2d += 1;
		g->map2d[column][row] = 'V';
		if (column < row - 1)
			check_valid_path (column + 1, row, map, g);
		if (row < column-1)
			check_valid_path (column, row + 1, map, g);
		if (column > 0)
			check_valid_path(column - 1, row, map, g);
		if (row > 0)
			check_valid_path(column, row - 1, map, g);
	}
}
