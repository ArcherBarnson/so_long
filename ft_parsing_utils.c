/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:34:22 by bgrulois          #+#    #+#             */
/*   Updated: 2022/06/27 12:10:46 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *filename)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	while (get_next_line(fd) != NULL)
		i++;
	close(fd);
	return (i);
}

int	is_char_in_str(char c, char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	verify_first_line(t_mlx_global *so_long)
{
	int	j;

	j = 0;
	while (so_long->map_split[0][j] != '\n')
		{
			if (so_long->map_split[0][j] != '1')
				return (-1);
			j++;
		}
	return (0);
}

int	verify_tiles_values(int	P, int	E, int	C)
{
	int	error;

	error = 0;
	if (P != 1)
	{
		write(2, "You need 1 player, no more, no less.\n", 37);
		error = -1;
	}
	if (E < 1)
	{
		write(2, "You need at least 1 exit.\n", 26);
		error = -1;
	}
	if (C < 1)
	{
		write(2, "You need at least 1 collectible.\n", 33);
		error = -1;
	}
	return (error);
}
