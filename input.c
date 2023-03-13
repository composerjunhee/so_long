#include "include/solong.h"

int keys(int keycode, t_game *game)
{
	if (keycode == KEY_W)
	{
		printf("W, Move to the North -> %d\n", keycode);
	}
	else if (keycode == KEY_S)
	{
		printf("S, Move to the South -> %d\n", keycode);
	}
	else if (keycode == KEY_D)
	{
		printf("S, Move to the East -> %d\n", keycode);
	}
	else if (keycode == KEY_A)
	{
		printf("A, Move to the West -> %d\n", keycode);
	}
	else if (keycode == KEY_ESC)
	{
		printf("Escaped -> %d\n", keycode);
		mlx_destroy_window(game->mlx, game->win);
	}
	return (0);
}
