/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambombaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 16:20:38 by ambombaa          #+#    #+#             */
/*   Updated: 2018/08/30 16:20:41 by ambombaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Checks the duplicates and errors with the inputs
*/

char	*check_inputs(char *s1, char *s2, int clean)
{
	char *new_s;

	new_s = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s1[0] == '\0')
		return (s2);
	ft_strcat(new_s, s1);
	ft_strcat(new_s, "\n");
	ft_strcat(new_s, s2);
	ft_strdel(&s1);
	(clean) ? ft_strdel(&s2) : 0;
	return (new_s);
}

/*
** checks the links between the nodes
*/

void	links(t_location *map, char *line)
{
	map->links = check_inputs(map->links, line, 0);
}
