/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambombaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 18:12:24 by ambombaa          #+#    #+#             */
/*   Updated: 2018/09/12 10:32:51 by ambombaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_push_to(t_colony **dest, t_colony **src)
{
	t_colony	*tmp;

	tmp = ft_pop(src);
	tmp->ant.room = tmp->ant.room->next;
	ft_trans_ant(dest, tmp);
}

void			ft_move_ants_in_maize(t_colony **ants)
{
	t_colony	*tmp;

	tmp = *ants;
	while (tmp)
	{
		tmp->ant.room = tmp->ant.room->next;
		tmp = tmp->next;
	}
}

void			ft_remove_ants_at_end(t_colony **ants_in_maize, t_location *map)
{
	t_colony	*tmp;

	tmp = *ants_in_maize;
	while (tmp)
	{
		if (ft_strequ(tmp->ant.room->str,
			map->rooms[ft_double_ptr_len((void **)map->rooms) - 1]))
		{
			ft_delete_ant(ants_in_maize,
					map->rooms[ft_double_ptr_len((void **)map->rooms) - 1]);
		}
		tmp = tmp->next;
	}
}

char			*next_in(char *str, char *current)
{
	char		**s;

	s = ft_strsplit(str, '-');
	if (ft_strequ(s[0], current))
		return (s[1]);
	else
		return (s[0]);
	return (NULL);
}
