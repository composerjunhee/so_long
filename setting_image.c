/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:12:14 by junheeki          #+#    #+#             */
/*   Updated: 2023/03/15 09:17:05 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/solong.h"

void	setting_img(t_game game)
{
	int		hei;
	int		wid;

	hei = 0;
	while (hei < game.hei)
	{
		wid = 0;
		while (wid < game.wid)
		{
			if (game.str_line[hei * game.wid + wid] == '1')
			{
				mlx_put_image_to_window(game.mlx, game.win, game.img.wall, wid * 64, hei * 64);
			}
			else if (game.str_line[hei * game.wid + wid] == 'C')
			{
				mlx_put_image_to_window(game.mlx, game.win, game.img.collectible, wid * 64, hei * 64);
			}
			else if (game.str_line[hei * game.wid + wid] == 'P')
			{
				mlx_put_image_to_window(game.mlx, game.win, game.img.player, wid * 64, hei * 64);
			}
			else if (game.str_line[hei * game.wid + wid] == 'E')
			{
				mlx_put_image_to_window(game.mlx, game.win, game.img.exit, wid * 64, hei * 64);
			}
			else
			{
				mlx_put_image_to_window(game.mlx, game.win, game.img.land, wid * 64, hei * 64);
			}
			wid++;
		}
		hei++;
	}
}
