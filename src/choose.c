/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:18:33 by saich             #+#    #+#             */
/*   Updated: 2021/11/19 03:06:09 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

t_check	*ft_choose(t_pile *pile)
{
	t_begin	begin;
	t_push	*comp;
	t_check	*finish;

	finish = ft_lst_dup(pile->a, pile, &begin, &comp);
	begin.begin_a = pile->a;
	ft_mergesort(&finish);
	if (ft_lst_comp(pile->a, finish) == 1 || ft_lstsize(&pile->a) <= 3)
	{
		if (ft_lst_comp(pile->a, finish) == 0)
			ft_3fast(&pile->a, &begin);
		ft_free_lst(&finish);
		return (pile->a);
	}
	pile->tmp = ft_lst_dup(pile->a, pile, &begin, &comp);
	comp = (t_push *)malloc(sizeof(t_push));
	if (!comp)
		ft_error_push(pile, &begin, comp);
	ft_init(&comp, pile, &begin);
	ft_free_lst(&pile->tmp);
	ft_quicksort(pile, &begin, &comp, finish);
	if (pile->b)
		ft_free_lst(&pile->b);
	ft_free_lst(&finish);
	return (begin.begin_a);
}

void	ft_init(t_push **comp, t_pile *pile, t_begin *begin)
{
	ft_init_comp(comp, pile, begin, *comp);
	ft_init_begin(begin, pile->a, pile->b, *comp);
}

/*
	ft_init_comp(&comp, pile, &begin, comp);
	ft_init_begin(&begin, pile->a, pile->b, comp);
*/
