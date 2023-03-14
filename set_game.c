/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:10:13 by junheeki          #+#    #+#             */
/*   Updated: 2023/03/14 16:49:46 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	set_param(t_param *par)
{
	par->fd = open("maps/map.ber", O_RDONLY);
	if (par->fd <= 0)
		return ;
	par->map = NULL; // map을 불러와서 저장할 공간
	par->count_e = 0; // 탈출구의 갯수
	par->count_p = 0; // 시작지점의 갯수
	par->count_c = 0; // 수집품의 갯수
	par->win_width = 0; // 윈도우의 너비
	par->win_height = 0; // 윈도우의 높이
	par->x = 0; // 이미지의 x축 크기
	par->y = 0; // 이미지의 y축 크기
	par->count_move = 0; // 이동 횟수
	par->p_x = 0; // 플레이어의 x좌표
	par->p_y = 0; // 플레이어의 y좌표
	par->mlx = mlx_init(); // mlx
	par->g = mlx_xpm_file_to_image(par->mlx, "imgs/g.xpm", &par->wi, &par->he);// 땅 이미지
	par->w = mlx_xpm_file_to_image(par->mlx, "imgs/r.xpm", &par->wi, &par->he);// 벽 이미지
	par->c = mlx_xpm_file_to_image(par->mlx, "imgs/c.xpm", &par->wi, &par->he);// 수집품 이미지
	par->e = mlx_xpm_file_to_image(par->mlx, "imgs/e.xpm", &par->wi, &par->he);// 탈출구 이미지
	par->p = mlx_xpm_file_to_image(par->mlx, "imgs/p.xpm", &par->wi, &par->he);// 플레이어 이미지
	par->win = NULL;// 윈도우
}

