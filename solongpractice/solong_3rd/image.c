/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:09:51 by junheeki          #+#    #+#             */
/*   Updated: 2023/03/28 13:41:58 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/solong.h"

t_img	img_init(void *mlx)
{
	t_img img;
	int	wid;
	int	hei;

	img.land = mlx_xpm_file_to_image(mlx, "images/grass.xpm", &wid, &hei);
	img.wall = mlx_xpm_file_to_image(mlx, "images/wall.xpm", &wid, &hei);
	img.collectible = mlx_xpm_file_to_image(mlx, "images/collectible.xpm", &wid, &hei);
	img.player = mlx_xpm_file_to_image(mlx, "images/woodboy.xpm", &wid, &hei);
	img.exit = mlx_xpm_file_to_image(mlx, "images/exit.xpm", &wid, &hei);
	return(img);
}

void put_img(t_game *game, int w, int h)
{
	if(game->str_line[h * game->wid + w] == '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img.wall, w * 32, h * 32);
	}
	else if(game->str_line[h * game->wid + w] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img.collectible, w * 32, h * 32);
	}
	else if(game->str_line[h * game->wid + w] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img.player, w * 32, h * 32);
	}
	else if(game->str_line[h * game->wid + w] == 'E' && game->all_col == game->col_cnt)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit, w * 32, h * 32);
	}
	else if(game->str_line[h * game->wid + w] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit, w * 32, h * 32);
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img.land, w * 32, h * 32);
	}
}

void setting_img(t_game *game)
{
	int	hei;
	int wid;

	hei = 0;
	while(hei < game->hei)
	{
		wid = 0;
		while(wid < game->wid)
		{
			put_img(game, wid, hei);
			wid++;
		}
		hei++;
	}
}
