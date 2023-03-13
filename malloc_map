#include "include/solong.h"

int invalid_ext(char *filename)  //Check Name "ber"
{
	char *temp;

	temp = ft_strnstr(filename, ".ber", ft_strlen(filename));
	if (temp == NULL)
		return (1);
	else if (ft_strlen(temp) > 4)
		return (1);
	else
		return (0);
}

void malloc_map(t_game *game, char *filename)
{
	char *line;
	int	fd;
	int	i;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	game->map.height = 0;
	game->map.width = ft_strlen(line) - 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		game->map.height++;
	}
	close(fd);
	game->map.pos = (char **)malloc(game->map.height * sizeof(char *));
	i = -1;
	while (++i < game->map.height)
		game->map.pos[i] = (char *)malloc(game->map.width * sizeof(char *));
	while (1) //Check Square
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (game->map.width != ft_strlen(line))
		free(line);
	}
}
void	is_walled(t_game *game) //Wall Checking
{
	int	i;

	i = -1;
	while (++i < game->map.height)
		if (game->map.pos[i][0] != '1' || \
				game->map.pos[i][game->map.width - 1] != '1')
			write(1,"Not Walled\n", 11);
			exit(1);
	i = -1;
	while (++i < game->map.width)
		if (game->map.pos[0][i] != '1' || \
				game->map.pos[game->map.height - 1][i] != '1')
			write(1,"Not Walled\n", 11);
			exit(1);
}
