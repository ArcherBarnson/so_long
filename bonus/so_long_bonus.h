#ifndef	SO_LONG_BONUS_H
# define SO_LONG_BONUS_H 

typedef	struct s_mlx_bonus
{
	void	*ennemy;
	int	ennemy_count;
	int	**ennemypos;
	int	player_health;
}		t_mlx_bonus;

void	ennemies_getpos(t_mlx_global *so_long, t_mlx_bonus *bonus);
void	place_ennemies(t_mlx_global *so_long, t_mlx_bonus *bonus);
void	spawn_ennemies(t_mlx_global *so_long, t_mlx_bonus *bonus);
void	ft_damage(t_mlx_global *so_long, t_mlx_bonus *bonus);
t_mlx_bonus	*ennemies_init(t_mlx_global *so_long);

#endif
