/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:47:49 by bgrulois          #+#    #+#             */
/*   Updated: 2022/06/30 15:06:33 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
#define TILES "10PEC"
#define EXTENSION ".ber"
#define ESC 65307
#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363
#define W 119
#define A 97
#define S 115
#define D 100

typedef struct s_mlx_global
{
	void	*mlx;
	void	*window;
	int	map_dimensions[2];
	int	player_pos[2];
	int	P;
	int	E;
	int	C;
	int	map_fd;
	char	*map_line;
	char	**map_split;
	void	*wall;
	void	*ground;
	void	*player;
	void	*exit;
	void	*exit_open;
	void	*collectible;
	int	img_width;
	int	img_height;
	int	collectibles_left;
	int	step_count;
}		t_mlx_global;

typedef	struct s_mlx_bonus
{
	void	*ennemy;
	int	ennemy_count;
	int	**ennemypos;
	int	player_health;
	int	available_tiles;
}		t_mlx_bonus;

int		ft_strlen(char *str);
int		get_line_size(char *buf);
int		count_lines(char *filename);
int		is_char_in_str(char c, char *str);
//int		verify_first_line(t_mlx_global *so_long);
//int		count_collectibles(t_mlx_global *so_long);
//int		verify_walls(t_mlx_global *so_long);
//int		verify_tiles_values(int	P, int	E, int	C);
//int		verify_tiles(t_mlx_global *so_long);
int		check_bounds(t_mlx_global *so_long);
int		check_wall(t_mlx_global *so_long, int i);
int		check_tiles(t_mlx_global *so_long);
int		global_check(t_mlx_global *so_long);
int		where_is_that_char(char c, char *str);
int		get_action(int keycode, t_mlx_global *so_long);
int		close_window(t_mlx_global *so_long);
int		move_up(t_mlx_global *so_long);
int		move_down(t_mlx_global *so_long);
int		move_left(t_mlx_global *so_long);
int		move_right(t_mlx_global *so_long);
int		can_u_move(t_mlx_global *so_long, int x, int y);
int		can_u_exit(t_mlx_global *so_long, int x, int y);
int		is_collectible(t_mlx_global *so_long, int x, int y);
int 		ft_parsing(char *map_file, t_mlx_global *so_long);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
int	*generate_random_coordinates(int x, int y);
void	init_imgs(t_mlx_global *so_long);
void    draw_map(t_mlx_global *so_long);
void	my_mlx_place_tile(t_mlx_global *so_long, int x, int y);
void	get_map_dimensions(t_mlx_global *so_long);
void	set_img(t_mlx_global *so_long, int texture);
void	get_player_pos(t_mlx_global *so_long);
void	refresh(t_mlx_global *so_long, int offset[2]);
void	ennemies_getpos(t_mlx_global *so_long, t_mlx_bonus *bonus);
void	place_ennemies(t_mlx_global *so_long, t_mlx_bonus *bonus);
void	spawn_ennemies(t_mlx_global *so_long, t_mlx_bonus *bonus);
void	ft_damage(t_mlx_global *so_long, int x, int y);
void	default_init_global(t_mlx_global *so_long);
void	default_init_bonus(t_mlx_bonus *bonus);
void	free_tab(char **tab);
void	free_imgs(t_mlx_global *so_long);
void	free_all(t_mlx_global *so_long, t_mlx_bonus *bonus);
void	clean_exit(t_mlx_global *so_long, t_mlx_bonus *bonus);
int	ft_so_long(t_mlx_global *so_long);
void	clean_exit(t_mlx_global *so_long, t_mlx_bonus *bonus);
t_mlx_global 	*global_init(void);
t_mlx_bonus	*ennemies_init(t_mlx_global *so_long);

#endif
