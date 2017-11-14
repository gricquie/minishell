/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 12:52:23 by gricquie          #+#    #+#             */
/*   Updated: 2016/11/27 12:52:24 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	while (dest - src > 0 && n > 0)
	{
		((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
		n--;
	}
	return (ft_memcpy(dest, src, n));
}
