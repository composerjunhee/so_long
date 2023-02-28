#include "include/solong.h"

int keys(int keycode, t_vars *vars)
{
	if (keycode == 13)  // push W
	{
		printf("W, Move to the North -> %d\n", keycode);
	}
	else if (keycode == 1)  // push S
	{
		printf("S, Move to the South -> %d\n", keycode);
	}
	else if (keycode == 2)  // push D
	{
		printf("S, Move to the East -> %d\n", keycode);
	}
	else if (keycode == 0)  // push A
	{
		printf("A, Move to the West -> %d\n", keycode);
	}
	else if (keycode == 53)  // Destroy the window
	{
		printf("Escaped -> %d\n", keycode);
		mlx_destroy_window(vars->mlx, vars->win);
	}
	return (0);
}
