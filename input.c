/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:47:26 by junheeki          #+#    #+#             */
/*   Updated: 2023/03/16 10:18:28 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/solong.h"

int keys(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		printf("Escaped -> %d\n", keycode);
		exit(0);
		//mlx_destroy_window(game->mlx, game->win);
	}
	if (keycode == KEY_W)
	{
		game->count_move++;
		printf("W, Move to the North -> %d\n", keycode);
	}
	else if (keycode == KEY_S)
	{
		game->count_move++;
		printf("S, Move to the South -> %d\n", keycode);
	}
	else if (keycode == KEY_D)
	{
		game->count_move++;
		printf("S, Move to the East -> %d\n", keycode);
	}
	else if (keycode == KEY_A)
	{
		game->count_move++;
		printf("A, Move to the West -> %d\n", keycode);
	}
	return (0);
}
