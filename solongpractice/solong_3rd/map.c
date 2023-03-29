/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:20:31 by junheeki          #+#    #+#             */
/*   Updated: 2023/03/29 17:51:00 by junheeki         ###   ########.fr       */
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

void	map_check_wall(t_game *game)
{
	int	i;

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
		{
			num_e++;
			if(num_e == 1)
			{
				game->map_end = malloc(sizeof(int) * 2);
				game->map_end[0] = i % game->wid; // X
				game->map_end[1] = i / game->wid; // Y
			}
			else
				print_err("Map must have at least one exit\n");
		}
		else if (game->str_line[i] == 'P')
		{
			num_p++;
			{
				if(num_p == 1)
				{
					game->map_start = malloc(sizeof(int) * 2);
					game->map_start[0] = i % game->wid; // X
					game->map_start[1] = i / game->wid; // Y
				}
				else
					print_err("Map must have one starting position\n");
			}
		}
		else if (game->str_line[i] == 'C')
			game->all_col++;
	}
	if (game->all_col == 0)
		print_err("Map must have at least one collectible\n");
}

// // pathfinding function
// queue = pos
// rear = back
int	pathfinding(t_game *game, int start, int end)
{
	printf("start: %d\n", start);
	if (start < 0 || start >= game->wid * game->hei)
		return (0);
	if (end < 0 || end >= game->wid * game->hei)
		return (0);

	int	*pos;
	int	visited[game->wid * game->hei];
	int	parent[game->wid * game->hei];
	int front = 0;
	int back = 0;
	int curr;
	int next;
	int i;

	if (!game || game->wid <= 0 || game->hei <= 0 || !game->str_line)
		return (0);
	pos = malloc(sizeof(int) * game->wid * game->hei);
	if (!pos)
		print_err("MEMORY ERROR.\n");

// initialize visited and parent arrays
	i = 0;
	while (i < game->wid * game->hei - 1)
	{
		visited[i] = 0;
		parent[i] = -1;
    	i++;
	}
	pos[back] = start; //start from the player's position
	back++;
	visited[start] = 1;

	while (front <= back)
	{
		printf("front: %d back: %d curr: %d end: %d\n", front, back, curr, end);
		curr = pos[front];
		front++;

		if (curr == end)
		{
			printf("THIS ENDED HERE AND RETURNED 1\n");
			free(pos);
			return(1);
		}
		//Check North
		next = curr - game->wid;
		printf("NORTH: next: %d gameline: %d visitd: %d\n", next, game->str_line[next], visited[next]);
		if (next >= 0 && game->str_line[next] == '0' && !visited[next])
		{
			pos[back] = next;
			back++;
			parent[next] = curr;
			visited[next] = 1;
			printf("back: %d\n", back);
			//pathfinding(game)
		}
		// check south neighbor
		next = curr + game->wid;
		printf("SOUTH: next: %d gameline: %d visitd: %d\n", next, game->str_line[next], visited[next]);
		if (next < game->wid * game->hei && game->str_line[next] == '0'
				&& !visited[next])
		{
			pos[back] = next;
			back++;
			parent[next] = curr;
			visited[next] = 1;
		}

		// check west neighbor
		next = curr - 1;
		if (curr % game->wid > 0 && game->str_line[next] == '0' && !visited[next])
		{
			pos[back] = next;
			back++;
			parent[next] = curr;
			visited[next] = 1;
		}

		// check east neighbor
		next = curr + 1;
		if (curr % game->wid < game->wid - 1 && game->str_line[next] == '0'
				&& !visited[next])
		{
			pos[back] = next;
			back++;
			parent[next] = curr;
			visited[next] = 1;
		}
	}
	printf("front: %d back: %d end: %d\n", front, back, end);
	free(pos);
	return (0);
}

void	map_check(t_game *game)
{
	int start;
	int end;

	if (game->hei * game->wid != ft_strleni(game->str_line))
		print_err("Map must be rectangular.\n");
	map_check_wall(game);
	map_check_params(game);
	start = game->map_start[1] * game->wid + game->map_start[0];
	printf("start: %d x: %d y: %d\n", start, game->map_start[0], game->map_start[1]);
	end = game->map_end[1] * game->wid + game->map_end[0];
	if(!pathfinding(game, start, end))
	{
		printf("Error: Player cannot reach the exit.\n");
		free(game->str_line);
		exit(1);
	}
}
