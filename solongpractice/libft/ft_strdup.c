/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:54:04 by junheeki          #+#    #+#             */
/*   Updated: 2022/11/10 15:06:28 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	str_len;
	char	*result;

	str_len = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!result)
		return (0);
	while (*s != '\0')
		*result++ = *s++;
	*result = '\0';
	return (result - str_len);
}
