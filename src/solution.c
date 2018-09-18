/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambombaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 17:06:19 by ambombaa          #+#    #+#             */
/*   Updated: 2018/09/12 10:31:31 by ambombaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				process(t_location *map, char *line, int *flag)
{
	if (map->ants == 0)
	{
		count_ants(map, line);
		*flag = 1;
	}
	else if (ft_strchr(line, '-') || *flag == 3)
	{
		if (*flag == 2)
			*flag = 3;
		if (*flag != 3)
			exit_func(map, 1);
		links(map, line);
	}
	else if ((*flag == 1 || *flag == 2) && !is_empty(line))
	{
		rooms(map, line);
		*flag = 2;
	}
	else
		exit_func(map, 1);
}

t_string			*ft_create_links(char *links)
{
	char			**s;
	t_string		*l;
	int				i;

	l = NULL;
	s = ft_strsplit(links, '\n');
	i = 0;
	while (s[i])
	{
		if (s[i][0] != '#')
			ft_append(&l, s[i]);
		i++;
	}
	return (l);
}

int					is_in(char *str, char *find)
{
	char			**s;

	s = ft_strsplit(str, '-');
	if (ft_strequ(s[0], find))
		return (1);
	if (ft_strequ(s[1], find))
		return (1);
	return (0);
}

int					is_in_list(t_string *path, char *str)
{
	while (path)
	{
		if (path == NULL)
			return (0);
		if (ft_strequ(str, path->str))
			return (1);
		path = path->next;
	}
	return (0);
}

t_string			*find_str(t_string *l, char *f, t_string *p, t_string *c)
{
	char			**s;

	s = NULL;
	while (l)
	{
		if (!is_in_list(p, l->str) || !is_in_list(c, l->str))
		{
			s = ft_strsplit(l->str, '-');
			if (ft_strequ(s[0], f))
				return (l);
			if (ft_strequ(s[1], f))
				return (l);
		}
		l = l->next;
	}
	return (NULL);
}
