/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:43:33 by bgrulois          #+#    #+#             */
/*   Updated: 2022/06/29 16:36:30 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	where_is_that_char(char c, char	*str)
{
	int	i;

	i = 0;
	while (str[i] && c != str[i])
		i++;
	if (str[i] == '\0')
		return (-1);
	return (i);
}

void	get_map_dimensions(t_mlx_global *so_long)
{
	int	x;
	int	y;

	x = get_line_size(so_long->map_split[0]);
	y = 0;
	while (so_long->map_split[y] != NULL)
		y++;
	so_long->map_dimensions[1] = x * 50;
	so_long->map_dimensions[0] = y * 50;
	//printf("x = %i\ny = %i\n", base->map_dimensions[1], base->map_dimensions[0]);
	return ;
}

void	get_player_pos(t_mlx_global *so_long)
{
	int	y;
	int	x;

	x = 0;
	while (so_long->map_split[x] != NULL)
	{
		y = 0;
		while (so_long->map_split[x][y] != '\n'
		&& so_long->map_split[x][y] != '\0')
		{
			if (so_long->map_split[x][y] == 'P')
			{
				so_long->player_pos[0] = x;
				so_long->player_pos[1] = y;
			}
			y++;
		}
		x++;
	}
	return ;
}

/*int	count_collectibles(t_mlx_global *so_long)
{
	int	i;
	int	j;
	int	col_count;

	i = 0;
	j = 0;
	col_count = 0;
	while (so_long->map_split[i] != NULL)
	{
		j = 0;
		while (so_long->map_split[i][j] != '\n'
		&& so_long->map_split[i][j] != '\0')
		{
			if (so_long->map_split[i][j] == 'C')
				col_count++;
			j++;
		}
		i++;
	}
	return (col_count);
}*/

/*void	set_img(t_mlx_global *so_long, int texture)
{
	so_long->img.addr = mlx_get_data_addr(so_long->img.img, &so_long->img.bpp,
		&so_long->img.line_length, &so_long->img.endian);
	return ;
}*/
