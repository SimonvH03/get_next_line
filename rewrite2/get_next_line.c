/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-hoo <svan-hoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:11:14 by svan-hoo          #+#    #+#             */
/*   Updated: 2023/12/08 19:59:27 by svan-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_gnl(const char *buffer)
{
	int		i;
	char	*temp;

	i = ft_strchr(buffer, '\n');
	if (i == 0)
		i = ft_strlen(buffer);
	temp = (char *)malloc((i + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	temp[i] = '\0';
	while (i--)
		temp[i] = buffer[i];
	return (temp);
}

char	*ft_strjoin_gnl(char **newline, const char *buffer)
{
	char		*ptr;
	const int	n_len = ft_strlen(*newline);
	const int	b_len = ft_strlen(buffer);
	const int	b_nl = ft_strchr(buffer, '\n');
	int			i;

	if (b_nl == 0)
		i = n_len + b_len;
	else
		i = n_len + b_nl;
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (ptr == NULL)
		return (ft_free(newline));
	ptr[i] = '\0';
	while (i-- > n_len)
		ptr[i] = buffer[i - n_len];
	i++;
	while (i--)
		ptr[i] = (*newline)[i];
	ft_free (newline);
	return (ptr);
}

char	*ft_read_gnl(char **newline, char *buffer, int fd)
{
	int		bytes_read;

	bytes_read = BUFFER_SIZE;
	while (bytes_read == BUFFER_SIZE && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE * sizeof(char));
		if (bytes_read < 0)
		{
			ft_memclear(buffer, BUFFER_SIZE + 1);
			return (ft_free(newline));
		}
		buffer[bytes_read] = '\0';
		*newline = ft_strjoin_gnl(newline, buffer);
		if (*newline == NULL)
			return (NULL);
	}
	return (*newline);
}

void	ft_remainder_gnl(char *buffer)
{
	const char	*remainder = buffer + ft_strchr(buffer, '\n');
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
	buffer[i] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*newline;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	newline = ft_strdup_gnl(buffer);
	newline = ft_read_gnl(&newline, buffer, fd);
	ft_remainder_gnl(buffer);
	if (newline)
		if (newline[0] == 0)
			ft_free(&newline);
	return (newline);
}

int	main(void)
{
	int			fd;
	int			line;
	char		*nextline;

	line = 0;
	fd = open("giant_line.txt", O_RDONLY);
	while (line < 15)
	{
		nextline = get_next_line(fd);
		if (nextline == NULL)
		{
			printf("nextline == NULL: stop.\n");
			return (0);
		}
		printf(">> nextline %i:	%s\n", line, nextline);
		line++;
		free(nextline);
	}
	close(fd);
	return (0);
}
