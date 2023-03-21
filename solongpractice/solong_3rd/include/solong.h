#ifndef SOLONG_H
# define SOLONG_H
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define PRESS_RED_BUTTON 17
# define KEY_PRESS 2
# define KEY_RELEASE 3

# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>

typedef struct s_img
{
	void	*player;
	void	*collectible;
	void	*land;
	void	*wall;
	void	*exit;
}			t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		wid;
	int		hei;
	char	*str_line;
	int		all_col;
	int		col_cnt;
	int		walk_cnt;
}			t_game;

//image.c
t_img	img_init(void *mlx);
void put_img(t_game *g, int w, int h);
void setting_img(t_game *game);

//keycode.c

int			clear_game(t_game *game);
void		move_w(t_game *g);
void		move_a(t_game *g);
void		move_s(t_game *g);
void		move_d(t_game *g);

//solong.c
void		print_err(char *message);
void		game_init(t_game *g, char *map);
int			exit_game(t_game *game);
int			press_key(int key_code, t_game *game);
int			main(int argc, char **argv);

#endif
