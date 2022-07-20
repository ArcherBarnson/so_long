#include "so_long.h"

int	verify_extension(char *map_file)
{
	int	len;

	len = ft_strlen(map_file);
	if (map_file[len - 4] == '.' && map_file[len - 3] == 'b'
		&& map_file[len - 2] == 'e' && map_file[len - 1] == 'r')
		return (0);
	return (-1);
}

int	check_wall(t_mlx_global *so_long, int i)
{
	int	j;

	j = 0;
	if (i == 0 || so_long->map_split[i + 1] == NULL)
	{
		while (so_long->map_split[i][j] != '\n'
			&& so_long->map_split[i][j] != '\0')
		{
			if (so_long->map_split[i][j] != '1')
				return (-1);
			j++;
		}
	}
	else
	{
		while (so_long->map_split[i][j] != '\n'
			&& so_long->map_split[i][j] != '\0')
			j++;
		if (so_long->map_split[i][0] != '1'
			&& so_long->map_split[i][j] != '1')
			return (-1);
	}
	return (0);
}

int	check_bounds(t_mlx_global *so_long)
{
	int	i;
	int	len;

	i = 0;
	len = get_line_size(so_long->map_split[i]);
	while (so_long->map_split[i] != NULL)
	{
		if (len != get_line_size(so_long->map_split[i]))
			return (-1);
		if (check_wall(so_long, i) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	check_tiles(t_mlx_global *so_long)
{
	int	i;
	int	j;
	int	tile;

	i = -1;
	j = 0;
	while (so_long->map_split[++i] != NULL)
	{
		while (so_long->map_split[i][j] != '\n'
			&& so_long->map_split[i][j] != '\0')
		{
			tile = where_is_that_char(so_long->map_split[i][j],
				TILES);
			printf("TILE = %i\n", tile);
			if (tile == -1)
				return (-1);
			if (tile == 2)
				so_long->P++;
			if (tile == 3)
				so_long->E++;
			if (tile == 4)
				so_long->C++;
			j++;
		}
		j = 0;
	}
	return (0);
}

int	ft_parsing(char *map_file, t_mlx_global *so_long)
{
	char	*tmpline;

	if (verify_extension(map_file) == -1)
		return (-2);
	so_long->map_fd = open(map_file, O_RDONLY, 0644);
	if (so_long->map_fd <= 0)
		return (-1);
	tmpline = get_next_line(so_long->map_fd);
	while (tmpline != NULL)
	{
		so_long->map_line = ft_strjoin(so_long->map_line, tmpline);
		so_long->map_line = ft_strjoin(so_long->map_line, "|");
		tmpline = get_next_line(so_long->map_fd);
	}
	free(tmpline);
	so_long->map_split = ft_split(so_long->map_line, '|');
	if (check_bounds(so_long) == -1)
		return (-3);
	if (check_tiles(so_long) == -1)
		return (-4);
	if (so_long->P != 1)
		return (-5);
	if (so_long->E < 1 || so_long->C < 1)
		return (-6);
	return (0);
}
