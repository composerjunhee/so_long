/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_re.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:15:18 by junheeki          #+#    #+#             */
/*   Updated: 2023/04/03 14:53:57 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/solong.h"

void	map_read(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		print_err("File Open Fail.\n");
	line = get_next_line(fd);
	game->hei = 0;
	game->walk_cnt = 0;
	game->wid = ft_strleni(line) - 1;
	game->str_line = ft_strdupn(line);
	free(line);
	while (line)
	{
		game->hei++;
		line = get_next_line(fd);
		if (line)
		{
			game->str_line = ft_strjoinn(game->str_line, line);
		}
	}
	close(fd);
}

int	**map_array(char *map, t_game *game)
{
	char	*str;
	int		fd;
	char	arr[2];

	arr[1] = '\0';
	str = NULL;
	game->map2d = (int **)malloc(game->hei * sizeof(int *));
	if(!game->map2d)
		return (0);
	game->x = -1;
	while (++game->x < game->hei)
		game->map2d[game->x] = (int *)malloc(game->wid * sizeof(int));
	game->x = 0;
	game->y = -1;
	game->z = -1;
	fd = open(map, O_RDONLY);
	while (++game->z < game->hei)
	{
		str = get_next_line(fd);
		while (str[++game->y] != '\n')
		{
			arr[0] = str[game->y];
			if (ft_strncmp(arr, "P", 1) == 0)
			{
				game->player_y = game->x;
				game->player_x = game->y;
				game->map2d[game->x][game->y] = 2;
			}
			else if (ft_strncmp(arr, "C", 1) == 0)
				game->map2d[game->x][game->y] = 3;
			else if (ft_strncmp(arr, "E", 1) == 0)
				game->map2d[game->x][game->y] = 4;
			else
				game->map2d[game->x][game->y] = ft_atoi(arr);
		}
		game->x++;
		game->y = -1;
		free(str);
	}
	return (game->map2d);
}

void	map_check(t_game *game)
{
	if (game->hei * game->wid != ft_strleni(game->str_line))
		print_err("Map must be rectangular.\n");
	map_check_wall(game);
	map_check_params(game);
}
