/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:57:05 by junheeki          #+#    #+#             */
/*   Updated: 2023/04/12 14:38:39 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/solong.h"

int	clear_game(t_game *g)
{
	g->walk_cnt++;
	ft_printf("%s %d%s\n", "Succesfully escaped!", g->walk_cnt, "steps.");
	exit(0);
}

void	move_w(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < ft_strleni(g->map_line))
	{
		if (g->map_line[i] == 'P')
			break ;
	}
	if (g->map_line[i - g->m.wid] == 'C')
		g->m.col_cnt++;
	if (g->map_line[i - g->m.wid] == 'E' && g->m.all_col == g->m.col_cnt)
		clear_game(g);
	else if (g->map_line[i - g->m.wid] != '1' && g->map_line[i
			- g->m.wid] != 'E')
	{
		g->map_line[i] = '0';
		g->map_line[i - g->m.wid] = 'P';
		g->walk_cnt++;
		ft_printf("%d\n", g->walk_cnt);
		setting_img(g);
	}
}

void	move_a(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < ft_strleni(g->map_line))
	{
		if (g->map_line[i] == 'P')
			break ;
	}
	if (g->map_line[i - 1] == 'C')
		g->m.col_cnt++;
	if (g->map_line[i - 1] == 'E' && g->m.all_col == g->m.col_cnt)
		clear_game(g);
	else if (g->map_line[i - 1] != '1' && g->map_line[i - 1] != 'E')
	{
		g->map_line[i] = '0';
		g->map_line[i - 1] = 'P';
		g->walk_cnt++;
		ft_printf("%d\n", g->walk_cnt);
		setting_img(g);
	}
}

void	move_s(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < ft_strleni(g->map_line))
	{
		if (g->map_line[i] == 'P')
			break ;
	}
	if (g->map_line[i + g->m.wid] == 'C')
		g->m.col_cnt++;
	if (g->map_line[i + g->m.wid] == 'E' && g->m.all_col == g->m.col_cnt)
		clear_game(g);
	else if (g->map_line[i + g->m.wid] != '1' && g->map_line[i
			+ g->m.wid] != 'E')
	{
		g->map_line[i] = '0';
		g->map_line[i + g->m.wid] = 'P';
		g->walk_cnt++;
		ft_printf("%d\n", g->walk_cnt);
		setting_img(g);
	}
}

void	move_d(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < ft_strleni(g->map_line))
	{
		if (g->map_line[i] == 'P')
			break ;
	}
	if (g->map_line[i + 1] == 'C')
		g->m.col_cnt++;
	if (g->map_line[i + 1] == 'E' && g->m.all_col == g->m.col_cnt)
		clear_game(g);
	else if (g->map_line[i + 1] != '1' && g->map_line[i + 1] != 'E')
	{
		g->map_line[i] = '0';
		g->map_line[i + 1] = 'P';
		g->walk_cnt++;
		ft_printf("%d\n", g->walk_cnt);
		setting_img(g);
	}
}
