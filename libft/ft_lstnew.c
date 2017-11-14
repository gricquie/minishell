/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 12:46:40 by gricquie          #+#    #+#             */
/*   Updated: 2016/11/27 12:46:41 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new->content_size = content_size;
	if (!(new->content = malloc(content_size)))
		return (NULL);
	if (content == NULL)
	{
		new->content_size = 0;
		new->content = NULL;
	}
	else
		new->content = ft_memcpy(new->content, content, content_size);
	new->next = NULL;
	return (new);
}
