/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:51:26 by bgrulois          #+#    #+#             */
/*   Updated: 2022/06/29 17:03:00 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verify_extension(char *arg)
{
	int	i;
	int	test_fd;

	i = 0;
	if (!arg)
		return (-1);
	test_fd = open(arg, O_DIRECTORY);
	if (test_fd != -1)
		return (-1);
	while (arg[i])
		i++;
	if (arg && arg[i - 1] == 'r' && arg[i - 2] == 'e' && arg[i - 3] == 'b'
			&& arg[i - 4] == '.')
		return (0);
	else
		return (-1);
}

t_mlx_global	*init_struct(char *av)
{
	t_mlx_global *so_long;

	so_long = malloc(sizeof(t_mlx_global));
	if (!so_long)
		return (NULL);
	if (ft_parsing(av, so_long) == NULL)
		return (NULL);
    	set_map_dimensions(so_long);
	get_player_pos(so_long);
	so_long->collectibles_left = count_collectibles(so_long);
	so_long->step_count = 0;
	//printf("1x = %i\n0y = %i\n", so_long->map_dimensions[1], so_long->map_dimensions[0]);
    	so_long->mlx = mlx_init();
    	so_long->window = mlx_new_window(so_long->mlx, so_long->map_dimensions[1],
                        so_long->map_dimensions[0], "So Long");
	return (so_long);
}

int	main(int ac, char **av)
{
	t_mlx_global *so_long;

	if (ac != 2 || verify_extension(av[1]) == -1)
	{
		write(2, "Bad argument, a .ber file is needed\n", 36);
		return(-1);
	}
	so_long = init_struct(av[1]);
	if (so_long == NULL)
		return (-1);
	init_imgs(so_long);
	draw_map(so_long);
	mlx_hook(so_long->window, 2, 1L<<0, get_action, so_long);
	mlx_loop(so_long->mlx);
	return (0);
}
