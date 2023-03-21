/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:05:25 by junheeki          #+#    #+#             */
/*   Updated: 2023/03/21 13:20:16 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/solong.h"

void	move_left(t_param *par, int y) // 왼쪽으로 이동
{
	t_mapline	*curline;
	char		*str;

	curline = par->map;
	while (y-- != 0)
		curline = curline->next;
        //플레이어의 y좌표에 해당하는 문자열로 이동
	str = curline->line;
	if (str[par->p_x - 1] == '1')
		return ;
        // 만약 이동할 위치가 1이라면 벽이므로 그냥 종료
	// else if (str[par->p_x - 1] == 'E')
	// 	if (get_e(par))
	// 		return ;
           	// 이동할 위치가 탈출구이고 조건이 맞다면 게임종료, 안맞다면 함수를 종료
	if (str[par->p_x - 1] == 'C')
		par->count_c--;
        // 이동할 위치가 수집품이라면 수집품 카운트를 줄여줌
	str[par->p_x - 1] = 'P';
    // 이동할 위치를 P로 바꿔주고
	str[par->p_x] = '0';
    // 원래 위치를 0으로 바꿔줌
	par->move++;
    // 이동횟수 1 증가
	set_p(par);
    // 플레이어의 좌표값을 수정해줌
}

void	move_right(t_param *par, int y) // 왼쪽으로 이동
{
	t_mapline	*curline;
	char		*str;

	curline = par->map;
	while (y-- != 0)
		curline = curline->next;
        //플레이어의 y좌표에 해당하는 문자열로 이동
	str = curline->line;
	if (str[par->p_x + 1] == '1')
		return ;
        // 만약 이동할 위치가 1이라면 벽이므로 그냥 종료
	// else if (str[par->p_x + 1] == 'E')
	// 	if (get_e(par))
	// 		return ;
           	// 이동할 위치가 탈출구이고 조건이 맞다면 게임종료, 안맞다면 함수를 종료
	if (str[par->p_x + 1] == 'C')
		par->count_c--;
        // 이동할 위치가 수집품이라면 수집품 카운트를 줄여줌
	str[par->p_x + 1] = 'P';
    // 이동할 위치를 P로 바꿔주고
	str[par->p_x] = '0';
    // 원래 위치를 0으로 바꿔줌
	par->move++;
    // 이동횟수 1 증가
	set_p(par);
    // 플레이어의 좌표값을 수정해줌
}

void	move_up(t_param *par, int y) // 위로 이동하는 함수
{
	t_mapline	*curline;
	char		*str;

	curline = par->map;
	str = curline->line;
	while (y != 0)
	{
		if (y == 1) // y가 1일때 즉 이동할 y좌표를 보고있을 때
		{
			if (str[par->p_x] == '1')
				return ;
                // 갈 위치가 1이라면 함수 종료
			// else if (str[par->p_x] == 'E')
			// 	if (get_e(par))
			// 		return ;
                    // 갈 위치가 E이고 탈출조건이 맞으면 게임종료 아니면 함수 종료
			if (str[par->p_x] == 'C')
				par->count_c--;
                // 갈 위치가 C라면 수집품 카운트 -1
			str[par->p_x] = 'P';
            // 갈 위치를 P로 변경해줌
		}
		curline = curline->next; // 다음 문자열로 (한줄 아래)
		str = curline->line;
		y--; // 반복마다 y값 감소
	}
	str[par->p_x] = '0'; // 현재문자열의  x좌표위치를 0으로 바꿈
	par->move++; // 이동횟수 1 증가
	set_p(par); // 플레이어 좌표 수정
}

void	move_down(t_param *par, int y) // 아래로 이동하는 함수
{
	t_mapline	*curline;
	char		*str;
	char		*savestr;

	curline = par->map;
	while (y != 0) // 현재 플레이어가 있는 y좌표까지 문자열 이동
	{
		curline = curline->next;
		y--;
	}
	savestr = curline->line; // 현재y좌표 문자열을 저장해둠
	curline = curline->next; // 다음 문자열로
	str = curline->line;
	if (str[par->p_x] == '1')
		return ;
        // 갈곳이 1이라면 함수 종료
	// else if (str[par->p_x] == 'E')
	// 	if (get_e(par))
	// 		return ;
            // 이동할 위치가 탈출구이고 조건이 맞다면 게임종료, 안맞다면 함수를 종료
	if (str[par->p_x] == 'C')
		par->count_c--;
        // 이동할 위치가 수집품이라면 수집품 카운트를 줄여줌
	str[par->p_x] = 'P';
    //이동할 위치를 P로 바꿔주고
	savestr[par->p_x] = '0';
    // 아까 저장해둔 현재문자열의  현재위치를 0으로 변경
	par->move++;
    // 이동횟수 증가
	set_p(par);
    // 플레이어 좌표 수정
}
