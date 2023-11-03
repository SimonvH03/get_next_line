/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-hoo <svan-hoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:56:11 by svan-hoo          #+#    #+#             */
/*   Updated: 2023/11/03 22:33:24 by svan-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

char	*ft_strjoin_ptr(const char *pre, const char *suf, int size)
{
	char			*ptr;
	const size_t	prelen = ft_strlen(pre);
	const size_t	suflen = ft_strlen(suf);
	size_t			i;

	ptr = (char *)malloc((prelen + suflen + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (*pre)
		*ptr++ = *pre++;
	while (*suf && size--)
		*ptr++ = *suf++;
	*ptr = '\0';
	ptr -= (prelen + suflen);
	return (ptr);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] || str[i] == (char)c)
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
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
