#ifndef SOLONG_H
# define SOLONG_H
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_PRESS 2
# define KEY_RELEASE 3

# include "../libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_param
{
	int		x;
	int		y;
}			t_param;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

int			keys(int keycode, t_vars *vars);
//int render_next_frame(void *vars);

#endif
