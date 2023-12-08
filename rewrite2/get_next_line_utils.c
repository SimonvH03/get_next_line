/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-hoo <svan-hoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:11:18 by svan-hoo          #+#    #+#             */
/*   Updated: 2023/12/08 18:53:52 by svan-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free(char **pp)
{
	free(*pp);
	*pp = NULL;
	return (NULL);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}

int	ft_strchr(const char *str, char c)
{
	int	i;

	i = 0;
	if (str)
		while (str[i] || str[i] == c)
			if (str[i++] == c)
				return (i);
	return (0);
}

void	ft_memclear(char *src, size_t n)
{
	if (src)
		while (n--)
			src[n] = 0;
}
