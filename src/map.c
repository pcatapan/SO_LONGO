/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:01:58 by aanghel           #+#    #+#             */
/*   Updated: 2022/03/24 09:25:39 by pcatapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_fill_matrix(t_map *map, char **matrice)
{
	int	x;
	int	s;
	int	y;

	x = 0;
	y = 0;
	s = 0;
	while (x < map->h)
	{
		y = 0;
		while (y <= map->w)
		{
			if (map->max_line[s] != '\n')
				matrice[x][y] = map->max_line[s];
			else
				matrice[x][y] = '\0';
			s++;
			y++;
		}
		x++;
	}
}

void	ft_print_map_in_shell(t_map *map, char **print)
{
	int	i;
	int	j;

	i = 0;
	ft_printf("\n");
	while (i < map->h)
	{
		j = 0;
		while (print[i][j] != '\0')
		{
			ft_printf(" %c", print[i][j]);
			j++;
		}
		if (print[i][j] == '\0')
			ft_printf("\n");
		i++;
	}
}

void	ft_malloc_matrix(t_map *map, int i)
{
	map->map = malloc(map->h * sizeof(char *));
	map->enemy = malloc(map->h * sizeof(char *));
	if (!map->map || !map->enemy)
		return ;
	while (i < map->h)
	{
		map->map[i] = (char *)malloc(sizeof(char) * (map->w - 1));
		if (!map->map[i])
		{
			free(map->map);
			return ;
		}
		i++;
	}
	i = 0;
	while (i < map->h)
	{
		map->enemy[i] = (char *)malloc(sizeof(char) * (map->w - 1));
		if (!map->enemy[i])
		{
			free(map->enemy);
			return ;
		}
		i++;
	}
}

void	ft_creating_map(t_map *map)
{
	int	i;

	i = 0;
	map->w = map->w - 1;
	ft_malloc_matrix(map, i);
	ft_fill_matrix(map, map->map);
	ft_fill_matrix(map, map->enemy);
	free(map->max_line);
	ft_print_map_in_shell(map, map->map);
	// map->mlx_ptr = mlx_init();
	// map->window = mlx_new_window(map->mlx_ptr, map->w * SIZE, \
	// 				map->h * SIZE, "42 - FAKE PacMan by pcatapan");
	// ft_img(map);
	return ;
}
