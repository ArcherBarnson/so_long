/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:15:21 by bgrulois          #+#    #+#             */
/*   Updated: 2022/06/30 15:11:05 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_action(int keycode, t_mlx_global *so_long)
{
	printf("\ncolls==%i\n", so_long->collectibles_left);
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

int	close_window(t_mlx_global *so_long)
{
	write(1, "window_closed\n", 14);
	mlx_destroy_display(so_long->window);
	mlx_destroy_window(so_long->mlx, so_long->window);
	exit(0);
}

/*void	refresh(t_mlx_base *base, t_mlx_imgs *imgs, t_map_info *map,
		int offset[2])
{
	set_img(base, imgs, where_is_that_char(
			map->map_split[map->player_pos[0]][map->player_pos[1]], TILES));
	mlx_put_image_to_window(base->mlx, base->window,
			imgs->img.img,
			map->player_pos[0], map->player_pos[1]);
	set_img(base, imgs, where_is_that_char(
			map->map_split[map->player_pos[0] + offset[0]]
			[map->player_pos[1] + offset[1]], TILES));
	mlx_put_image_to_window(base->mlx, base->window,
			imgs->img.img,
			map->player_pos[0] + offset[0],
			map->player_pos[1] + offset[1]);
	return ;
}*/



int	move_down(t_mlx_global *so_long)
{
	if (can_u_move(so_long, 1, 0) == 0)
	{
		if (can_u_exit(so_long, 1, 0) == 1)
			exit(0);
		else
			return (0);
	}
	mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->ground,
			so_long->player_pos[1] * 50, so_long->player_pos[0] * 50);
	so_long->player_pos[0]++;
	mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->player,
			so_long->player_pos[1] * 50, so_long->player_pos[0] * 50);
	return (0);
}

int	move_up(t_mlx_global *so_long)
{
	if (can_u_move(so_long, -1, 0) == 0)
	{
		if (can_u_exit(so_long, -1, 0) == 1)
			exit(0);
		else
			return (0);
	}
	mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->ground,
			so_long->player_pos[1] * 50, so_long->player_pos[0] * 50);
	so_long->player_pos[0]--;
	mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->player,
			so_long->player_pos[1] * 50, so_long->player_pos[0] * 50);
	return (0);
}

int	move_left(t_mlx_global *so_long)
{
	if (can_u_move(so_long, 0, -1) == 0)
	{
		if (can_u_exit(so_long, 0, -1) == 1)
			exit(0);
		else
			return (0);
	}
	mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->ground,
			so_long->player_pos[1] * 50, so_long->player_pos[0] * 50);
	so_long->player_pos[1]--;
	mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->player,
			so_long->player_pos[1] * 50, so_long->player_pos[0] * 50);
	return (0);
}

int	move_right(t_mlx_global *so_long)
{
	if (can_u_move(so_long, 0, 1) == 0)
	{
		if (can_u_exit(so_long, 0, 1) == 1)
			exit(0);
		else
			return (0);
	}
	mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->ground,
			so_long->player_pos[1] * 50, so_long->player_pos[0] * 50);
	so_long->player_pos[1]++;
	mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->player,
			so_long->player_pos[1] * 50, so_long->player_pos[0] * 50);
	return (0);
}
