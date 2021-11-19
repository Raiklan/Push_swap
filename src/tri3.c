/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:36:26 by saich             #+#    #+#             */
/*   Updated: 2021/11/19 16:25:07 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

t_check	*ft_3fast(t_check **a, t_begin *b)
{
	if (ft_lstsize(a) == 2 && (*a)->n > (*a)->next->n)
		ft_sa(a, &b->begin_a, 1);
	if (ft_lstsize(a) == 3)
	{
		if (((*a)->n > (*a)->next->n && (*a)->next->n < (*a)->next->next->n
				&& (*a)->n < (*a)->next->next->n) || ((*a)->n < (*a)->next->n
				&& (*a)->next->n > (*a)->next->next->n && (*a)->n
				< (*a)->next->next->n) || ((*a)->n
				> (*a)->next->n && (*a)->next->n > (*a)->next->next->n
				&& (*a)->n > (*a)->next->next->n))
			ft_sa(a, &b->begin_a, 1);
		if ((*a)->n < (*a)->next->n && (*a)->next->n > (*a)->next->next->n
			&& (*a)->n > (*a)->next->next->n)
			ft_rra(a, &b->begin_a, 1);
		if ((*a)->n > (*a)->next->n && (*a)->next->n < (*a)->next->next->n
			&& (*a)->n > (*a)->next->next->n)
			ft_ra(a, &b->begin_a, 1);
		if ((*a)->n < (*a)->next->n && (*a)->next->n > (*a)->next->next->n
			&& (*a)->n < (*a)->next->next->n)
			ft_ra(a, &b->begin_a, 1);
		if ((*a)->n > (*a)->next->n && (*a)->next->n > (*a)->next->next->n
			&& (*a)->n > (*a)->next->next->n)
			ft_sa(a, &b->begin_a, 1);
	}
	return (b->begin_a);
}
