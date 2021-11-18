/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 23:17:04 by saich             #+#    #+#             */
/*   Updated: 2021/11/18 01:27:33 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	ft_free_lst(t_check **p)
{
	if ((*p)->next)
		ft_free_lst(&(*p)->next);
	free(*p);
}

void	ft_free_lst_push(t_push *p)
{
	if (p->next)
		ft_free_lst_push(p->next);
	free(p);
}

int	ft_is_sorted(t_check *a)
{
	t_check	*start;

	start = a;
	while (a)
	{
		if (a->n > a->next->n)
			return (0);
		a = a->next;
	}
	a = start;
	return (1);
}

int	ft_median(t_pile *pile, t_begin *begin, t_push **comp, int n)
{
	t_check	*temporary;
	t_check	*start;
	int		i;

	start = pile->tmp;
	temporary = ft_lst_dup(pile->tmp, pile, begin, comp);
	ft_mergesort(&pile->tmp);
	i = ft_lstsize(&temporary);
	if (i % 2 == 0)
		n = i / 2 - 1;
	else
		n = i / 2;
	i = -1;
	while (++i < n)
		pile->tmp = pile->tmp->next;
	n = pile->tmp->n;
	pile->tmp = start;
	ft_free_lst(&temporary);
	return (n);
}
