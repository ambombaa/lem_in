/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambombaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 16:57:01 by ambombaa          #+#    #+#             */
/*   Updated: 2018/08/30 16:57:06 by ambombaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** checks if the string is a number so that the program doesnt crash
*/

static void	check_number_input(char **r, t_location *map, char *s)
{
	int i;

	i = 0;
	if (s[0] == '-' || ft_isdigit(s[0]))
	{
		while (s[++i])
		{
			if (!ft_isdigit(s[i]))
				free_array(r, map, 1);
		}
	}
	else
		free_array(r, map, 1);
}

/*
**checks if the room is not a big L
*/

static void	check_the_room(t_location *map, char *line)
{
	char **r;

	r = ft_strsplit(line, ' ');
	if (r[0][0] == 'L' || r[3] != NULL)
		free_array(r, map, 1);
	check_number_input(r, map, r[1]);
	check_number_input(r, map, r[2]);
	free_array(r, map, 0);
}

/*
**reads number of rooms and validate the rooms coordinates
*/

void		rooms(t_location *map, char *line)
{
	map->rooms_list = check_inputs(map->rooms_list, line, 0);
	if (line[0] == '#')
		return ;
	check_the_room(map, line);
	map->room_quantity++;
}
