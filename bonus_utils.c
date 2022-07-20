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

void	ft_damage(t_mlx_global *so_long, int x, int y)
{
	if (so_long->map_split[so_long->player_pos[0] + x]
		[so_long->player_pos[1] + y] == 'X')
			clean_exit(so_long, NULL);
	return ;
}
