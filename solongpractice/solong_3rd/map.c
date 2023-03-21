/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:20:31 by junheeki          #+#    #+#             */
/*   Updated: 2023/03/21 16:49:44 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/solong.h"

void map_read(char *filename, t_game *game)
{
	int	fd;
	char *line;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		print_err("File Open Fail.\n");
	line = get_next_line(fd);
	game->hei = 0;
	game->walk_cnt = 0;
	game->wid = ft_strleni(line) - 1;
	game->str_line = ft_strdupn(line);
	free(line);
	while(line)
	{
		game->hei++;
		line = get_next_line(fd);
		if(line)
		{
			game->str_line = ft_strjoinn(game->str_line, line);
		}
	}
	close(fd);
}

void	map_check_wall(t_game *game)
{
	int		i;

	i = 0;
	while (i < ft_strleni(game->str_line))
	{
		if (i < game->wid)
		{
			if (game->str_line[i] != '1')
				print_err("Map must be closed/surrounded by walls\n");
		}
		else if (i % game->wid == 0 || i % game->wid == game->wid - 1)
		{
			if (game->str_line[i] != '1')
				print_err("Map must be closed/surrounded by walls\n");
		}
		else if (i > ft_strleni(game->str_line) - game->wid)
		{
			if (game->str_line[i] != '1')
				print_err("Map must be closed/surrounded by walls\n");
		}
		i++;
	}
}

void	map_check_params(t_game *game)
{
	int	i;
	int	num_e;
	int	num_p;

	i = 0;
	num_e = 0;
	num_p = 0;
	game->all_col = 0;
	game->col_cnt = 0;
	while (i++ < ft_strleni(game->str_line))
	{
		if (game->str_line[i] == 'E')
			num_e++;
		else if (game->str_line[i] == 'P')
			num_p++;
		else if (game->str_line[i] == 'C')
			game->all_col++;
	}
	if (num_e == 0)
		print_err("Map must have at least one exit\n");
	if (game->all_col == 0)
		print_err("Map must have at least one collectible\n");
	if (num_p != 1)
		print_err("Map must have one starting position\n");
}

void	map_check(t_game *game)
{
	if (game->hei * game->wid != ft_strleni(game->str_line))
		print_err("Map must be rectangular.\n");
	map_check_wall(game);
	map_check_params(game);
}
