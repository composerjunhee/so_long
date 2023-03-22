/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:09:51 by junheeki          #+#    #+#             */
/*   Updated: 2023/03/22 14:53:18 by junheeki         ###   ########.fr       */
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

void put_img(t_game *g, int w, int h)
{
	if(g->str_line[h * g->wid + w] == '1')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.wall, w * 32, h * 32);
	}
	else if(g->str_line[h * g->wid + w] == 'C')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.collectible, w * 32, h * 32);
	}
	else if(g->str_line[h * g->wid + w] == 'P')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.player, w * 32, h * 32);
	}
	else if(g->str_line[h * g->wid + w] == 'E' && g->all_col == g->col_cnt)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.exit, w * 32, h * 32);
	}
	else if(g->str_line[h * g->wid + w] == 'E')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.exit, w * 32, h * 32);
	}
	else
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.land, w * 32, h * 32);
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
