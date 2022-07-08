#include "so_long.h"

void	default_init_global(t_mlx_global *so_long)
{
	if (so_long != NULL)
	{
		so_long->mlx = NULL;
		so_long->window = NULL;
		so_long->P = 0;
		so_long->E = 0;
		so_long->C = 0;
		so_long->map_dimensions[0] = 0;
		so_long->map_dimensions[1] = 0;
		//so_long->map_split = NULL;
		so_long->player_pos[0] = 0;
		so_long->player_pos[1] = 0;
		so_long->map_fd = 0;
		so_long->wall = NULL;
		so_long->ground = NULL;
		so_long->player = NULL;
		so_long->exit = NULL;
		so_long->exit_open = NULL;
		so_long->collectible = NULL;
		so_long->img_width = 0;
		so_long->img_height = 0;
		so_long->collectibles_left = 0;
		so_long->step_count = 0;
	}
	return ;
}

void	default_init_bonus(t_mlx_bonus *bonus)
{
	if (bonus != NULL)
	{
		//bonus->ennemy = NULL;
		bonus->ennemy_count = 0;
		bonus->player_health = 0;
		bonus->ennemypos = NULL;
	}
	return ;
}

void	clean_exit(t_mlx_global *so_long, t_mlx_bonus *bonus)
{
	free_all(so_long, bonus);
	exit(0);
	return ;
}
