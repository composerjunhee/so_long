/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:51:21 by junheeki          #+#    #+#             */
/*   Updated: 2023/04/12 14:35:55 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/solong.h"

t_point get_screen_size(t_game *game)
{
    t_point point;

    mlx_get_screen_size(game->mlx, &point.x, &point.y);
    return (point);
}

bool larger_window(t_game *game)
{
    t_point screen_size;

    screen_size = get_screen_size(game);
    return (\
	((game->m.wid * 32) > screen_size.x) \
	|| \
	((game->plot.hei * 32) > screen_size.y) \
	);
}