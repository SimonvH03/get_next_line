/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-hoo <svan-hoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:11:18 by svan-hoo          #+#    #+#             */
/*   Updated: 2023/12/08 18:38:29 by svan-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free(char **p)
{
	free(*p);
	*p = NULL;
	return (NULL);
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
		while (str[i] || str[i] == c)
			if (str[i++] == c)
				return (i);
	return (0);
}

char	*ft_strdup_gnl(const char *str)
{
	int		i;
	char	*ptr;

	i = ft_strchr(str, '\n');
	if (i == 0)
		i = ft_strlen(str);
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr[i] = '\0';
	while (i--)
		ptr[i] = str[i];
	return (ptr);
}

void	ft_buffclear(char *buffer, size_t n)
{
	if (buffer)
		while (n--)
			buffer[n] = 0;
}
