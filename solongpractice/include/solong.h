#ifndef SOLONG_H
# define SOLONG_H
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define PRESS_RED_BUTTON	17
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

typedef struct s_mapline
{
	void	*currline;
	void	*nextline;
	void	*next;
	void	*line;
	void	*curline;

}			t_mapline;

typedef struct s_param
{
	void *mlx;
	void *win;
	void *woodboy;
	void *g;
	void *w;
	void *e;
	void *c;
	int count_e;
	int count_p;
	int count_c;
	size_t fd;
	t_mapline *map;
	int	p_x;
	int p_y;
	int move;
	int	x;
	int	y;
	int wid;
	int hei;
	int win_width;
	int win_height;
	//int *map;
}	t_param;

int 	drawmap(t_param *par);
void 	draw_img(char a, t_param *par, int x, int y);
int		key_press(int keycode, t_param *param);
void	move_left(t_param *par, int y);
void	move_right(t_param *par, int y);
void	move_up(t_param *par, int y);
void	move_down(t_param *par, int y);
void	set_p(t_param *par);

#endif
