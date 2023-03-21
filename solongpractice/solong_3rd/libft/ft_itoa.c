/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:37:11 by junheeki          #+#    #+#             */
/*   Updated: 2022/11/18 10:53:56 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_sub(char *str, int len, int n)
{
	int	index;

	index = 0;
	if (n == 0)
	{
		str[index] = '0';
	}
	while (n != 0)
	{
		str[len - index - 1] = n % 10 + '0';
		n /= 10;
		index++;
	}
}

static int	ft_len(int n, int *minus)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			*minus = 1;
			return (10);
		}
		else
		{
			*minus = 1;
			n = -n;
		}
	}
	else if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		minus;
	int		len;

	minus = 0;
	len = ft_len(n, &minus);
	str = (char *)malloc(sizeof(char) * (len + minus + 1));
	if (!str)
		return (NULL);
	str[len + minus] = '\0';
	if (n == -2147483648)
	{
		str[10] = '8';
		n = 214748364;
		str[0] = '-';
		len--;
	}
	else if (minus == 1)
	{
		str[0] = '-';
		n = -n;
	}
	ft_sub(&str[minus], len, n);
	return (&str[0]);
}
