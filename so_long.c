/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:35:48 by bgrulois          #+#    #+#             */
/*   Updated: 2022/06/29 17:19:29 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_imgs(t_mlx_global *so_long)
{
	int	a;
	int	b;

	so_long->wall = mlx_xpm_file_to_image(so_long->mlx, "../sl_assets/debug_wall_bis_lol.xpm",
			&a, &b);
	so_long->ground = mlx_xpm_file_to_image(so_long->mlx, "../sl_assets/debug_ground.xpm",
			&a, &b);
	so_long->player = mlx_xpm_file_to_image(so_long->mlx, "../sl_assets/debug_player.xpm",
			&a, &b);
	so_long->exit = mlx_xpm_file_to_image(so_long->mlx,
			"../sl_assets/debug_exit.xpm", &a, &b);
	so_long->collectible = mlx_xpm_file_to_image(so_long->mlx,
			"../sl_assets/debug_collectible.xpm", &a, &b);
	return ; 
}

void	draw_map(t_mlx_global *so_long)
{
	int	x;
	int	y;

	x = 0;
	y = 0;

	while (y < so_long->map_dimensions[0] / 50)
	{
		while (x < so_long->map_dimensions[1] / 50)
		{
			if (so_long->map_split[y][x] == '0')
				mlx_put_image_to_window(so_long->mlx, so_long->window,
					so_long->ground, x * 50, y * 50);
			if (so_long->map_split[y][x] == '1')
				mlx_put_image_to_window(so_long->mlx, so_long->window,
					so_long->wall, x * 50, y * 50);
			if (so_long->map_split[y][x] == 'P')
				mlx_put_image_to_window(so_long->mlx, so_long->window,
					so_long->player, x * 50, y * 50);
			if (so_long->map_split[y][x] == 'E')
				mlx_put_image_to_window(so_long->mlx, so_long->window,
					so_long->exit, x * 50, y * 50);
			if (so_long->map_split[y][x] == 'C')
				mlx_put_image_to_window(so_long->mlx, so_long->window,
					so_long->collectible, x * 50, y * 50);
			x++;
		}
		x = 0;
		y ++;
	}
	return ;
}

/*int	ft_so_long(t_mlx_global *so_long)
{
	init_imgs(so_long);
	draw_map(so_long);
	printf("solong 1x = %i 0y = %i\n\n", so_long->player_pos[1], so_long->player_pos[0]);
	return (0);
}*/
