/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:47:33 by junheeki          #+#    #+#             */
/*   Updated: 2023/03/14 15:17:45 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/solong.h"

/*void	setting_img(t_game game)
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
				mlx_put_image_to_window(game.mlx, game.win, game.img.character, wid * 64, hei * 64);
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
*/
int	main(int argc, char **argv)
{
	t_game	game;

	int		img_width;
	int		img_height;

	//set_game(&game);
	if (argc != 2)
	{
		write(1, "We need Map file\n", 18);
		exit(1);
	}

	// game.str_line = NULL;
	// if (!(game.str_line = get_map(argv[1], &game)))
	// {
	// 	write(1, "Error\nInvalid map file.\n", 24);
	// 	exit(1);
	// }
	//malloc_map;
	(void)argv;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hey");
	//mlx_loop_hook(vars.mlx, render_next_frame, vars.mlx);
	game.img.collectible = mlx_xpm_file_to_image(game.mlx,
			"./images/collectible.xpm", &img_width, &img_height);
	game.img.wall = mlx_xpm_file_to_image(game.mlx, "./images/wall.xpm",
			&img_width, &img_height);
	game.img.land = mlx_xpm_file_to_image(game.mlx, "./images/grass.xpm",
			&img_width, &img_height);
	game.img.flower = mlx_xpm_file_to_image(game.mlx, "./images/flower01.xpm",
			&img_width, &img_height);
	game.img.exit = mlx_xpm_file_to_image(game.mlx, "./images/exit.xpm",
			&img_width, &img_height);

	//setting_img(game);
	mlx_put_image_to_window(game.mlx, game.win, game.img.wall, 0, 0);
	mlx_put_image_to_window(game.mlx, game.win, game.img.wall, 32, 0);
	mlx_put_image_to_window(game.mlx, game.win, game.img.collectible, 32, 0);
	mlx_put_image_to_window(game.mlx, game.win, game.img.land, 64, 0);
	mlx_put_image_to_window(game.mlx, game.win, game.img.flower, 64, 0);
	mlx_put_image_to_window(game.mlx, game.win, game.img.exit, 96, 0);
	mlx_put_image_to_window(game.mlx, game.win, game.img.flower, 128, 0);
	mlx_hook(game.win, KEY_RELEASE, 1L << 0, keys, &game);
	mlx_loop(game.mlx);
	return (0);
}
