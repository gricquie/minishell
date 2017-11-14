/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:24:25 by gricquie          #+#    #+#             */
/*   Updated: 2016/12/03 14:24:26 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *tab, size_t size)
{
	unsigned int	i;
	void			*ntab;

	if (!(ntab = malloc(size)))
		return (NULL);
	i = 0;
	if (tab != NULL)
	{
		while (i < size)
		{
			ft_memcpy(ntab + i, tab + i, 1);
			i++;
		}
		free(tab);
	}
	return (ntab);
}
