/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_rules.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:10:59 by bgrulois          #+#    #+#             */
/*   Updated: 2022/06/30 15:13:32 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_u_move(t_mlx_global *so_long, int x, int y)
{
	char	*step_display;

	if (so_long->map_split[so_long->player_pos[0] + x]
			[so_long->player_pos[1] + y] == '1'
			|| so_long->map_split[so_long->player_pos[0] + x]
                        [so_long->player_pos[1] + y] == 'E')
		return (0);
	if (is_collectible(so_long, x, y) == 1)
		so_long->collectibles_left--;
	so_long->step_count++;
	step_display = ft_strjoin("step count > ", ft_itoa(so_long->step_count));//pourri
        mlx_string_put(so_long->mlx, so_long->window, 100, 100, 123, step_display);
	return (1);
}

int	can_u_exit(t_mlx_global *so_long, int x, int y)
{
	if (so_long->map_split[so_long->player_pos[0] + x]
			[so_long->player_pos[1] + y] == 'E'
		&& so_long->collectibles_left == 0)
		return (1);
	return (0);
}

int	is_collectible(t_mlx_global *so_long, int x, int y)
{
	if (so_long->map_split[so_long->player_pos[0] + x]
			[so_long->player_pos[1] + y] == 'C')
	{
		so_long->map_split[so_long->player_pos[0] + x]
			[so_long->player_pos[1] + y] = '0';
		return (1);
	}
	return (0);
}
