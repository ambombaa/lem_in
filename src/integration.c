/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integration.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambombaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:07:21 by ambombaa          #+#    #+#             */
/*   Updated: 2018/09/13 14:00:48 by ambombaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				ft_del_last(t_string **head)
{
	t_string		*tmp;
	t_string		*last;

	tmp = *head;
	last = tmp->next;
	while (last->next)
	{
		last = last->next;
		tmp = tmp->next;
	}
	tmp->next = NULL;
	free(last);
}

t_string			*find_last(t_string *last)
{
	while (last->next)
		last = last->next;
	return (last);
}

void				delete_node(t_string **head_ref, char *key)
{
	t_string		*temp;
	t_string		*prev;

	temp = *head_ref;
	if (temp != NULL && ft_strequ(temp->str, key))
	{
		*head_ref = temp->next;
		free(temp);
		return ;
	}
	while (temp != NULL && !ft_strequ(temp->str, key))
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return ;
	prev->next = temp->next;
	free(temp);
}

void				ini(t_pathfinding *path, char *start)
{
	path->found = 0;
	path->path = NULL;
	path->closedset = NULL;
	path->t = NULL;
	path->current = ft_strdup(start);
}

t_string			*find_path(char *start, char *end, t_string *links)
{
	t_pathfinding	path;

	ini(&path, start);
	while (path.found == 0)
	{
		path.tmp = find_str(links, path.current, path.path, path.closedset);
		if (path.tmp == NULL)
		{
			path.t = ft_strdup(find_last(path.path)->str);
			ft_putendl(path.t);
			ft_append(&path.closedset, path.t);
			path.current = ft_find_last(path.t, path.current);
			delete_node(&path.path, path.t);
			continue ;
		}
		if (path.tmp)
		{
			ft_append(&path.path, ft_strdup(path.tmp->str));
			delete_node(&links, path.tmp->str);
			path.current = next_in(path.tmp->str, path.current);
		}
		if (ft_strequ(path.current, end))
			path.found = 1;
	}
	return (path.path);
}
