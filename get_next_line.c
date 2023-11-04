/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon <simon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:54:18 by svan-hoo          #+#    #+#             */
/*   Updated: 2023/11/04 02:26:19 by simon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static char	*ft_read_fd(int fd, char *excess)
{
	ssize_t	bytes_read;
	char	*buffer;
	char	*found;

	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bytes_read = 1;
	if (excess)
		found = ft_strjoin_ptr(ft_strdup(""), excess, BUFFER_SIZE);
	while (bytes_read > 0 && found == ft_strchr(found, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(found);
			return (NULL);
		}
		found = ft_strjoin_ptr(found, buffer, bytes_read);
	}
	free(buffer);
	return (found);
}

char	*get_next_line(int fd)
{
	char		*found;
	static char	*excess;
	char		*nextline;

	found = ft_read_fd(fd, excess);
	excess = ft_strdup(ft_strchr(found, '\n') + 1);
	nextline = ft_splitdup(found, '\n');
	printf("excess: %s\n", excess);
	return (nextline);
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
		printf(">> nextline %i:	%s\n\n", (line - 1), nextline);
	}
	return (0);
}

excess not updated when file ends within bytes_read!!! change the strchr in read while loop condition