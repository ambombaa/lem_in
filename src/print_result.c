/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambombaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 16:56:09 by ambombaa          #+#    #+#             */
/*   Updated: 2018/09/11 18:12:14 by ambombaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_leni(int n)
{
	int i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char		*num;
	int			end;
	int			sign;
	long int	nu;

	nu = (long int)n;
	if (nu == 0)
		return (ft_strdup("0"));
	end = ft_leni(nu);
	sign = 0;
	if (nu < 0)
	{
		nu *= -1;
		sign = 1;
		end++;
	}
	if (!(num = ft_strnew(end)))
		return (NULL);
	while (end--)
	{
		num[end] = (nu % 10) + 48;
		nu = nu / 10;
	}
	num[0] = (sign == 1) ? '-' : num[0];
	return (num);
}

int				ft_bouncer(t_colony *ft_move_ants_in_maize, char *room)
{
	t_colony	*tmp;

	tmp = ft_move_ants_in_maize;
	while (tmp)
	{
		if (ft_strequ(tmp->ant.room->str, room))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void			ft_delete_ant(t_colony **head_ref, char *key)
{
	t_colony	*temp;
	t_colony	*prev;

	temp = *head_ref;
	prev = NULL;
	if (temp != NULL && ft_strequ(temp->ant.room->str, key))
	{
		*head_ref = temp->next;
		free(temp->ant.ant_name);
		free(temp);
		return ;
	}
	while (temp != NULL && !ft_strequ(temp->ant.room->str, key))
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return ;
	prev->next = temp->next;
	free(temp->ant.ant_name);
	free(temp);
}

/*
** print all the ants within the rooms
*/

void			result(t_location *map, t_string *q)
{
	t_colony	*ants_in_start;
	t_colony	*ants_in_maize;

	ft_putendl(map->ants_str);
	ft_putendl(map->rooms_list);
	ft_putendl(map->links);
	ft_putchar('\n');
	ants_in_maize = NULL;
	ants_in_start = ft_get_ants(map);
	ft_assign_routs(ants_in_start, q);
	ft_push_to(&ants_in_maize, &ants_in_start);
	ft_display(ants_in_maize);
	ft_remove_ants_at_end(&ants_in_maize, map);
	while (1)
	{
		ft_move_ants_in_maize(&ants_in_maize);
		if (ft_bouncer(ants_in_maize, q->next->str))
			if (ants_in_start)
				ft_push_to(&ants_in_maize, &ants_in_start);
		ft_display(ants_in_maize);
		ft_remove_ants_at_end(&ants_in_maize, map);
		if (!ants_in_maize && !ants_in_start)
			break ;
	}
}
