/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:18:38 by junheeki          #+#    #+#             */
/*   Updated: 2023/02/27 15:00:14 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unsigned_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

void	ft_put_unsigned(unsigned int num)
{
	if (num >= 10)
		ft_put_unsigned(num / 10);
	ft_putchar_fd((num % 10 + '0'), 1);
}

int	ft_print_unsigned(unsigned int num)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_unsigned(num);
	return (ft_unsigned_len(num));
}
