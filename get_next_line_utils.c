/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon <simon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:56:11 by svan-hoo          #+#    #+#             */
/*   Updated: 2023/11/07 05:34:37 by simon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *src)
{
	size_t	i;

	i = 0;
	while (src && src[i])
		i++;
	return (i);	
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
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*ptr;
	const size_t	s1len = ft_strlen(s1);
	const size_t	s2len = ft_strlen(s2);
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
	while (i < s2len)
	{
		ptr[s1len + i] = s2[i];
		i++;
	}
	ptr[s1len + s2len] = '\0';
	if (s1)
		free((char *)s1);
	return (ptr);
}

char	*ft_strdup(char *old, const char *src)
{
	int	i;
	char	*ptr;

	if (src == NULL)
		return (NULL);
	src++;
	ptr = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	if (old)
		free(old);
	return (ptr);
}
