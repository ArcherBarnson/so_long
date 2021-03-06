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
	clean_exit(so_long, NULL);
	return (0);
}

int	move_down(t_mlx_global *so_long, t_mlx_bonus *bonus)
{
	if (can_u_move(so_long, 1, 0, bonus) == 0)
	{
		if (can_u_exit(so_long, 1, 0) == 1)
			clean_exit(so_long, NULL);
		else
			return (0);
	}
	int     i = -1;
        while (so_long->map_split[i++] != NULL)
		printf("MAP ==> %s", so_long->map_split[i]);
	ft_damage(so_long, 1, 0);
	mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->ground,
		so_long->player_pos[1] * 50, so_long->player_pos[0] * 50);
	so_long->map_split[so_long->player_pos[0]][so_long->player_pos[1]] = '0';
	so_long->player_pos[0]++;
	mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->player,
		so_long->player_pos[1] * 50, so_long->player_pos[0] * 50);
	so_long->map_split[so_long->player_pos[0]][so_long->player_pos[1]] = 'P';
	return (0);
}

int	move_up(t_mlx_global *so_long, t_mlx_bonus *bonus)
{
	if (can_u_move(so_long, -1, 0, bonus) == 0)
	{
		if (can_u_exit(so_long, -1, 0) == 1)
			clean_exit(so_long, NULL);
		else
			return (0);
	}
	int     i = -1;
        while (so_long->map_split[i++] != NULL)
		printf("MAP ==> %s", so_long->map_split[i]);
	ft_damage(so_long, -1, 0);
	mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->ground,
		so_long->player_pos[1] * 50, so_long->player_pos[0] * 50);
	so_long->map_split[so_long->player_pos[0]][so_long->player_pos[1]] = '0';
	so_long->player_pos[0]--;
	mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->player,
		so_long->player_pos[1] * 50, so_long->player_pos[0] * 50);
	so_long->map_split[so_long->player_pos[0]][so_long->player_pos[1]] = 'P';
	return (0);
}

int	move_left(t_mlx_global *so_long, t_mlx_bonus *bonus)
{
	if (can_u_move(so_long, 0, -1, bonus) == 0)
	{
		if (can_u_exit(so_long, 0, -1) == 1)
			clean_exit(so_long, NULL);
		else
			return (0);
	}
	int     i = -1;
        while (so_long->map_split[i++] != NULL)
		printf("MAP ==> %s", so_long->map_split[i]);
	ft_damage(so_long, 0, -1);
	mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->ground,
		so_long->player_pos[1] * 50, so_long->player_pos[0] * 50);
	so_long->map_split[so_long->player_pos[0]][so_long->player_pos[1]] = '0';
	so_long->player_pos[1]--;
	mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->player,
		so_long->player_pos[1] * 50, so_long->player_pos[0] * 50);
	so_long->map_split[so_long->player_pos[0]][so_long->player_pos[1]] = 'P';
	return (0);
}

int	move_right(t_mlx_global *so_long, t_mlx_bonus *bonus)
{
	if (can_u_move(so_long, 0, 1, bonus) == 0)
	{
		if (can_u_exit(so_long, 0, 1) == 1)
			clean_exit(so_long, NULL);
		else
			return (0);
	}
	int     i = -1;
        while (so_long->map_split[i++] != NULL)
		printf("MAP ==> %s", so_long->map_split[i]);
	ft_damage(so_long, 0, 1);
	mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->ground,
		so_long->player_pos[1] * 50, so_long->player_pos[0] * 50);
	so_long->map_split[so_long->player_pos[0]][so_long->player_pos[1]] = '0';
	so_long->player_pos[1]++;
	mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->player,
		so_long->player_pos[1] * 50, so_long->player_pos[0] * 50);
	so_long->map_split[so_long->player_pos[0]][so_long->player_pos[1]] = 'P';
	return (0);
}
