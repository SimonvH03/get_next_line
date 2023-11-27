/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-hoo <svan-hoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:54:18 by svan-hoo          #+#    #+#             */
/*   Updated: 2023/11/24 18:10:09 by svan-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_nl(int fd, char *pile)
{
	char	*buffer;
	int		bytes_read;

	if (ft_strchr(pile, '\n'))
		return (pile);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bytes_read = BUFFER_SIZE;
	while (bytes_read == BUFFER_SIZE && !ft_strchr(pile, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		pile = ft_strjoin(pile, buffer, bytes_read);
	}
	free(buffer);
	return (pile);
}

char	*ft_splitdup_nl(const char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	ptr = malloc((i + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr[i] = '\0';
	while (i--)
		ptr[i] = str[i];
	return (ptr);
}

char	*ft_residu(const char *pile)
{
	char	*nl;
	char	*res;
	int		i;

	nl = ft_strchr(pile, '\n');
	if (nl != NULL)
		nl++;
	i = 0;
	if (nl)
		while (nl[i])
			i++;
	res = (char *)malloc((i + 1) * sizeof(char));
	if (res == NULL)
	{
		free((char *)pile);
		return (NULL);
	}
	res[i] = '\0';
	while (i--)
		res[i] = nl[i];
	free((char *)pile);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*pile = NULL;
	char		*nextline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	pile = ft_read_nl(fd, pile);
	if (pile == NULL)
		return (NULL);
	nextline = ft_splitdup_nl(pile);
	pile = ft_residu(pile);
	if (pile == NULL)
		free(nextline);
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
