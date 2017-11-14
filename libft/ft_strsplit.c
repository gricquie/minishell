/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 13:29:33 by gricquie          #+#    #+#             */
/*   Updated: 2016/11/27 13:29:35 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		split(char const *s, char ***tab, int *i, char c)
{
	int a;
	int j;

	j = 0;
	a = 0;
	while (s[a] != c && s[a])
	{
		if (!((*tab)[*i] = (char*)ft_realloc((void*)((*tab)[*i]),
									sizeof(char) * (j + 1))))
			return (0);
		(*tab)[*i][j++] = s[a++];
	}
	if (!((*tab)[*i] = (char*)ft_realloc((void*)((*tab)[*i]),
									sizeof(char) * (j + 1))))
		return (0);
	(*tab)[(*i)++][j] = '\0';
	while (s[a] == c && s[a])
		a++;
	return (a);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		a;
	int		temp;

	if (s == NULL)
		return (NULL);
	i = 0;
	a = 0;
	tab = NULL;
	while (s[a] == c && s[a])
		a++;
	while (s[a])
	{
		if (!(tab = (char**)ft_realloc((void*)tab, sizeof(char*) * (i + 1))))
			return (NULL);
		tab[i] = NULL;
		if (!(temp = split(s + a, &tab, &i, c)))
			return (NULL);
		a += temp;
	}
	if (!(tab = (char**)ft_realloc((void*)tab, sizeof(char*) * (i + 1))))
		return (NULL);
	tab[i] = NULL;
	return (tab);
}
