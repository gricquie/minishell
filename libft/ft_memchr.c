/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 12:48:52 by gricquie          #+#    #+#             */
/*   Updated: 2016/11/27 12:48:53 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ts;
	unsigned int	i;

	i = 0;
	ts = (unsigned char *)s;
	while (i < n)
	{
		if (ts[i] == (unsigned char)c)
			return ((void *)(ts + i));
		i++;
	}
	return (NULL);
}
