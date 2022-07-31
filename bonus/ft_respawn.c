#include "../so_long.h"

void	clean_map(t_mlx_global *so_long)
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
				so_long->map_split[i][j] = '0';
				mlx_put_image_to_window(so_long->mlx,
					so_long->window, so_long->ground,
					j * 50, i * 50);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return ;
}
