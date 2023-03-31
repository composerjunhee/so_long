/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:33:44 by junheeki          #+#    #+#             */
/*   Updated: 2022/11/10 15:14:14 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	const char	*p;

	p = str;
	while (*p != '\0')
		p++;
	while (*p != (char)ch && p != str)
		p--;
	if (*p != (char)ch)
		return (NULL);
	return ((char *)p);
}
