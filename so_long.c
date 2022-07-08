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

int	get_action(int keycode, t_mlx_global *so_long)
{
	//printf("\ncolls==%i\n", so_long->collectibles_left);
	if (keycode == ESC)
		close_window(so_long);
	else if (keycode == UP || keycode == W)
		move_up(so_long);
	else if (keycode == DOWN || keycode == S)
		move_down(so_long);
	else if (keycode == RIGHT || keycode == D)
		move_right(so_long);
	else if (keycode == LEFT || keycode == A)
		move_left(so_long);
	return (0);
}

void	init_imgs(t_mlx_global *so_long)
{
	int	a;
	int	b;

	so_long->wall = mlx_xpm_file_to_image(so_long->mlx,
			"../sl_assets/debug_wall_bis_lol.xpm", &a, &b);
	so_long->ground = mlx_xpm_file_to_image(so_long->mlx,
			"../sl_assets/test_ground.xpm", &a, &b);
	so_long->player = mlx_xpm_file_to_image(so_long->mlx,
			"../sl_assets/test_player.xpm", &a, &b);
	so_long->exit = mlx_xpm_file_to_image(so_long->mlx,
			"../sl_assets/test_exit_locked.xpm", &a, &b);
	so_long->exit_open = mlx_xpm_file_to_image(so_long->mlx,
			"../sl_assets/test_exit_open.xpm", &a, &b);
	so_long->collectible = mlx_xpm_file_to_image(so_long->mlx,
			"../sl_assets/test_collectible.xpm", &a, &b);
	return ;
}

void	my_mlx_place_tile(t_mlx_global *so_long, int x, int y)
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
	/*if (so_long->map_split[y][x] == 'X')
		mlx_put_image_to_window(so_long->mlx, so_long->window,
			bonus->ennemy, x * 50, y * 50);*/
	return ;
}

void	draw_map(t_mlx_global *so_long)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (so_long->map_split[y] != NULL)
	{
		while (so_long->map_split[y][x] != '\n'
			&& so_long->map_split[y][x] != '\0')
		{
			my_mlx_place_tile(so_long, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return ;
}

/*void	get_map_dimensions(t_mlx_global *so_long)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (so_long->map_split[x] != NULL)
		x++;
	while (so_long->map_split[0][y] != '\n' &&
		so_long->map_split[0][y] != '\0')
		y++;
	so_long->map_dimensions[0] = x;
	so_long->map_dimensions[1] = y;
	return ;
}*/
