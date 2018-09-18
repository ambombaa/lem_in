/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambombaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:46:50 by ambombaa          #+#    #+#             */
/*   Updated: 2018/09/03 13:46:53 by ambombaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cchar(const char *str, char c, int i)
{
	int d;

	d = 0;
	while (str[i] != c && str[i++] != '\0')
		d++;
	return (d);
}

static int	ft_cword(const char *str, char c)
{
	int num;
	int i;

	i = 0;
	num = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			i = i + ft_cchar(str, c, i) - 1;
			num++;
		}
		i++;
	}
	return (num);
}

static char	**ft_buidar(char const *s, char c, char **ar_str)
{
	int i;
	int k;
	int j;

	i = 0;
	k = 0;
	while (k < ft_cword(s, c))
	{
		j = 0;
		if (s[i] != c)
		{
			ar_str[k] = (char*)malloc(sizeof(char) * ft_cchar(s, c, i) + 1);
			while (ft_cchar(s, c, i) > 0)
				ar_str[k][j++] = s[i++];
			ar_str[k][j++] = '\0';
			k++;
		}
		i++;
	}
	ar_str[k] = NULL;
	return (ar_str);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ar_str;

	if (!s)
		return (NULL);
	ar_str = (char**)malloc(sizeof(char*) * ft_cword(s, c) + 1);
	if (ar_str == NULL)
		return (NULL);
	ft_bzero(ar_str, sizeof(char*) * ft_cword(s, c) + 1);
	ar_str = ft_buidar(s, c, ar_str);
	return (ar_str);
}
