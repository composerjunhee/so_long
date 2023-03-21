/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:22:52 by junheeki          #+#    #+#             */
/*   Updated: 2023/03/21 12:00:42 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/solong.h"

void draw_img(char a, t_param *par, int x, int y)
{
	if (a == '0') //if chracter is '0'
		mlx_put_image_to_window(par->mlx, par->win, par->g, x, y); //draw land image
	else if (a == '1') //if chracter is '1'
	{

		mlx_put_image_to_window(par->mlx, par->win, par->g, x, y);
		mlx_put_image_to_window(par->mlx, par->win, par->w, x, y); //draw land and wall
	}
	else if (a == 'P' || a == 'C' || a =='E') //if chracter is P,C or E
	{
		mlx_put_image_to_window(par->mlx, par->win, par->g, x, y);
		if (a == 'P')
			mlx_put_image_to_window(par->mlx, par->win, par->woodboy, x, y);
		else if (a == 'C')
			mlx_put_image_to_window(par->mlx, par->win, par->c, x, y);
		else if (a == 'E')
			mlx_put_image_to_window(par->mlx, par->win, par->e, x, y);
	}
}

int drawmap(t_param *par)
{
	t_mapline	*currline;
	char	*str;
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_clear_window(par->mlx, par->win); // erase all the images in window
	currline = par->map;
	while(currline)
	{
		str = currline->line;
		while( *str!='\n')
		{
			draw_img(*str, par, x, y);
			str++;
			x += par->wid;
            // 이미지가 그려질 x좌표값을 이미지의 너비만큼 증가시켜줌
		}
		currline = currline->next; // 다음 문자열로
		x = 0;
		y += par->hei;
        // 이미지가 그려질 y좌표값을 이미지의 높이만큼 증가시켜줌
	}
	return (0);
}
