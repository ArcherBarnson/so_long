#include "so_long.h"

void	reset_ints(t_mlx_global *so_long)
{
	so_long->map_dimensions[0] = 0;
	so_long->map_dimensions[1] = 0;
	so_long->player_pos[0] = 0;
	so_long->player_pos[1] = 0;
	so_long->P = 0;
	so_long->E = 0;
	so_long->C = 0;
	so_long->img_width = 0;
	so_long->img_height = 0;
	so_long->collectibles_left = 0;
	so_long->step_count = 0;
	so_long->map_fd = 0;
}

void	reset_imgs(t_mlx_global *so_long)
{
	so_long->wall = NULL;
	so_long->ground = NULL;
	so_long->player = NULL;
	so_long->exit = NULL;
	so_long->exit_open = NULL;
	so_long->collectible = NULL;
	return ;
}

t_mlx_global	*global_init(void)
{
	t_mlx_global	*so_long;

	so_long = malloc(sizeof(t_mlx_global));
	if (!so_long)
		return (NULL);
	so_long->mlx = NULL;
	so_long->window = NULL;
	so_long->map_line = NULL;
	so_long->map_split = NULL;
	reset_ints(so_long);
	reset_imgs(so_long);
	return (so_long);
}

t_mlx_bonus	*bonus_init(void)
{
	t_mlx_bonus	*bonus;
	bonus = malloc(sizeof(t_mlx_bonus));
	if (!bonus)
		return (NULL);
	bonus->ennemy = NULL;
	bonus->ennemypos = NULL;
	bonus->ennemy_count = 0;
	bonus->available_tiles = 0;
	return (bonus);
}
