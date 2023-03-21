/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:37:00 by junheeki          #+#    #+#             */
/*   Updated: 2023/02/20 20:49:29 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_malloc(char **ret)
{
	size_t	i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		i++;
	}
	free(ret);
	return (NULL);
}

static size_t	get_row(char const *s, char c)
{
	size_t	ret;
	size_t	i;

	ret = 0;
	i = 0;
	if (!*s)
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			ret++;
			while (s[i] && s[i] == c)
				i++;
		}
		else
			i++;
	}
	if (s[i - 1] != c)
		ret++;
	return (ret);
}

static size_t	get_strlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			break ;
		i++;
	}
	return (i);
}

void	saverr(char const *s, char c, char **ret, size_t row)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (i < row)
	{
		while (*s && *s == c)
			s++;
		len = get_strlen(s, c);
		ret[i] = (char *)malloc(sizeof(char) * len + 1);
		if (!ret[i])
		{
			free_malloc(ret);
			return ;
		}
		ft_strlcpy(ret[i], s, len + 1);
		i++;
		if (i < row)
			s += len;
	}
	ret[i] = (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	row;

	if (!s)
		return (NULL);
	row = get_row(s, c);
	ret = (char **)malloc(sizeof(char *) * (row + 1));
	if (!ret)
		return (NULL);
	saverr(s, c, ret, row);
	return (ret);
}
