#include "so_long.h"

void	free_tab(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return ;
}

void	free_imgs(t_mlx_global *so_long)
{
	if (so_long->wall)
		free(so_long->wall);
	if (so_long->ground)
		free(so_long->ground);
	if (so_long->player)
		free(so_long->player);
	if (so_long->exit)
		free(so_long->exit);
	if (so_long->exit_open)
		free(so_long->exit_open);
	if (so_long->collectible)
		free(so_long->collectible);
	return ;
}

void	free_all(t_mlx_global *so_long, t_mlx_bonus *bonus)
{
	int	i;

	i = -1;
	free_tab(so_long->map_split, so_long->map_dimensions[0]);
	free_imgs(so_long);
	while (++i < 2)
		free(bonus->ennemypos[i]);
	free(bonus->ennemypos);
	if (bonus->ennemy)
		free(bonus->ennemy);
	if (so_long->window)
		free(so_long->window);
	if (so_long->mlx)
		free(so_long->mlx);
	if (so_long)
		free(so_long);
	if (bonus)
		free(bonus);
	return ;
}
