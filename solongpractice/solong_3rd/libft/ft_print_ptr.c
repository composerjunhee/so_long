/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:29:01 by junheeki          #+#    #+#             */
/*   Updated: 2023/02/27 14:54:46 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putptr(unsigned long long ptr, size_t *len)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16, len);
		ft_putptr(ptr % 16, len);
	}
	else
	{
		if (ptr < 10)
			*len += ft_putchar('0' + ptr);
		else
			*len += ft_putchar(ptr - 10 + 'a');
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	size_t	len;

	len = 0;
	len += ft_putstr("0x");
	ft_putptr(ptr, &len);
	return (len);
}
