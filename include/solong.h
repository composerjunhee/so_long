#ifndef SOLONG_H
# define SOLONG_H

#include "../libft/libft.h"
#include <mlx.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int keys(int keycode, t_vars *vars);
//int render_next_frame(void *vars);

#endif
