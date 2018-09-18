/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambombaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 16:21:01 by ambombaa          #+#    #+#             */
/*   Updated: 2018/08/31 15:28:30 by ambombaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_location	*map_init_2(t_location *map)
{
	int				i;
	int				j;

	i = 0;
	map->init_2 = 1;
	map->table = ft_memalloc(sizeof(int*) * map->room_quantity);
	map->rooms = ft_memalloc(sizeof(char*) * (map->room_quantity + 1));
	while (i < map->room_quantity)
	{
		map->rooms[i] = NULL;
		map->table[i] = ft_memalloc(sizeof(int) * map->room_quantity);
		j = 0;
		while (map->table[i][j])
		{
			map->table[i][j] = 0;
			j++;
		}
		i++;
	}
	map->rooms[i] = NULL;
	return (map);
}

/*
** Reads the number of ants, the rooms, the links
*/

static void			read_map(t_location *map)
{
	char			*line;
	int				flag;

	flag = 0;
	while (get_next_line(0, &line) > 0)
		process(map, line, &flag);
	if (!map->ants || !map->links[0])
		exit_func(map, 1);
	map = map_init_2(map);
}

size_t				ft_double_ptr_len(void **str)
{
	size_t count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

void				cut(t_location *loc)
{
	loc->map = ft_memalloc(sizeof(t_location));
	init(loc->map);
	read_map(loc->map);
	add_rooms(loc->map);
}

int					main(void)
{
	t_location		loc;

	cut(&loc);
	if (!loc.map->good[0] || !loc.map->good[1])
		exit_func(loc.map, 1);
	loc.lin = ft_create_links(loc.map->links);
	loc.path = find_path(loc.map->rooms[0],
	loc.map->rooms[ft_double_ptr_len((void **)loc.map->rooms) - 1], loc.lin);
	loc.len = ft_lstlen(loc.path);
	loc.i = 0;
	loc.current = loc.map->rooms[0];
	loc.wae = NULL;
	ft_append(&loc.wae, loc.current);
	while (loc.path)
	{
		loc.s = ft_strsplit(loc.path->str, '-');
		to_list(&loc.wae, loc.s[0]);
		to_list(&loc.wae, loc.s[1]);
		loc.path = loc.path->next;
	}
	result(loc.map, loc.wae);
	exit_func(loc.map, 0);
}
