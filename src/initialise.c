/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambombaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:05:59 by ambombaa          #+#    #+#             */
/*   Updated: 2018/09/05 11:06:11 by ambombaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				init(t_location *map)
{
	map->links = ft_strnew(1);
	map->ants_str = ft_strnew(1);
	map->rooms_list = ft_strnew(1);
	map->room_quantity = 0;
	map->ants = 0;
	map->current_room = 0;
	map->last_path_index = 0;
	map->init_2 = 0;
	map->good[0] = 0;
	map->good[1] = 0;
	map->rooms = NULL;
	map->table = NULL;
}

/*
**Initialises the map to we are going to use
*/

int					is_empty(char *s)
{
	int				i;

	i = 0;
	while (s[i])
	{
		if (!ft_isspace(s[i]))
			break ;
		i++;
	}
	if (i == ft_strlen(s))
		return (1);
	return (0);
}

/*
** Initialises the structure
*/

void				ft_append(t_string **head, char *new_data)
{
	t_string		*new_node;
	t_string		*last;

	new_node = ft_memalloc(sizeof(t_string));
	last = *head;
	new_node->str = new_data;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return ;
}
