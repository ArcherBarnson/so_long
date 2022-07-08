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
	t_mlx_global	*so_long;

	so_long = malloc(sizeof(t_mlx_global));
	if (!so_long)
		return (NULL);
	so_long->map_split = malloc(sizeof(char *) * count_lines(av) + 1);
	if (!so_long->map_split)
		return (NULL);
	default_init_global(so_long);
	so_long->map_fd = open(av, O_RDONLY, 0644);
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
	t_mlx_global	*so_long;
	t_mlx_bonus		*bonus;

	if (ac != 2 || verify_extension(av[1]) == -1)
	{
		write(2, "Bad argument, a .ber file is needed\n", 36);
		return (-1);
	}
	so_long = init_struct(av[1]);
	bonus = ennemies_init(so_long);
	if (so_long == NULL || bonus == NULL)
	{
		clean_exit(so_long, bonus);
		exit(0);
		return (-1);
	}
	init_imgs(so_long);
	spawn_ennemies(so_long, bonus);
	draw_map(so_long, bonus);
	mlx_hook(so_long->window, 2, 1L << 0, get_action, so_long);
	mlx_loop(so_long->mlx);
	return (0);
}
