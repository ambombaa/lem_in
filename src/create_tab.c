/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambombaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 16:17:12 by ambombaa          #+#    #+#             */
/*   Updated: 2018/08/30 16:17:15 by ambombaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Obtains the number of ants from the lines coming from get_next_lines
*/

void		count_ants(t_location *map, char *line)
{
	int		i;
	char	*s;

	i = 0;
	map->ants_str = check_inputs(map->ants_str, line, 0);
	if (line[0] == '#')
		return ;
	s = ft_strtrim(line);
	if ((map->ants = ft_atoi(s)) <= 0)
		exit_func(map, 1);
	while (s[i] != '\n' && s[i] != 0)
	{
		if (!ft_isdigit(s[i++]))
			exit_func(map, 1);
	}
}
