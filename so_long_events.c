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

int	close_window(t_mlx_global *so_long)
{
//	write(1, "window_closed\n", 14);
	mlx_destroy_display(so_long->window);
	mlx_destroy_window(so_long->mlx, so_long->window);
	exit(0);
}

int	move_down(t_mlx_global *so_long)
{
	if (can_u_move(so_long, 1, 0) == 0)
	{
		if (can_u_exit(so_long, 1, 0) == 1)
			exit(0);
		else
			return (0);
	}
	//ft_damage(so_long, 1, 0);
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
	//ft_damage(so_long, -1, 0);
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
	//ft_damage(so_long, 0, -1); //echec et mat mdr
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
	//ft_damage(so_long, 0, 1);
	mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->ground,
		so_long->player_pos[1] * 50, so_long->player_pos[0] * 50);
	so_long->player_pos[1]++;
	mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->player,
		so_long->player_pos[1] * 50, so_long->player_pos[0] * 50);
	return (0);
}
