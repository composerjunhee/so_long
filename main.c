#include "include/solong.h"

int	main(int argc, char **argv)
{
	t_game	game;
	t_img	image;

	int		img_width;
	int		img_height;

	if (argc != 2)
	{
		write(1,"We need Map file\n", 17);
		exit(1);
	}

	//map_read;

	(void)argv;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Hey");
	//mlx_loop_hook(vars.mlx, render_next_frame, vars.mlx);
	image.collectible = mlx_xpm_file_to_image(game.mlx, "./images/collectible.xpm", &img_width,
			&img_height);
	image.wall= mlx_xpm_file_to_image(game.mlx, "./images/wall.xpm", &img_width,
			&img_height);
	image.land = mlx_xpm_file_to_image(game.mlx, "./images/grass.xpm", &img_width,
			&img_height);
	image.flower = mlx_xpm_file_to_image(game.mlx, "./images/flower01.xpm", &img_width,
			&img_height);
	image.exit = mlx_xpm_file_to_image(game.mlx, "./images/exit.xpm", &img_width,
			&img_height);
	mlx_put_image_to_window(game.mlx, game.win, image.wall, 0, 0);
	mlx_put_image_to_window(game.mlx, game.win, image.wall, 32, 0);
	mlx_put_image_to_window(game.mlx, game.win, image.land, 64, 0);
	mlx_put_image_to_window(game.mlx, game.win, image.exit, 96, 0);
	mlx_put_image_to_window(game.mlx, game.win, image.flower, 128, 0);
	mlx_hook(game.win, KEY_RELEASE, 1L<<0, keys, &game);
	mlx_loop(game.mlx);
	return (0);
}
