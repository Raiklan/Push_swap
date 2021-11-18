/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 00:08:58 by saich             #+#    #+#             */
/*   Updated: 2021/11/18 01:27:58 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	ft_init_begin(t_begin *begin, t_check *a, t_check *b, t_push *comp)
{
	(*begin).begin_a = a;
	(*begin).begin_b = b;
	(*begin).begin_comp = comp;
}

void	ft_init_comp(t_push **comp, t_pile *pile, t_begin *begin, int i)
{
	(*comp)->median = ft_median(pile, begin, comp, (*comp)->median);
	(*comp)->nb_bloc = i;
	(*comp)->size = 0;
	(*comp)->next = (t_push *)malloc(sizeof(t_push) * 1);
	if (!(*comp)->next)
		ft_error_push(pile, begin, *comp);
}

void	ft_error_push(t_pile *pile, t_begin *begin, t_push *comp)
{
	if (pile->a)
		ft_free_lst(&pile->a);
	if (pile->b)
		ft_free_lst(&pile->b);
	if (begin->begin_a)
		ft_free_lst(&begin->begin_a);
	if (begin->begin_b)
		ft_free_lst(&begin->begin_b);
	if (begin->begin_comp)
		ft_free_lst_push(begin->begin_comp);
	if (comp)
		ft_free_lst_push(comp);
	exit(0);
}
