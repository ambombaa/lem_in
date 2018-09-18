/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambombaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 17:39:32 by ambombaa          #+#    #+#             */
/*   Updated: 2018/09/12 09:41:13 by ambombaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_trans_ant(t_colony **head, t_colony *new_data)
{
	t_colony	*new_node;
	t_colony	*last;

	new_node = ft_memalloc(sizeof(t_colony));
	last = *head;
	new_node = new_data;
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

void			ft_display(t_colony *ants)
{
	t_colony	*tmp;

	tmp = ants;
	while (tmp)
	{
		ft_putstr(tmp->ant.ant_name);
		ft_putchar('-');
		ft_putstr(tmp->ant.room->str);
		ft_putchar(' ');
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

void			ft_append_ant(t_colony **head, char *new_data)
{
	t_colony	*new_node;
	t_colony	*last;

	new_node = ft_memalloc(sizeof(t_colony));
	last = *head;
	new_node->ant.ant_name = new_data;
	new_node->ant.room = NULL;
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

t_colony		*ft_get_ants(t_location *map)
{
	t_colony	*ant_farm;
	int			i;

	i = 1;
	ant_farm = NULL;
	while (i <= map->ants)
	{
		ft_append_ant(&ant_farm, ft_strjoin("L", ft_itoa(i)));
		i++;
	}
	return (ant_farm);
}

t_colony		*ft_pop(t_colony **head)
{
	t_colony	*pop;

	pop = NULL;
	if (!*head)
		return (NULL);
	pop = *head;
	*head = (*head)->next;
	pop->next = NULL;
	return (pop);
}
