/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-hoo <svan-hoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:11:14 by svan-hoo          #+#    #+#             */
/*   Updated: 2023/11/29 15:22:12 by svan-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(const char *newline, const char *buffer)
{
	char		*ptr;
	const int	n_len = ft_strlen(newline);
	const int	b_len = ft_strlen(buffer);
	const int	b_nl = ft_strchr(buffer, '\n');
	int			i;

	if (b_nl == 0)
		i = n_len + b_len;
	else
		i = n_len + b_nl;
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr[i] = '\0';
	while (i-- > n_len)
		ptr[i] = buffer[i - n_len];
	i++;
	while (i--)
		ptr[i] = newline[i];
	ft_free ((char *)newline);
	return (ptr);
}

void	ft_residu(char *buffer)
{
	const char	*residu = buffer + ft_strchr(buffer, '\n');

	if (residu > buffer)
		while (*residu)
			*buffer++ = *residu++;
	*buffer = '\0';
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*newline;
	int			bytes_read;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, buffer, 0) < 0)
		return (NULL);
	newline = ft_strdup_gnl(buffer);
	bytes_read = BUFFER_SIZE;
	while (bytes_read == BUFFER_SIZE && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE * sizeof(char));
		if (bytes_read < 0)
		{
			ft_buffclear(buffer, BUFFER_SIZE);
			return (ft_free(newline));
		}
		buffer[bytes_read] = '\0';
		newline = ft_strjoin_gnl(newline, buffer);
	}
	if (newline[0] == 0)
		return (ft_free(newline));
	ft_residu(buffer);
	return (newline);
}

// int	main(void)
// {
// 	int			fd;
// 	int			line;
// 	char		*nextline;

// 	line = 0;
// 	fd = open("test5.txt", O_RDONLY);
// 	while (line < 100)
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
