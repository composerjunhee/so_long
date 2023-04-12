/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:19:18 by junheeki          #+#    #+#             */
/*   Updated: 2023/04/12 16:27:54 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/solong.h"

t_img	img_init(void *mlx)
{
	t_img	img;
	int		wid;
	int		hei;

	img.land = mlx_xpm_file_to_image(mlx, "textures/grass.xpm", &wid, &hei);
	img.wall = mlx_xpm_file_to_image(mlx, "textures/wall.xpm", &wid, &hei);
	img.col = mlx_xpm_file_to_image(mlx, "textures/collectible.xpm", &wid,
			&hei);
	img.player = mlx_xpm_file_to_image(mlx, "textures/woodboy.xpm", &wid, &hei);
	img.exit = mlx_xpm_file_to_image(mlx, "textures/exit.xpm", &wid, &hei);
	return (img);
}

void	put_img(t_game *g, int w, int h)
{
	mlx_put_image_to_window(g->mlx, g->win, g->img.land, w * 32, h * 32);
	if (g->map_line[h * g->m.wid + w] == '1')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.wall, w * 32, h * 32);
	}
	else if (g->map_line[h * g->m.wid + w] == 'C')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.col, w * 32, h * 32);
	}
	else if (g->map_line[h * g->m.wid + w] == 'P')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.player, w * 32, h * 32);
	}
	else if (g->map_line[h * g->m.wid + w] == 'E'
		&& g->m.all_col == g->m.col_cnt)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.exit, w * 32, h * 32);
	}
	else if (g->map_line[h * g->m.wid + w] == 'E')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.exit, w * 32, h * 32);
	}
}

void	setting_img(t_game *game)
{
	int	hei;
	int	wid;

	hei = 0;
	while (hei < game->m.hei)
	{
		wid = 0;
		while (wid < game->m.wid)
		{
			put_img(game, wid, hei);
			wid++;
		}
		hei++;
	}
}
