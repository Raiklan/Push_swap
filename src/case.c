/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 02:32:15 by saich             #+#    #+#             */
/*   Updated: 2021/11/20 02:51:54 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	ft_case1(t_check **a, t_check **start_a)
{
	ft_sa(a, start_a, 1);
	ft_ra(a, start_a, 1);
	ft_sa(a, start_a, 1);
	ft_rra(a, start_a, 1);
	ft_sa(a, start_a, 1);
}

void	ft_case2(t_check **a, t_check **start_a)
{
	ft_sa(a, start_a, 1);
	ft_ra(a, start_a, 1);
	ft_sa(a, start_a, 1);
	ft_rra(a, start_a, 1);
}

void	ft_case3(t_check **a, t_check **start_a)
{
	ft_ra(a, start_a, 1);
	ft_sa(a, start_a, 1);
	ft_rra(a, start_a, 1);
	ft_sa(a, start_a, 1);
}

void	ft_case4(t_check **a, t_check **start_a)
{
	ft_ra(a, start_a, 1);
	ft_sa(a, start_a, 1);
	ft_rra(a, start_a, 1);
}

void	ft_sort3(t_check **a, t_check **start_a)
{
	if (ft_list_size(a) == 2 && (*a)->n > (*a)->next->n)
		ft_sa(a, start_a, 1);
	if (ft_list_size(a) >= 3)
	{
		if ((*a)->n > (*a)->next->n && (*a)->next->n > (*a)->next->next->n)
			ft_case1(a, start_a);
		if (((*a)->n > (*a)->next->n && (*a)->next->n
				< (*a)->next->next->n) && (*a)->n < (*a)->next->next->n)
			ft_sa(a, start_a, 1);
		if (((*a)->n > (*a)->next->n && (*a)->next->n
				< (*a)->next->next->n) && (*a)->n > (*a)->next->next->n)
			ft_case2(a, start_a);
		if (((*a)->n < (*a)->next->n && (*a)->next->n
				> (*a)->next->next->n) && (*a)->n > (*a)->next->next->n)
			ft_case3(a, start_a);
		if (((*a)->n < (*a)->next->n && (*a)->next->n
				> (*a)->next->next->n) && (*a)->n < (*a)->next->next->n)
			ft_case4(a, start_a);
	}
}
