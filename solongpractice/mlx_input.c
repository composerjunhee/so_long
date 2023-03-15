/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:51:41 by junheeki          #+#    #+#             */
/*   Updated: 2023/03/15 17:17:27 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/solong.h"

#define KEY_ESC	53
#define KEY_W	13
#define KEY_S	1
#define KEY_A	0
#define KEY_D	2
#define PRESS_RED_BUTTON	17

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
	int	p_x;
	int p_y;
	int move;
	int	x;
	int	y;
	int wid;
	int hei;
	int win_width;
	int win_height;
	int *map;
}	t_param;

void param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
}

int	key_press(int keycode, t_param *param)
// 입력에따라 좌표로 사용할 값을 증감시킴
{
	if (keycode == KEY_W && param->y != 0)
		param->y -= param->hei;
	if (keycode == KEY_S && param->y != 800)
		param->y += param->hei;
	else if (keycode == KEY_A && param->x != 0)
		param->x -= param->wid;
	else if (keycode == KEY_D && param->x != 800)
		param->x += param->wid;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("y: %d x: %d\n", param->y, param->x);
	return (0);
}

int draw(t_param *loc)
{
	mlx_clear_window(loc->mlx, loc->win);
	mlx_put_image_to_window(loc->mlx, loc->win, loc->g, 64, 0);
	mlx_put_image_to_window(loc->mlx, loc->win, loc->w, 0, 0);
	mlx_put_image_to_window(loc->mlx, loc->win, loc->w, 32, 0);
	mlx_put_image_to_window(loc->mlx, loc->win, loc->c, 32, 0);
	mlx_put_image_to_window(loc->mlx, loc->win, loc->g, 64, 0);
	mlx_put_image_to_window(loc->mlx, loc->win, loc->e, 96, 0);
	mlx_put_image_to_window(loc->mlx, loc->win, loc->woodboy, loc->x, loc->y);

	return(0);
}

void	freemap(t_param *par) // 여태 할당한 저장공간을 모두 해제해줌
{
	t_mapline	*currline;
	t_mapline	*nextline;

	currline = par->map;
	while (currline) // 연결리스트의 끝까지 순회
	{
		nextline = currline->next; // 할당 해제 전 다음 연결리스트를 미리 가져옴
		free (currline->line); // 내부에 들어있는 line부터 해제
		free (currline); // 현재 공간을 해제
		currline = nextline; // 다음 연결리스트로 이동
	}
	free (currline); // 마지막에 보고있던 저장공간 해제
}

int copymap(t_param *par)
{
	char *str;
	str = get_next_line(par->fd); //read mapfile with GNL
	{
		copyline(str, par); //copy line and put int linked list
		free(str);
		str = get_next_line(par->fd);
	}
	free (str);
	return (1);
}

int copyline(char *str, t_param *par)
{
	t_mapline *line;
	t_mapline *currline;

	currline = par->map;
	line = malloc(sizeof(t_mapline));
	if(!line)
	{
		freemap(par);
		return(0);
	}
	line->next = NULL;
	line->line = ft_strdup(str);
	if (par->map == NULL) // 연결리스트의 첫 부분이 NULL이라면
		par->map = line; // 시작의 line에 바로 넣어줌
	else
	{
		while (currline->next != NULL) // 연결리스트의 끝까지 이동
			currline = currline->next;
		currline->next = line; // 문자열을 넣어줌
	}
	return (1);
}

void set_param(t_param *par)
{
	par->fd = open("maps/map.ber", O_RDONLY);
	if (par->fd <= 0)
		return ;
	par->map = NULL;
	par->count_e = 0;
	par->count_c = 0;
	par->count_p = 0;
	par->win_width = 0;
	par->win_height = 0;
	par->x = 0;
	par->y = 0;
	par-> move = 0;
	par-> p_x = 0;
	par-> p_y = 0;
	par->mlx = mlx_init();
	par->g = mlx_xpm_file_to_image(par->mlx, "imgs/grass.xpm", &par->wid, &par->hei);
	par->w = mlx_xpm_file_to_image(par->mlx, "imgs/wall.xpm", &par->wid, &par->hei);
	par->c = mlx_xpm_file_to_image(par->mlx, "imgs/collectible.xpm", &par->wid, &par->hei);
	par->e = mlx_xpm_file_to_image(par->mlx, "imgs/exit.xpm", &par->wid, &par->hei);
	par->woodboy = mlx_xpm_file_to_image(par->mlx, "imgs/woodboy.xpm", &par->wid, &par->hei);
	par->win = NULL;
}

int main(void)
{
	t_param	par;
	int	mapstat;

	set_param(&par);
	if (par.fd <= 0)
	{
		write(1, "ERROR. Invalid Map File\n", 25);
		return (0);
	}
	copymap(&par);

	par.mlx = mlx_init();
	par.win = mlx_new_window(par.mlx, par.win_width, par.win_height, "so_long");
	par.x = 0;
	par.y = 0;
	par.woodboy =mlx_xpm_file_to_image(par.mlx, "images/woodboy.xpm", &par.wid, &par.hei);
	par.c = mlx_xpm_file_to_image(par.mlx,
			"./images/collectible.xpm", &par.wid, &par.hei);
	par.w = mlx_xpm_file_to_image(par.mlx, "./images/wall.xpm",
			&par.wid, &par.hei);
	par.g = mlx_xpm_file_to_image(par.mlx, "./images/grass.xpm",
			&par.wid, &par.hei);
	par.e = mlx_xpm_file_to_image(par.mlx, "./images/exit.xpm",
			&par.wid, &par.hei);

	mlx_key_hook(par.win, &key_press, &par);
	mlx_loop_hook(par.mlx, &draw, &par);
	mlx_loop(par.mlx);
	return(0);
}
