/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:32:39 by junheeki          #+#    #+#             */
/*   Updated: 2023/03/15 09:36:04 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int main(void)
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "Hello");
	mlx_loop(mlx);
}
