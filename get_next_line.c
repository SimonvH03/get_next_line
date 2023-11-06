/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-hoo <svan-hoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:54:18 by svan-hoo          #+#    #+#             */
/*   Updated: 2023/11/06 19:12:47 by svan-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static char	*ft_read_delim(int fd, const char delim, char *excess)
{
	char	*buffer;
	int		bytes_read;
	char	*found;

	found = NULL;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	bytes_read = 1;
	if (excess)
		found = ft_strjoin(found, excess);
	while (bytes_read && ft_strchr(buffer, delim) == buffer
		&& ft_strchr(found, delim) == found)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		found = ft_strjoin(found, buffer);
	}
	return (found);
}

char	*get_next_line(int fd)
{
	static char	*excess;
	char		*found;
	const char	delim = '\n';

	found = ft_read_delim(fd, delim, excess);
	excess = ft_strdup(ft_strchr(found, delim) + 1);
	found = ft_splitdup_keepdelim(found, delim);
	return (found);
}

// int	main(void)
// {
// 	int			fd;
// 	int			line;
// 	char		*nextline;

// 	line = 0;
// 	fd = open("test5.txt", O_RDONLY);
// 	while (line < 15)
// 	{
// 		nextline = get_next_line(fd);
// 		if (nextline == NULL)
// 		{
// 			printf("nextline == NULL: stop.");
// 			return (0);
// 		}
// 		printf(">> nextline %i:	%s\n", line, nextline);
// 		line++;
// 	}
// 	return (0);
// }
