/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-hoo <svan-hoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:56:11 by svan-hoo          #+#    #+#             */
/*   Updated: 2023/11/06 20:31:05 by svan-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen_safe(const char *s)
{
	size_t	size;

	if (s == NULL)
		return (0);
	size = 0;
	while (s[size])
		size++;
	return (size);
}

char	*ft_splitdup_keepdelim(const char *s, const char c)
{
	size_t	i;
	char	*ptr;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	i++;
	ptr = malloc((i + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr[i] = '\0';
	while (i--)
		ptr[i] = s[i];
	if (s)
		free((char *)s);
	return (ptr);
}

char	*ft_strjoin(const char *s1, const char *s2, size_t size)
{
	char			*ptr;
	const size_t	s1len = ft_strlen_safe(s1);
	const size_t	s2len = ft_strlen_safe(s2);
	size_t			i;

	ptr = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < s1len)
	{
		ptr[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2len && size--)
	{
		ptr[s1len + i] = s2[i];
		i++;
	}
	ptr[s1len + s2len] = '\0';
	free((char *)s1);
	return (ptr);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str && (str[i] || str[i] == (char)c))
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i++;
	}
	return ((char *)str);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*ptr;

	i = 0;
	while (s[i])
		i++;
	ptr = malloc((i + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
