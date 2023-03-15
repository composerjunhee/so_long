/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:10:13 by junheeki          #+#    #+#             */
/*   Updated: 2023/03/15 09:25:28 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/solong.h"

void	set_param(t_game *game)
{
	t_map *map;
	t_player player;


	game->fd = open("maps/map.ber", O_RDONLY);
	if (game->fd <= 0)
		return ;
	map->save = NULL; // map을 불러와서 저장할 공간
	game->count_e = 0; // 탈출구의 갯수
	game->count_p = 0; // 시작지점의 갯수
	game->count_c = 0; // 수집품의 갯수
	game->wid = 0; // 윈도우의 너비
	game->hei = 0; // 윈도우의 높이
	game->x = 0; // 이미지의 x축 크기
	game->y = 0; // 이미지의 y축 크기
	game->count_move = 0; // 이동 횟수
	game.player->player_x = 0; // 플레이어의 x좌표
	game.player->player_y = 0; // 플레이어의 y좌표
	game->mlx = mlx_init(); // mlx
	game.img->land = mlx_xpm_file_to_image(par->mlx, "imgs/g.xpm", &par->wi, &par->he);// 땅 이미지
	img->wall = mlx_xpm_file_to_image(par->mlx, "imgs/r.xpm", &par->wi, &par->he);// 벽 이미지
	img->collectible = mlx_xpm_file_to_image(par->mlx, "imgs/c.xpm", &par->wi, &par->he);// 수집품 이미지
	img->exit = mlx_xpm_file_to_image(par->mlx, "imgs/e.xpm", &par->wi, &par->he);// 탈출구 이미지
	img->player = mlx_xpm_file_to_image(par->mlx, "imgs/p.xpm", &par->wi, &par->he);// 플레이어 이미지
	game->win = NULL;// 윈도우
}

