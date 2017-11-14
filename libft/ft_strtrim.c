/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 13:32:21 by gricquie          #+#    #+#             */
/*   Updated: 2016/11/27 13:32:22 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == ',' || s[i] == '\n' ||
						s[i] == '\t') && s[i])
		i++;
	while ((s[j] == ' ' || s[j] == ',' || s[j] == '\n' ||
						s[j] == '\t') && j > i)
		j--;
	if (!(str = (char*)malloc(sizeof(char) * (j - i + 2))))
		return (NULL);
	str = ft_strncpy(str, s + i, j - i + 1);
	str[j - i + 1] = '\0';
	return (str);
}
