/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:55:21 by junheeki          #+#    #+#             */
/*   Updated: 2023/04/06 15:43:43 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/solong.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		print_err("ex) ./solong map.ber <- Follow the Format \n");
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		print_err("ex) ./solong map.ber <- Follow the Format \n");
	game = malloc(sizeof(t_game));
	game_init(game, argv[1]);
	game->map2d = map_array(argv[1], game);
	map_check(game);
	game_window(game);
	mlx_hook(game->win, KEY_PRESS, 0, &press_key, game);
	mlx_hook(game->win, PRESS_RED_BUTTON, 0, &exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}
