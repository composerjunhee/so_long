#ifndef SOLONG_H
# define SOLONG_H
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define WINDOW_WIDTH 640
# define WINDOW_HEIGHT 640
# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_param
{
	int		x;
	int		y;
}			t_param;

// typedef struct s_vars
// {
// 	void	*mlx;
// 	void	*win;
// }			t_vars;

typedef struct s_img
{
	void	*collectible;
	void	*land;
	void	*wall;
	void	*exit;
	void	*flower;
	void	*character;
}			t_img;

typedef struct s_map
{
	int		width;
	int		height;
	char	**pos;
}			t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_map	map;
	int		wid;
	int		hei;
	char	*str_line;
	int		walk_counter;
}			t_game;

int			keys(int keycode, t_game *game);
void		map_read(char *filename, t_game *game);

#endif
