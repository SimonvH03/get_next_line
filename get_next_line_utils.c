/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-hoo <svan-hoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:56:11 by svan-hoo          #+#    #+#             */
/*   Updated: 2023/11/08 20:18:44 by svan-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *src)
{
	size_t	i;

	i = 0;
	if (src)
		while (src[i])
			i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] || str[i] == (char)c)
		{
			if (str[i] == (char)c)
				return ((char *)(str + i));
			i++;
		}
	}
	return (NULL);
}

char	*ft_safe_err_exit(const char *pile, const char *ptr)
{
	if (pile)
		free((char *)pile);
	if (ptr && *ptr)
		return ((char *)ptr);
	return (NULL);
}

char	*ft_strjoin(const char *pile, const char *buff, int n)
{
	const size_t	p_len = ft_strlen(pile);
	char			*ptr;
	size_t			i;

	ptr = NULL;
	if ((p_len == 0 && n == 0) || n < 0)
		return (ft_safe_err_exit(pile, ptr));
	ptr = (char *)malloc((p_len + n + 1) * sizeof(char));
	if (ptr == NULL)
		return (ft_safe_err_exit(pile, ptr));
	i = 0;
	while (i < p_len)
	{
		ptr[i] = pile[i];
		i++;
	}
	i = 0;
	while (i < (size_t)n)
	{
		ptr[p_len + i] = buff[i];
		i++;
	}
	ptr[p_len + n] = '\0';
	return (ft_safe_err_exit(pile, ptr));
}
