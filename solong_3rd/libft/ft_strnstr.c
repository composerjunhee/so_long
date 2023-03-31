/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:37:34 by junheeki          #+#    #+#             */
/*   Updated: 2022/11/10 15:17:30 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	finder(const char *str, const char *letter, int n)
{
	str += n;
	while (*letter)
	{
		if (*str != *letter)
			return (0);
		str++;
		letter++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	if (!n)
		return (0);
	if (!*haystack)
		return (0);
	while ((haystack[i] != 0) && (i <= (n - ft_strlen(needle))))
	{
		if (finder(haystack, needle, i) == 1)
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
