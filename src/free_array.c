/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambombaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 16:17:45 by ambombaa          #+#    #+#             */
/*   Updated: 2018/08/30 16:17:51 by ambombaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_array(char **array, t_location *map, int error)
{
	int i;

	i = 0;
	while (array[i])
		(array[i]) ? free(array[i++]) : 0;
	free(array);
	if (error)
		exit_func(map, 1);
	array = NULL;
}

void	exit_func(t_location *map, int error)
{
	int i;

	free(map->links);
	free(map->ants_str);
	free(map->rooms_list);
	if (map->init_2)
	{
		free_array(map->rooms, map, 0);
		i = 0;
		while (i < map->room_quantity)
		{
			free(map->table[i]);
			i++;
		}
		free(map->table);
	}
	free(map);
	if (error)
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(1);
	}
	exit(0);
}
