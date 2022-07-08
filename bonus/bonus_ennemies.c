#include "so_long.h"
#include "so_long_bonus.h"

void	ennemies_getpos(t_mlx_global *so_long, t_mlx_bonus *bonus)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	x = 0;
	i = 0;
	while (y < so_long->map_dimensions[0] / 50)
	{
		x = 0;
		while (x < so_long->map_dimensions[1] / 50)
		{
			if (so_long->map_split[x][y] == 'X')
			{
				bonus->ennemypos[i][0] = y;
				bonus->ennemypos[i][1] = x;
				i++;
			}
			x++;
		}
		y++;
	}
	return ;
}

void	place_ennemies(t_mlx_global *so_long, t_mlx_bonus *bonus)
{
	int	x;
	int	y;

	x = 2;
	y = 3;
	while (x < so_long->map_dimensions[0] / 50)
	{
		while (y < so_long->map_dimensions[1] / 50)
		{
			if (so_long->map_split[x][y] == '0')
			{
				mlx_put_image_to_window(so_long->mlx, so_long->window,
						bonus->ennemy, x * 50, y * 50);
				so_long->map_split[x][y] = 'X';
			}
			printf("%s\n", so_long->map_split[x]);
			printf("\nec=%i\nx=%i\ny=%i\n", bonus->ennemy_count, x, y);
			y += 2;
		}
		y = 3;
		x += 2;
	}
	return ;
}

void	spawn_ennemies(t_mlx_global *so_long, t_mlx_bonus *bonus)
{
	int	a;
	int	b;

	bonus->ennemy = mlx_xpm_file_to_image(so_long->mlx,
			"../sl_assets/debug_ennemy.xpm", &a, &b);
	while (bonus->ennemy_count != 0)
		place_ennemies(so_long, bonus);
	return ;
}

t_mlx_bonus	*ennemies_init(t_mlx_global *so_long)
{
	t_mlx_bonus *bonus;

	bonus = malloc(sizeof(t_mlx_bonus));
	if (!bonus)
		return (NULL);
	bonus->ennemy_count = 10;
	bonus->player_health = 1;
	bonus->ennemypos = malloc(sizeof(int *) * bonus->ennemy_count);
	if (!bonus->ennemypos)
		return (NULL);
	spawn_ennemies(so_long, bonus);
	ennemies_getpos(so_long, bonus);
	return (bonus);
}

void	ft_damage(t_mlx_global *so_long, t_mlx_bonus *bonus)
{
	int	i;

	i = 0;
	while (i < bonus->ennemy_count)
	{
		if (so_long->player_pos[0] == bonus->ennemypos[i][0] &&
			so_long->player_pos[1] == bonus->ennemypos[i][1])
		{
			bonus->player_health--;
			if (bonus->player_health == 0)
				exit(0);
		}
		i++;
	}
	return ;
}
