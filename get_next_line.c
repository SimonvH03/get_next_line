/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-hoo <svan-hoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:54:18 by svan-hoo          #+#    #+#             */
/*   Updated: 2023/11/03 22:39:45 by svan-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static char	*ft_read_fd(int fd, char *excess)
{
	ssize_t	bytes_read;
	char	*buffer;
	char	*str;

	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bytes_read = 1;
	if (excess)
		str = ft_strjoin_ptr(str, excess, 1);
	while (bytes_read > 0 && str == ft_strchr(str, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(str);
			return (NULL);
		}
		printf("%s", buffer);
		str = ft_strjoin_ptr(str, buffer, bytes_read);
	}
	free(buffer);
	return (str);
}

static char	*ft_splitread(char *str)
{
	char	*excess;
	char	*split;

	if (str == NULL)
		return (NULL);
	split = ft_strchr(str, '\n') + 1;
	excess = ft_strdup(split);
	*split++ = '\0';
	if (split != NULL)
		free(split);
	return (excess);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*excess;

	excess = ft_strdup("");
	str = ft_read_fd(fd, excess);
	excess = ft_splitread(str);
	return (str);
}

int	main(void)
{
	int			fd;
	int			line;
	char		*nextline;

	line = 0;
	fd = open("test.txt", O_RDONLY);
	while (line++ < 5)
	{
		nextline = get_next_line(fd);
		if (nextline == NULL)
		{
			printf("nextline == NULL: stop.");
			return (0);
		}
		printf("loop %i:	%s", (line - 1), nextline);
	}
	return (0);
}
