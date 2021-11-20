/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:40:11 by saich             #+#    #+#             */
/*   Updated: 2021/11/20 02:28:23 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	ft_pushout_of_a(t_pile *pile, t_begin *begin, t_push **comp, int n)
{
	int	i;
	int	j;

	j = (*comp)->nb_bloc + 1;
	(*comp)->next = (t_push *)malloc(sizeof(t_push) * 1);
	if (!((*comp)->next))
		ft_error_push(pile, begin, comp);
	while (n > 3 && j++)
	{
		i = -1;
		*comp = (*comp)->next;
		pile->tmp = ft_lst_n_dup_a(pile, begin, comp, n);
		ft_init_comp(comp, pile, begin, j);
		ft_free_lst(&pile->tmp);
		while (i < n)
		{
			if ((pile->a)->n <= (*comp)->median && ++(*comp)->size && --n)
				ft_pb(&pile->a, &pile->b, &begin->begin_a, &begin->begin_b);
			else if (i++)
				ft_ra(&pile->a, &begin->begin_a, 1);
		}
		while (i-- > 0)
			ft_rra(&pile->a, &begin->begin_a, 1);
	}
	free_null(comp);
}

void	ft_size4(t_pile *pile, t_begin *begin, t_push **comp)
{
	int	i;
	int	new_size;

	new_size = 0;
	pile->tmp = ft_lst_n_dup_b(pile, begin, comp, (*comp)->size);
	(*comp)->median = ft_median(pile, begin, comp, (*comp)->median);
	ft_free_lst(&pile->tmp);
	i = -1;
	while (++i < (*comp).size)
	{
		if ((pile->b)->n >= (*comp)->median)
		{
			ft_pa(&pile->a, &pile->b, &begin->begin_a, &begin->begin_b);
			new_size++;
			(*comp)->size--;
			i--;
		}
		else
			ft_rb(&pile->b, &begin->begin_b, 1);
	}
	if ((*comp)->nb_bloc != 0)
		while (i-- > 0)
			ft_rrb(&pile->b, &begin->begin_b, 1);
	ft_pushout_of_a(pile, begin, comp, new_size);
}

void	ft_algo(t_pile *pile, t_begin *st, t_push **comp, t_check *finish)
{
	t_push	*mem;

	while (!(ft_lst_comp(finish, pile->a)))
	{
		*comp = st->begin_comp;
		while (*comp && (*comp)->next)
		{
			mem = *comp;
			*comp = (*comp)->next;
		}
		if ((*comp)->size <= 3)
		{
			while ((*comp)->size-- > 0)
			{
				if (st->begin_b->next && st->begin_b->n < st->begin_b->next->n)
					ft_sb(&pile->b, &st->begin_b, 1);
				ft_pa(&pile->a, &pile->b, &st->begin_a, &st->begin_b);
			}
			if ((*comp)->nb_bloc != 0)
				mem->next = NULL;
			free(*comp);
		}
		else
			ft_size4(pile, st, comp);
		ft_sort3(&pile->a, &st->begin_a);
	}
}

t_check	*ft_quicksort(t_pile *pile, t_begin *st, t_push **comp,
	t_check *finish)
{
	int	i;
	int	j;

	j = 0;
	while (ft_list_size(&pile->a) > 3 && ++j)
	{
		i = ft_list_size(&pile->a);
		while (--i > -1)
		{
			if ((pile->a)->n < (*comp)->median && ++(*comp)->size)
				ft_pb(&pile->a, &pile->b, &st->begin_a, &st->begin_b);
			else
				ft_ra(&pile->a, &st->begin_a, 1);
		}
		if (ft_list_size(&pile->a) > 3)
		{
			*comp = (*comp)->next;
			pile->tmp = ft_lst_dup(pile->a, pile, st, comp);
			ft_init_comp(comp, pile, st, j);
			ft_free_lst(&pile->tmp);
		}
	}
	free_null(comp);
	st->begin_a = ft_3fast(&pile->a, st);
	ft_algo(pile, st, comp, finish);
	return (st->begin_a);
}

void	free_null(t_push **comp)
{
	free((*comp)->next);
	(*comp)->next = NULL;
}
