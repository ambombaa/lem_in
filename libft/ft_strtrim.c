/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambombaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:47:39 by ambombaa          #+#    #+#             */
/*   Updated: 2018/09/03 13:47:42 by ambombaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		begin;
	int		end;
	char	*str;

	if (!s)
		return (NULL);
	begin = -1;
	end = ft_strlen(s);
	while (ft_isspace(s[++begin]))
		NULL;
	while (ft_isspace(s[--end]))
		NULL;
	str = ft_strsub(s, begin, end - begin + 1);
	return (str);
}
