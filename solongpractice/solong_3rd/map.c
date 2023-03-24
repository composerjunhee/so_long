/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:20:31 by junheeki          #+#    #+#             */
/*   Updated: 2023/03/24 16:36:42 by junheeki         ###   ########.fr       */
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
	game->wid = ft_strlen(line) - 1;
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

// // pathfinding function
// int pathfinding(t_game *game, int start, int end)
// {
// 	int *queue;
// 	int visited[game->wid * game->hei];
// 	int parent[game->wid * game->hei];
// 	int front = 0, rear = 0;
// 	int curr, next;

// 	queue = malloc(sizeof(int) * game->wid * game->hei);
// 	if (!queue)
// 		print_err("Memory allocation error.\n");

// 	// initialize visited and parent arrays
// 	for (int i = 0; i < game->wid * game->hei; i++)
// 	{
// 		visited[i] = 0;
// 		parent[i] = -1;
// 	}

// 	// start from the player's position
// 	queue[rear++] = start;
// 	visited[start] = 1;

// 	while (front < rear)
// 	{
// 		curr = queue[front++];

// 		if (curr == end)
// 		{
// 			free(queue);
// 			return 1;
// 		}

// 		// check north neighbor
// 		next = curr - game->wid;
// 		if (next >= 0 && game->str_line[next] == 0 && !visited[next])
// 		{
// 			queue[rear++] = next;
// 			parent[next] = curr;
// 			visited[next] = 1;
// 		}

// 		// check south neighbor
// 		next = curr + game->wid;
// 		if (next < game->wid * game->hei && game->str_line[next] == 0 && !visited[next])
// 		{
// 			queue[rear++] = next;
// 			parent[next] = curr;
// 			visited[next] = 1;
// 		}

// 		// check west neighbor
// 		next = curr - 1;
// 		if (curr % game->wid > 0 && game->str_line[next] == 0 && !visited[next])
// 		{
// 			queue[rear++] = next;
// 			parent[next] = curr;
// 			visited[next] = 1;
// 		}

// 		// check east neighbor
// 		next = curr + 1;
// 		if (curr % game->wid < game->wid - 1 && game->str_line[next] == 0 && !visited[next])
// 		{
// 			queue[rear++] = next;
// 			parent[next] = curr;
// 			visited[next] = 1;
// 		}
// 	}

// 	free(queue);
// 	return 0;
// }

void	map_check(t_game *game)
{
	if (game->hei * game->wid != ft_strleni(game->str_line))
		print_err("Map must be rectangular.\n");
	map_check_wall(game);
	map_check_params(game);
	// pathfinding(game, 'P', 'E');
}
