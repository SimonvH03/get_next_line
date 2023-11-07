/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon <simon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:54:18 by svan-hoo          #+#    #+#             */
/*   Updated: 2023/11/07 20:46:30 by simon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_nl(int fd, char *pile)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bytes_read = 42;
	while (bytes_read > 0 && !ft_strchr(pile, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			if (pile)
				free(pile);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		pile = ft_strjoin(pile, buffer);
	}
	free(buffer);
	if (*pile == '\0' && bytes_read == 0)
	{
		free(pile);
		return (NULL);
	}
	return (pile);
}

char	*get_next_line(int fd)
{
	static char	*pile;
	char		*nextline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	pile = ft_read_nl(fd, pile);
	if (pile == NULL)
		return (NULL);
	nextline = ft_splitdup_nl(pile);
	pile = ft_residu(pile);
	return (nextline);
}

// int	main(void)
// {
// 	int			fd;
// 	int			line;
// 	char		*nextline;

// 	line = 0;
// 	fd = open("test5.txt", O_RDONLY);
// 	while (line < 20)
// 	{
// 		nextline = get_next_line(fd);
// 		if (nextline == NULL)
// 		{
// 			printf("nextline == NULL: stop.");
// 			return (0);
// 		}
// 		printf(">> nextline %i:	%s\n", line, nextline);
// 		line++;
// 		free(nextline);
// 	}
// 	close(fd);
// 	return (0);
// }
