/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-hoo <svan-hoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:11:14 by svan-hoo          #+#    #+#             */
/*   Updated: 2024/01/23 20:00:20 by svan-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup_gnl(const char *buffer)
{
	int		i;
	char	*temptr;

	i = ft_strchr_gnl(buffer, '\n');
	if (i == 0)
		i = ft_strlen_gnl(buffer);
	temptr = (char *)malloc((i + 1) * sizeof(char));
	if (temptr == NULL)
		return (NULL);
	temptr[i] = '\0';
	while (i--)
		temptr[i] = buffer[i];
	return (temptr);
}

char	*ft_strjoin_gnl(char **newline, const char *buffer)
{
	char		*temptr;
	const int	n_len = ft_strlen_gnl(*newline);
	const int	b_len = ft_strlen_gnl(buffer);
	const int	b_nl = ft_strchr_gnl(buffer, '\n');
	int			i;

	if (b_nl == 0)
		i = n_len + b_len;
	else
		i = n_len + b_nl;
	temptr = (char *)malloc((i + 1) * sizeof(char));
	if (temptr == NULL)
		return (ft_free_gnl(newline));
	temptr[i] = '\0';
	while (i-- > n_len)
		temptr[i] = buffer[i - n_len];
	i += 1;
	while (i--)
		temptr[i] = (*newline)[i];
	ft_free_gnl(newline);
	return (temptr);
}

char	*ft_read_gnl(char **newline, char *buffer, int fd)
{
	int		bytes_read;

	bytes_read = BUFFER_SIZE;
	while (bytes_read == BUFFER_SIZE && !ft_strchr_gnl(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (ft_free_gnl(newline));
		buffer[bytes_read] = '\0';
		*newline = ft_strjoin_gnl(newline, buffer);
		if (*newline == NULL)
			return (NULL);
	}
	return (*newline);
}

void	ft_remainder_gnl(char *buffer)
{
	const char	*remainder = buffer + ft_strchr_gnl(buffer, '\n');
	int			i;

	i = 0;
	if (remainder > buffer)
	{
		while (remainder[i])
		{
			buffer[i] = remainder[i];
			i++;
		}
	}
	ft_memclear_gnl(buffer + i, BUFFER_SIZE - i);
}

char	*get_next_line(int fd)
{
	static char	buffer[MAX_FDS][BUFFER_SIZE + 1];
	char		*newline;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > MAX_FDS)
		return (NULL);
	newline = ft_strdup_gnl(buffer[fd]);
	if (newline == NULL)
	{
		ft_memclear_gnl(buffer[fd], BUFFER_SIZE + 1);
		return (NULL);
	}
	newline = ft_read_gnl(&newline, buffer[fd], fd);
	if (newline == NULL)
	{
		ft_memclear_gnl(buffer[fd], BUFFER_SIZE + 1);
		return (NULL);
	}
	ft_remainder_gnl(buffer[fd]);
	if (newline[0] == 0)
		return (ft_free_gnl(&newline));
	return (newline);
}

// int	main(void)
// {
// 	int			fd;
// 	int			line;
// 	char		*nextline;

// 	line = 0;
// 	fd = open("text.txt", O_RDONLY);
// 	while (line < 15)
// 	{
// 		nextline = get_next_line(fd);
// 		printf("\nline %d:\t%s", line, nextline);
// 		line++;
//		if (nextline == NULL)
//			break ;
// 		free(nextline);
// 	}
// 	close(fd);
// 	return (0);
// }