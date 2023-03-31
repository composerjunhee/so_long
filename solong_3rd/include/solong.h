/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:23:48 by junheeki          #+#    #+#             */
/*   Updated: 2023/03/31 17:05:28 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include <stdlib.h>
# include <unistd.h>

typedef struct s_img
{
	void	*player;
	void	*col;
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
	int		all_col2d;
	int		col_cnt;
	int		walk_cnt;
	int		start;
	int		end;
	int		**map2d;
	int		x;
	int		y;
	int		z;
	int		validity;
	int		reach_exit;
	int		player_x;
	int		player_y;
}			t_game;

//util.c
int			ft_strleni(const char *str);
char		*ft_strdupn(char *s);
int			ft_strlcpyn(char *dst, char *src, int len);
char		*ft_strjoinn(char *s1, char *s2);

//map_re.c
void		map_read(char *filename, t_game *game);
int			**map_array(char *map, t_game *game);
void		map_check(t_game *game);

//image.c
t_img		img_init(void *mlx);
void		put_img(t_game *game, int w, int h);
void		setting_img(t_game *game);

//keycode.c

int			clear_game(t_game *game);
void		move_w(t_game *g);
void		move_a(t_game *g);
void		move_s(t_game *g);
void		move_d(t_game *g);

//solong.c
void		print_err(char *message);
void		game_init(t_game *game, char *map);
int			exit_game(t_game *game);
int			press_key(int key_code, t_game *game);

//map_check.c
void	map_check_params(t_game *game);
void	map_check_wall(t_game *game);

void	game_window(t_game *g);

//map_validpath.c
void	check_valid_path(int column, int row, int **map, t_game *g);
#endif
