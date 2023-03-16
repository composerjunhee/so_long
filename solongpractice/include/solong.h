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

// typedef struct s_param
// {
// 	int			x;
// 	int			y;
// }				t_param;

// typedef struct s_img
// {
// 	void		*collectible;
// 	void		*land;
// 	void		*wall;
// 	void		*exit;
// 	void		*flower;
// 	void		*player;
// }				t_img;

// typedef struct s_map
// {
// 	int			width;
// 	int			height;
// 	char		**pos;
// 	int			save;
// }				t_map;

// typedef struct s_player
// {
// 	int			player_x;
// 	int			player_y;
// 	int			col_counter;
// 	int			key_block;
// }				t_player;

// typedef struct s_game
// {
// 	void		*mlx;
// 	void		*win;
// 	t_img		img;
// 	t_map		map;
// 	t_player	player;
// 	int			count_e;
// 	int			count_p;
// 	int			count_c;
// 	int			wid;
// 	int			hei;
// 	int			x;
// 	int			y;
// 	char		*str_line;
// 	int			count_move;
// }				t_game;

// int				keys(int keycode, t_game *game);
// void			map_read(char *filename, t_game *game);
// void			exit_event(t_game *game);
// void			setting_img(t_game game);
// int invalid_ext(char *filename);
// void malloc_map(t_game *game, char *filename);
// void	is_walled(t_game *game);

typedef struct s_mapline
{
	void	*currline;
	void	*nextline;
	void	*next;
	void	*line;
	void	*curline;

}			t_mapline;

#endif
