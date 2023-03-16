/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:22:52 by junheeki          #+#    #+#             */
/*   Updated: 2023/03/16 16:39:23 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/solong.h"

int drawmap(t_param *par)
{
	t_mapline	*currline;
	char	*str;
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_clear_window(par->mlx, par->win); // erase all the images in window
}
