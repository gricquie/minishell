/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdeljoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gricquie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 16:22:43 by gricquie          #+#    #+#             */
/*   Updated: 2016/12/23 16:35:36 by gricquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdeljoin(t_list *begin, t_list *del)
{
	if (begin == NULL || del == NULL)
		return ;
	while (begin->next != del && begin->next != NULL)
		begin = begin->next;
	if (begin->next == del)
		begin->next = del->next;
	if (del->content)
		free(del->content);
	free(del);
	del = NULL;
}
