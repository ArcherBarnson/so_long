#include "so_long.h"

void	place_ennemies(t_mlx_global *so_long, t_mlx_bonus *bonus)
{
	int	cols;
	int	rows;
	int	rec;
	int	*rcords;

	cols = so_long->map_dimensions[0] / 50;
	rows = so_long->map_dimensions[1] / 50;
	rec = bonus->ennemy_count;
	//printf("\nrec=%i\nx=%i\ny=%i\n", rec, cols, rows);
	rcords = generate_random_coordinates(cols, rows);
	while (rec > 0)
	{
		printf("\nrec=%i\n", rec);
		rcords = generate_random_coordinates(cols, rows);
		if ((rcords[0] < cols - 1 && rcords[1] < rows -1) 
			&& so_long->map_split[rcords[0]][rcords[1]] == '0')
		{
			so_long->map_split[rcords[0]][rcords[1]] = 'X';
			rec--;
		}
	}
	free(rcords);
	return ;
}

void 	spawn_ennemies(t_mlx_global *so_long, t_mlx_bonus *bonus)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (so_long->map_split[i] != NULL)
	{
		while (so_long->map_split[i][j] != '\n'
			&& so_long->map_split[i][j] != '\0')
		{
			if (so_long->map_split[i][j] == 'X')
			{
				printf("spawnEnnemies_J = %i\n", j);
				printf("spawnEnnemies_I = %i\n", i);
				mlx_put_image_to_window(so_long->mlx,
						so_long->window,
						bonus->ennemy, j * 50, i * 50);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return ;
}

void	load_ennemies(t_mlx_global *so_long, t_mlx_bonus *bonus)
{
	int	a;
	int	b;

	bonus->ennemy = mlx_xpm_file_to_image(so_long->mlx,
			"../sl_assets/test_ennemy.xpm", &a, &b);
	place_ennemies(so_long, bonus);
	return ;
}

void	default_init_bonus(t_mlx_bonus *bonus)
{
	if (bonus != NULL)
	{
		bonus->ennemy = NULL;
		bonus->ennemy_count = 0;
		bonus->ennemypos = NULL;
		bonus->available_tiles = 0;
	}
	return ;
}

int	count_available_tiles(t_mlx_global *so_long)
{
	int	i;
	int	j;
	int	available_tiles;

	i = 0;
	j = 0;
	available_tiles = 0;
	while (so_long->map_split[i] != NULL)
	{
		while (so_long->map_split[i][j] != '\n'
			&& so_long->map_split[i][j] != '\0')
		{
			if (so_long->map_split[i][j] == '0')
				available_tiles++;
			j++;
		}
		j = 0;
		i++;
	}
	return (available_tiles);
}

t_mlx_bonus	*ennemies_init(t_mlx_global *so_long)
{
	t_mlx_bonus	*bonus;
	//int		i;

	//i = 0;
	bonus = malloc(sizeof(t_mlx_bonus));
	if (!bonus)
		return (NULL);
	default_init_bonus(bonus);
	bonus->available_tiles = count_available_tiles(so_long);
	bonus->ennemy_count = bonus->available_tiles / RATIO;
	bonus->ennemypos = malloc(sizeof(int *) * bonus->ennemy_count);
	if (!bonus->ennemypos)
		return (NULL);
	/*while (i < bonus->ennemy_count)
	{
		bonus->ennemypos[i] = malloc(sizeof(int) * 2);
		if (!bonus->ennemypos[i])
			return (NULL);
		i++;
	}*/
	load_ennemies(so_long, bonus);
	spawn_ennemies(so_long, bonus);
	return (bonus);
}
