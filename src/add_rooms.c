/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambombaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 16:16:51 by ambombaa          #+#    #+#             */
/*   Updated: 2018/08/30 16:16:54 by ambombaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Checks the start and the end of the input in the map
*/

static void	check_start_end(t_location *map, char **r, int end)
{
	if (end)
	{
		map->rooms[map->room_quantity - 1] = ft_strdup(r[0]);
		(map->good[1])++;
		return ;
	}
	map->rooms[0] = ft_strdup(r[0]);
	(map->good[0])++;
}

static void	good(t_location *map, char **line, char **r, int end)
{
	map->good[end]++;
	if (map->good[end] > 1)
	{
		free_array(r, map, 0);
		free_array(line, map, 1);
	}
}

/*
** Finds the index of a room
*/

int			room_index(t_location *map, char *room_name, int start)
{
	int		index;

	index = (start) ? 0 : 1;
	while (map->rooms[index] && index < map->room_quantity)
	{
		if (ft_strequ(map->rooms[index], room_name) == 1)
			return (index);
		index++;
	}
	return (index);
}

/*
** Checks if the line has a room name and parameter
*/

static void	room_validity(t_location *map, int i, char **r)
{
	int		r_index;

	r_index = room_index(map, r[0], 0);
	if (r_index > 0 && i != r_index)
		exit_func(map, 1);
	map->rooms[i] = ft_strdup(r[0]);
}

/*
** Checking every line that we red and we added every room that we red
*/

void		add_rooms(t_location *map)
{
	int		i;
	int		j;
	char	**line;
	char	**r;

	i = 0;
	j = 1;
	line = ft_strsplit(map->rooms_list, '\n');
	while (line[i] && j < map->room_quantity)
	{
		r = ft_strsplit(line[i], ' ');
		if (ft_strequ("##start", line[i]))
			good(map, line, r, 0);
		else if (ft_strequ("##end", line[i]))
			good(map, line, r, 1);
		else if (map->good[0] == 1 && line[i][0] != '#')
			check_start_end(map, r, 0);
		else if (map->good[1] == 1 && line[i][0] != '#')
			check_start_end(map, r, 1);
		else if (line[i][0] != '#')
			room_validity(map, j++, r);
		free_array(r, map, 0);
		i++;
	}
	free_array(line, map, 0);
}
