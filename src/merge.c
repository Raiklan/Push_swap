/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:25:06 by saich             #+#    #+#             */
/*   Updated: 2021/11/17 17:42:54 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	ft_mergesort(t_check **head)
{
	int		i;
	int		tmp;
	int		len;
	t_check	*begin;

	begin = *head;
	len = ft_lstsize(head);
	i = 0;
	while (i < len)
	{
		if (!((*head)->next))
			(*head) = begin;
		if ((*head)->n > (*head)->next->n)
		{
			tmp = (*head)->n;
			(*head)->n = (*head)->next->n;
			(*head)->next->n = tmp;
			i = 0;
		}
		else
			i++;
		(*head) = (*head)->next;
	}
	(*head) = begin;
}
