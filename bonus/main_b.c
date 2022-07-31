#include "../so_long.h"

int	err_msg(int err_code)
{
	if (err_code == 0)
		write(2, "Error\nUsage : ./so_long <map.ber>\n", 34);
	if (err_code == -2)
		write(2, "Error\nBad extension\n", 20);
	if (err_code == -3)
	{
		write(2, "Error\n", 6);
		write(2, "Bad map (not closed or wrong dimensions)", 40);
	}
	if (err_code == -4)
		write(2, "Error\nYour map contains an invalid tile\n", 40);
	if (err_code == -5)
		write(2, "Error\nInvalid number of players\n", 32);
	if (err_code == -6)
		write(2, "Error\nNo exit or collectible present\n", 37);
	//clean_exit(so_long, NULL);
	return (-1);
}

int	main(int ac, char **av)
{
	t_mlx_global	*so_long;
	t_mlx_bonus		*bonus;

	if (ac != 2)
		return(err_msg(0));
	so_long = global_init();
	if (so_long == NULL)
		return (-1);
	if (ft_parsing(av[1], so_long) != 0)
		return (err_msg(ft_parsing(av[1], so_long)));
	so_long->mlx = mlx_init();
	init_imgs(so_long);
	get_player_pos(so_long);
	get_map_dimensions(so_long);
	so_long->window = mlx_new_window(so_long->mlx,
		so_long->map_dimensions[1], so_long->map_dimensions[0],
		"So_long");
	draw_map(so_long);
	bonus = ennemies_init(so_long);
	if (bonus == NULL)
		clean_exit(so_long, bonus);
	mlx_hook(so_long->window, 2, 1L << 0, get_action, so_long);
	mlx_loop(so_long->mlx);
	return (0);
}
