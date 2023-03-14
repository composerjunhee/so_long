/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:47:20 by junheeki          #+#    #+#             */
/*   Updated: 2023/03/14 13:52:32 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/solong.h"

void	exit_event(t_game *game)
{
	int player_x;
	int player_y;

	player_x = game->player.x;
	player_y = game->player.y;

	if (game->map.pos[player_y][player_x] == 'E')
	{
		if(game->col_num == game->player.col_counter)
		{
			write(1, "Escaped.", 9);
			exit(0);
		}
		else
			write(1, "Collect all the collectibles", 29);

	}
}
