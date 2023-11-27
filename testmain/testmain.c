/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-hoo <svan-hoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:46:08 by svan-hoo          #+#    #+#             */
/*   Updated: 2023/11/27 18:33:28 by svan-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

void	ft_writing(const char *str, int n)
{
	char	esc[7];

	esc[0] = '\\';
	esc[4] = '\\';
	while (*str || n > 0)
	{
		if (!ft_isprint(*str))
		{
			esc[1] = ((*str >> 6) & 7) + '0';
			esc[2] = ((*str >> 3) & 7) + '0';
			esc[3] = ((*str >> 0) & 7) + '0';
			write(1, esc, 5);
		}
		else
			write(1, str, 1);
		str++;
		if (n > 0)
			n--;
	}
	if (n < 0)
		write(1, "\\0", 2);
}

int	main(void)
{
	const char	*str = "line00\012line01";
	static char	buffer[10];

	ft_writing(str, 25);
	write(1, "\n", 1);
	return (0);
}
