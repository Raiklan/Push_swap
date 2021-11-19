/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:12:48 by saich             #+#    #+#             */
/*   Updated: 2021/11/19 02:51:55 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	ft_sa(t_check **a, t_check **start_a, int n)
{
	if (ft_lstsize(a) <= 1)
		return ;
	(*a) = (*a)->next;
	(*start_a)->next = (*start_a)->next->next;
	(*a)->next = *start_a;
	*start_a = *a;
	if (n != 0)
		write(1, "sa\n", 4);
}

void	ft_sb(t_check **b, t_check **start_b, int n)
{
	if (ft_lstsize(b) <= 1)
		return ;
	(*b) = (*b)->next;
	(*start_b)->next = (*start_b)->next->next;
	(*b)->next = *start_b;
	*start_b = *b;
	if (n != 0)
		write(1, "sb\n", 4);
}

void	ft_ss(t_check **a, t_check **b, t_check **start_a, t_check **start_b)
{
	ft_sa(a, start_a, 0);
	ft_sb(b, start_b, 0);
	write(1, "ss\n", 4);
}

void	ft_pa(t_check **a, t_check **b, t_check **start_a, t_check **start_b)
{
	t_check	*t;

	if (*b)
	{
		t = *b;
		*b = (*b)->next;
		*start_b = *b;
		t->next = *a;
		*a = t;
		*start_a = *a;
		write(1, "pa\n", 4);
	}
}

void	ft_pb(t_check **a, t_check **b, t_check **start_a, t_check **start_b)
{
	t_check	*t;

	if (*a)
	{
		t = *a;
		*a = (*a)->next;
		*start_a = *a;
		t->next = *b;
		*b = t;
		*start_b = *b;
		write(1, "pb\n", 4);
	}
}
