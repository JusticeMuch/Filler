/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jronald <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 01:46:21 by jronald           #+#    #+#             */
/*   Updated: 2018/06/03 16:18:04 by jronald          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void*, size_t))
{
	t_list *nxt;

	nxt = *alst;
	while (nxt)
	{
		del(nxt->content, nxt->content_size);
		free(nxt);
		nxt = nxt->next;
	}
	*alst = NULL;
}
