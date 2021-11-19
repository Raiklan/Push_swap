/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 01:32:04 by saich             #+#    #+#             */
/*   Updated: 2021/11/18 13:09:33 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	ft_ra(t_check **a, t_check **start_a, int n)
{
	t_check	*t;

	t = NULL;
	if ((*a) && (*a)->next)
	{
		t = *a;
		*start_a = (*a)->next;
		t->next = NULL;
		while ((*a)->next)
			(*a) = (*a)->next;
		(*a)->next = t;
		*a = *start_a;
		if (n != 0)
			write(1, "ra\n", 4);
	}
}

void	ft_rb(t_check **b, t_check **start_b, int n)
{
	t_check	*t;

	t = NULL;
	if ((*b) && (*b)->next)
	{
		t = *b;
		*start_b = (*b)->next;
		t->next = NULL;
		while ((*b)->next)
			(*b) = (*b)->next;
		(*b)->next = t;
		*b = *start_b;
		if (n != 0)
			write(1, "rb\n", 4);
	}
}

void	ft_rr(t_check **a, t_check **b, t_check **start_a, t_check **start_b)
{
	ft_ra(a, start_a, 0);
	ft_rb(b, start_b, 0);
	write(1, "rr\n", 4);
}

void	ft_rra(t_check **a, t_check **start_a, int n)
{
	t_check	*t;

	t = NULL;
	if ((*a) && (*a)->next)
	{
		while ((*a)->next->next)
			*a = (*a)->next;
		t = (*a)->next;
		(*a)->next = NULL;
		*a = *start_a;
		t->next = *a;
		*start_a = t;
		*a = *start_a;
		if (n != 0)
			write(1, "rra\n", 5);
	}
}

void	ft_rra(t_check **b, t_check **start_b, int n)
{
	t_check	*t;

	t = NULL;
	if ((*b) && (*b)->next)
	{
		while ((*b)->next->next)
			*b = (*b)->next;
		t = (*b)->next;
		(*b)->next = NULL;
		*b = *start_b;
		t->next = *b;
		*start_b = t;
		*b = *start_b;
		if (n != 0)
			write(1, "rrb\n", 5);
	}
}
