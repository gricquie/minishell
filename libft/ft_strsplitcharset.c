/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitcharset.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 14:00:47 by gricquie          #+#    #+#             */
/*   Updated: 2016/12/04 14:00:49 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*split(char **tab, char const **s, char const *c)
{
	char	*end;

	end = NULL;
	while (*s >= end)
	{
		end = ft_strstr(*s, c);
		if (end == NULL && **s)
		{
			if (!(*tab = (char *)ft_memalloc(ft_strlen(*s) + 1)))
				return (NULL);
			*tab = ft_strncpy(*tab, *s, ft_strlen(*s));
			(*tab)[ft_strlen(*s)] = '\0';
		}
		if (end == NULL)
		{
			*(tab + (**s ? 1 : 0)) = NULL;
			return (end);
		}
		if (*s == end)
			*s += ft_strlen(c);
	}
	return (end);
}

char			**ft_strsplitcharset(char const *s, char const *c)
{
	char	**tab;
	char	*end;
	size_t	size;

	end = (char *)s;
	tab = NULL;
	size = 0;
	if (s == NULL || c == NULL)
		return (NULL);
	while (*s)
	{
		if (!(tab = (char **)ft_realloc(tab, sizeof(char *) * (size + 2))))
			return (NULL);
		if (!(end = split(tab + size, &s, c)))
			return (tab);
		if (!(tab[size] = (char *)ft_memalloc(sizeof(char) * (end - s + 1))))
			return (NULL);
		tab[size] = ft_strncpy(tab[size], s, end - s);
		tab[size++][end - s + 1] = '\0';
		s = end;
	}
	tab[size] = NULL;
	return (tab);
}
