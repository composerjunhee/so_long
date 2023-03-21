/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:54:27 by junheeki          #+#    #+#             */
/*   Updated: 2023/03/21 16:37:28 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/solong.h"

int clear_game(t_game *game)
{
	game->walk_cnt++;
	printf("%s %d%s\n", "You are succesfully escaped!", game->walk_cnt, "steps.");
	exit(0);
}

void move_w(t_game *g)
{
	int	i;

	i = 0;
	while(i++ < ft_strleni(g->str_line))
	{
		if(g->str_line[i] == 'P') //startpoint
			break ;
	}
	if (g->str_line[i - g->wid] == 'C') //collectible
		g->col_cnt++;
	if (g->str_line[i - g->wid] == 'E' && g->all_col == g->col_cnt)  //winning condition
		clear_game(g);
	else if (g->str_line[i - g->wid] != '1' && g->str_line[i - g->wid] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i - g->wid] = 'P';
		g->walk_cnt++;
		ft_printf("%d\n", g->walk_cnt);
		setting_img(g);
	}
}

void move_a(t_game *g)
{
	int	i;

	i = 0;
	while(i++ < ft_strleni(g->str_line))
	{
		if(g->str_line[i] == 'P') //startpoint
			break ;
	}
	if (g->str_line[i - 1] == 'C') //collectible
		g->col_cnt++;
	if (g->str_line[i - 1] == 'E' && g->all_col == g->col_cnt)  //winning condition
		clear_game(g);
	else if (g->str_line[i - 1] != '1' && g->str_line[i - 1] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i - 1] = 'P';
		g->walk_cnt++;
		ft_printf("%d\n", g->walk_cnt);
		setting_img(g);
	}
}

void move_s(t_game *g)
{
	int	i;

	i = 0;
	while(i++ < ft_strleni(g->str_line))
	{
		if(g->str_line[i] == 'P') //startpoint
			break ;
	}
	if (g->str_line[i + g->wid] == 'C') //collectible
		g->col_cnt++;
	if (g->str_line[i + g->wid] == 'E' && g->all_col == g->col_cnt)  //winning condition
		clear_game(g);
	else if (g->str_line[i + g->wid] != '1' && g->str_line[i + g->wid] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i + g->wid] = 'P';
		g->walk_cnt++;
		ft_printf("%d\n", g->walk_cnt);
		setting_img(g);
	}
}

void move_d(t_game *g)
{
	int	i;

	i = 0;
	while(i++ < ft_strleni(g->str_line))
	{
		if(g->str_line[i] == 'P') //startpoint
			break ;
	}
	if (g->str_line[i + 1] == 'C') //collectible
		g->col_cnt++;
	if (g->str_line[i + 1] == 'E' && g->all_col == g->col_cnt)  //winning condition
		clear_game(g);
	else if (g->str_line[i + 1] != '1' && g->str_line[i + 1] != 'E')
	{
		g->str_line[i] = '0';
		g->str_line[i + 1] = 'P';
		g->walk_cnt++;
		ft_printf("%d\n", g->walk_cnt);
		setting_img(g);
	}
}
