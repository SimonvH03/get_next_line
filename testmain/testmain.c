/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svan-hoo <svan-hoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:46:08 by svan-hoo          #+#    #+#             */
/*   Updated: 2023/11/24 22:10:40 by svan-hoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_writing(char *str, int n)
{
	if (n <= 0)
	{
		while (*str)
		{
			write(1, str++, 1);
		}
	}
	else
	{
		while (n--)
		{
			if (*str == '\0')
				write(1, "\\0", 2);
			else if (*str == '\n')
				write(1, "\\n", 2);
			else
				write(1, str++, 1);
		}
	}

}

int	main(void)
{
	char *str = "randoms\nhit";
	static char	buffer[10];
	ft_writing(str, 15);
	return (0);
}
