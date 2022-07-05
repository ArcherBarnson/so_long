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
	while (c != str[i])
		i++;
	return (i);
}

void	set_map_dimensions(t_mlx_global *so_long)
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

	y = 0;
	while (y < so_long->map_dimensions[0] / 50)
	{
		x = 0;
		while (x < so_long->map_dimensions[1] / 50)
		{
			if (so_long->map_split[y][x] == 'P')
			{
				so_long->player_pos[0] = y;
				so_long->player_pos[1] = x;
			}
			x++;
		}
		y++;
	}
	return ;
}

int	count_collectibles(t_mlx_global *so_long)
{
	int	i;
	int	j;
	int	col_count;

	i = 0;
	j = 0;
	col_count = 0;
	while (i < so_long->map_dimensions[0] / 50)
	{
		j = 0;
		while (j < so_long->map_dimensions[1] / 50)
		{
			if (so_long->map_split[i][j] == 'C')
				col_count++;
			j++;
		}
		i++;
	}
	return (col_count);
}

/*void	set_img(t_mlx_global *so_long, int texture)
{
	so_long->img.addr = mlx_get_data_addr(so_long->img.img, &so_long->img.bpp,
		&so_long->img.line_length, &so_long->img.endian);
	return ;
}*/
