/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 11:25:49 by gricquie          #+#    #+#             */
/*   Updated: 2016/11/27 11:25:50 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	init(char **tab, int n)
{
	int		factor;
	int		size;

	factor = 1;
	size = 1;
	if (n < 0)
	{
		n = -n;
		size++;
	}
	while (n / factor >= 10)
	{
		factor *= 10;
		size++;
	}
	if (!(*tab = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	return (factor);
}

static char	*exception(int n)
{
	char	*tab;
	int		i;
	int		factor;

	if (!(tab = (char *)malloc(sizeof(char) * 12)))
		return (NULL);
	i = 1;
	tab[0] = '-';
	factor = 1000000000;
	while (i < 11)
	{
		tab[i++] = -(n / factor) + 48;
		n = n % factor;
		factor /= 10;
	}
	tab[i] = '\0';
	return (tab);
}

char		*ft_itoa(int n)
{
	int		factor;
	int		i;
	char	*tab;

	i = 0;
	if (n == -2147483648)
		return (exception(n));
	if ((factor = init(&tab, n)) == 0)
		return (NULL);
	if (n < 0)
	{
		tab[i++] = '-';
		n = -n;
	}
	while (factor >= 1)
	{
		tab[i++] = n / factor + 48;
		if (factor == 1)
			break ;
		n = n % factor;
		factor = factor / 10;
	}
	tab[i] = '\0';
	return (tab);
}
