/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-hoo <svan-hoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:11:18 by svan-hoo          #+#    #+#             */
/*   Updated: 2023/11/27 20:31:46 by svan-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free(void *p)
{
	free(p);
	p = NULL;
	return (p);
}

int	ft_strlen(const char *src)
{
	int	i;

	i = 0;
	if (src)
		while (src[i])
			i++;
	return (i);
}

int	ft_strchr(const char *str, char c)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] || str[i] == c)
		{
			if (str[i] == c)
				return (i + 1);
			i++;
		}
	}
	return (0);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*ptr;

	i = ft_strlen(src);
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr[i] = '\0';
	while (i--)
		ptr[i] = src[i];
	return (ptr);
}
