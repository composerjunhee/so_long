// #include <mlx.h>
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// int keys(int keycode, t_vars *vars)
// {
// 	if (keycode == 13)  // push W
// 	{
// 		printf("W, Move to the North -> %d\n", keycode);
// 	}
// 	else if (keycode == 1)  // push S
// 	{
// 		printf("S, Move to the South -> %d\n", keycode);
// 	}
// 	else if (keycode == 2)  // push D
// 	{
// 		printf("S, Move to the East -> %d\n", keycode);
// 	}
// 	else if (keycode == 0)  // push A
// 	{
// 		printf("A, Move to the West -> %d\n", keycode);
// 	}
// 	else if (keycode == 53)  // Destroy the window
// 	{
// 		printf("Escaped -> %d\n", keycode);
// 		mlx_destroy_window(vars->mlx, vars->win);
// 	}
// 	return (0);
// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
// 	mlx_hook(vars.win, 2, 1L<<0, keys, &vars);
// 	mlx_loop(vars.mlx);
// }
