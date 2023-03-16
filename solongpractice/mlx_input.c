/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:51:41 by junheeki          #+#    #+#             */
/*   Updated: 2023/03/16 13:33:59 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/solong.h"

#define KEY_ESC	53
#define KEY_W	13
#define KEY_S	1
#define KEY_A	0
#define KEY_D	2
#define PRESS_RED_BUTTON	17

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
	ft_printf("y: %d x: %d\n", param->y, param->x);
	return (0);
}

int draw(t_param *loc)
{
	mlx_clear_window(loc->mlx, loc->win);
	mlx_put_image_to_window(loc->mlx, loc->win, loc->w, 0, 0);
	mlx_put_image_to_window(loc->mlx, loc->win, loc->w, 32, 0);
	mlx_put_image_to_window(loc->mlx, loc->win, loc->c, 32, 0);
	mlx_put_image_to_window(loc->mlx, loc->win, loc->g, 64, 0);
	mlx_put_image_to_window(loc->mlx, loc->win, loc->e, 96, 0);
	mlx_put_image_to_window(loc->mlx, loc->win, loc->woodboy, loc->x, loc->y);
	return(0);
}

int check_line_len(t_param *par)
{
	t_mapline *curline;
	int	before_line_len;
	int	curr_line_len;
	int	line_count;

	before_line_len = 0;
	line_count = 0;
	curline = par->map;
	before_line_len = ft_strlen(curline->line); //check number of letter in first line
	while(curline) // repeat till end of the line
	{
		line_count++; // line + 1
		curr_line_len = ft_strlen(curline->line); // check number of letters in current line
		if (before_line_len != curr_line_len)
			return (ft_printf("Different length. ERROR\n"));
		before_line_len = curr_line_len; // number of letters are matched
		curline = curline->next; //check next line
	}
	if (line_count >= 3) // if lines are lesser than 3
		return (line_count); //it's impossible to print everything resources
	return (ft_printf("Need 3 or more lines\n"));
}

int check_wall_end (char *str)
{
	while (*str != '\n')
	{
		if(*str != '1')
			return (ft_printf("We need only 1 for wall\n"));
		str++;
	}
	return (1);
}

int check_wall_middle(char *str)
{
	char a;
	if (*str != '1')
		return (ft_printf("There is no 1 at the beginning of the position\n"));
	while (*str != '\n')
	{
		a = *str;
		str++;
	}
	if (a != '1')
		return (ft_printf("There is no 1 at the end of the position.\n"));
	return (1);
}

int check_wall(t_param *par, int linenum)
{
	int	line_count;
	int	end_line;
	t_mapline	*curline;

	line_count = 0;
	end_line = linenum;
	curline = par->map;
	while (curline)// repeat till last line
	{
		if (line_count == 0 || line_count == end_line - 1) // firstline or last line
		{
			if(!check_wall_end(curline->line)) //if it's not 1, return error
				return (ft_printf("Wall is not covered yet\n"));
		}
		else
		{
			if(!check_wall_middle(curline->line))
				return (ft_printf("Check Middle Wall\n"));
		}
		line_count++;
		curline = curline->next;
	}
	return (1);
}

void	freemap(t_param *par) // free all allocated memory
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

int check_map(t_param *par)
{
	int map_line; //how many lines in map

	map_line = check_line_len(par); //check lines of map and save
	par->win_height = map_line * par -> hei; //calculate height of window and save;
	par->win_width = (ft_strlen(par->map->line) - 1) * par->wid; //calculate width of window
	if (map_line) // check number of lines
		if(check_wall(par, map_line))

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
		ft_printf("ERROR. Invalid Map File\n");
		return (0);
	}
	copymap(&par);
	mapstat = check_map(&par);
	if (mapstat == 0)
	{
		ft_printf("ERROR\n");
		freemap(&par);
		exit (0);
		return (0);
	}

	set_p(&par);
	par.win = mlx_new_window(par.mlx, par.win_width, par.win_height, "so_long");
	drawmap(&par);
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
