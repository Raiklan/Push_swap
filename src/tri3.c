/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:36:26 by saich             #+#    #+#             */
/*   Updated: 2021/11/20 02:28:56 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

t_check	*ft_lst_n_dup_b(t_pile *pile, t_begin *begin, t_push **comp, int n)
{
	t_check	*new;
	t_check	*start;

	new = (t_check *)malloc(sizeof(t_check));
	if (!(new))
		ft_error_ps(pile, begin, *comp);
	start = new;
	while (begin->begin_b && n > 0)
	{
		new->n = begin->begin_b->n;
		new->next = (t_check *)malloc(sizeof(t_check));
		if (!(new->next))
			ft_error_ps(pile, begin, *comp);
		begin->begin_b = begin->begin_b->next;
		n--;
		if (begin->begin_b && n > 0)
			new = new->next;
	}
	free(new->next);
	new->next = NULL;
	new = start;
	return (new);
}

t_check	*ft_lst_n_dup_a(t_pile *pile, t_begin *begin, t_push **comp, int n)
{
	t_check	*new;
	t_check	*start;

	new = (t_check *)malloc(sizeof(t_check));
	if (!new)
		ft_error_push(pile, begin, *comp);
	start = new;
	while (begin->begin_a && n > 0)
	{
		new->n = begin->begin_a->n;
		new->next = (t_check *)malloc(sizeof(t_check));
		if (!new->next)
			ft_error_push(pile, begin, comp);
		begin->begin_a = begin->begin_a->next;
		n--;
		if (begin->begin_a && n > 0)
			new = new->next;
	}
	free(new->next);
	new->next = NULL;
	new = start;
	return (new);
}

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
