#include "include/solong.h"

void	map_read(char *filename, t_game *game)
{
	int  fd;
	char *line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	game->map.height = 0;
	game->map.width = ft_strlen(line) - 1;
	game->str_line = ft_strdup(line);
	free(line);
	while (line)
	{
		game->map.hei++;
		line = get_next_line(fd);
		if (line)
		{
			game->str_line = ft_strjoin(game->str_line, line);
		}
	}
	close(fd);
	printf("%s\n", game->str_line);
}
