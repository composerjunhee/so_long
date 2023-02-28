#include "include/solong.h"

// typedef struct s_info
// {

// }

// int	print_map(t_info *info)
// {
// 	int	row;
// 	int	col;

// 	row = -1;
// 	while (++row < info->map.row)
// 	{
// 		col = -1;
// 		while (++col < info->map.col)
// 		{
// 			put_img(info, row, col);
// 		}
// 	}
// 	return (0);
// }

//int render_next_frame(void *vars);

int	main()
{
	t_vars	vars;

	void	*img;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	int		img_width;
	int		img_height;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hey");
	//mlx_loop_hook(vars.mlx, render_next_frame, vars.mlx);
	img = mlx_xpm_file_to_image(vars.mlx, "./images/collectible.xpm", &img_width,
			&img_height);
	img2 = mlx_xpm_file_to_image(vars.mlx, "./images/wall.xpm", &img_width,
			&img_height);
	img3 = mlx_xpm_file_to_image(vars.mlx, "./images/flower01.xpm", &img_width,
			&img_height);
	img4 = mlx_xpm_file_to_image(vars.mlx, "./images/grass.xpm", &img_width,
			&img_height);
	img5 = mlx_xpm_file_to_image(vars.mlx, "./images/exit.xpm", &img_width,
			&img_height);
	mlx_put_image_to_window(vars.mlx, vars.win, img2, 0, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, img2, 32, 0);
	mlx_put_image_to_window(vars.mlx, vars.win, img4, 64, 0);
	mlx_hook(vars.win, 2, 1L<<0, keys, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
