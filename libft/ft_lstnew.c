/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambombaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:26:08 by ambombaa          #+#    #+#             */
/*   Updated: 2018/09/03 13:26:13 by ambombaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *node_new;

	node_new = (t_list*)malloc(sizeof(t_list));
	if (node_new == NULL)
		return (NULL);
	if (content == NULL)
	{
		node_new->content = NULL;
		node_new->content_size = 0;
	}
	else
	{
		node_new->content = malloc(content_size);
		if (node_new->content == NULL)
			return (NULL);
		ft_memcpy(node_new->content, content, content_size);
		node_new->content_size = content_size;
	}
	node_new->next = NULL;
	return (node_new);
}
