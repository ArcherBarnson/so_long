#include "so_long.h"

int	*generate_random_coordinates(int x, int y)
{
	int		*rcords;
	char	urand[2];
	int		urand_fd;
	int		i;

	rcords = malloc(sizeof(int) * 2);
	if (!rcords)
		return (NULL);
	i = 0;
	urand_fd = open("/dev/urandom", O_RDONLY, 0644);
	read(urand_fd, urand, 2);
	close(urand_fd);
	while (i < 2)
	{
		rcords[i] = (int)urand[i];
		if (rcords[i] < 0)
			rcords[i] = -rcords[i];
		if (i == 0)
			rcords[i] = (rcords[i] + 1) % x;
		if (i == 1)
			rcords[i] = (rcords[i] + 1) % y;
		i++;
	}
	//printf("\ncols = %i\nrows = %i\n", rcords[0], rcords[1]);
	return (rcords);
}

void	place_ennemies(t_mlx_global *so_long, t_mlx_bonus *bonus)
{
	int	cols;
	int	rows;
	int	rec;
	int	*rcords;

	cols = so_long->map_dimensions[0] / 50;
	rows = so_long->map_dimensions[1] / 50;
	rec = bonus->ennemy_count;
	//printf("\nrec=%i\nx=%i\ny=%i\n", rec, x, y);
	rcords = generate_random_coordinates(cols, rows);
	while (rcords[0] < cols && rcords[1] < rows && rec > 0)
	{
		//printf("\nrec=%i\n", rec);
		rcords = generate_random_coordinates(cols, rows);
		if (so_long->map_split[rcords[0]][rcords[1]] == '0'
			|| so_long->map_split[rcords[0]][rcords[1]] == 'X')
		{
			so_long->map_split[rcords[0]][rcords[1]] = 'X';
			rec--;
		}
	}
	//free(rcords);
	return ;
}

void	spawn_ennemies(t_mlx_global *so_long, t_mlx_bonus *bonus)
{
	int	a;
	int	b;

	bonus->ennemy = mlx_xpm_file_to_image(so_long->mlx,
			"../sl_assets/test_ennemy.xpm", &a, &b);
	place_ennemies(so_long, bonus);
	//printf("\nec=%i\n", bonus->ennemy_count);
	return ;
}

t_mlx_bonus	*ennemies_init(t_mlx_global *so_long)
{
	t_mlx_bonus	*bonus;
	int		i;

	i = 0;
	bonus = malloc(sizeof(t_mlx_bonus));
	if (!bonus)
		return (NULL);
	default_init_bonus(bonus);
	bonus->ennemy_count = 10;
	bonus->player_health = 1;
	bonus->ennemypos = malloc(sizeof(int *) * bonus->ennemy_count);
	if (!bonus->ennemypos)
		return (NULL);
	while (i < bonus->ennemy_count)
	{
		bonus->ennemypos[i] = malloc(sizeof(int) * 2);
		if (!bonus->ennemypos[i])
			return (NULL);
		i++;
	}
	spawn_ennemies(so_long, bonus);
	return (bonus);
}

void	ft_damage(t_mlx_global *so_long, int x, int y)
{
	if (so_long->map_split[so_long->player_pos[0] + x]
		[so_long->player_pos[1] + y] == 'X')
	{
		//bonus->player_health--;
		{
			//clean_exit(so_long, bonus);
			exit (0);
		}
	}
	return ;
}
