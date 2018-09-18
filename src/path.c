/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambombaa <ambombaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:40:11 by ambombaa          #+#    #+#             */
/*   Updated: 2018/09/11 16:58:30 by ambombaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int					ft_lstlen(t_string *str)
{
	int				i;

	i = 0;
	while (str)
	{
		i++;
		str = str->next;
	}
	return (i);
}

void				to_list(t_string **wae, char *str)
{
	if (!is_in_list(*wae, str))
		ft_append(wae, str);
}

int					find_index(char **arr, char *str)
{
	int				i;

	i = 0;
	while (arr[i])
	{
		if (ft_strequ(arr[i], str))
			return (i);
		i++;
	}
	return (-1);
}

void				ft_assign_routs(t_colony *ants, t_string *da_wae)
{
	while (ants)
	{
		ants->ant.room = da_wae;
		ants = ants->next;
	}
}

char				*ft_find_last(char *links, char *str)
{
	char			**s1;

	s1 = ft_strsplit(links, '-');
	if (ft_strequ(s1[0], str))
		return (s1[1]);
	else
		return (s1[0]);
	return (NULL);
}
