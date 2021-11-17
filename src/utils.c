/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:33:54 by saich             #+#    #+#             */
/*   Updated: 2021/11/17 17:03:06 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	ft_error(t_check *p)
{
	write (1, "Error\n", 7);
	free(p->next);
	exit(0);
}

int	ft_list_size(t_check **p)
{
	t_check	*tmp;
	int		i;

	tmp = *p;
	if (tmp)
	{
		i = 0;
		while (tmp)
		{
			tmp = tmp->next;
			i++;
		}
		return (i);
	}
	else
		return (0);
}

t_check	*ft_lst_dup(t_check *temp, t_pile *pile, t_begin *begin, t_push **comp)
{
	t_check	*new;
	t_check	*start;

	new = (t_check *)malloc(sizeof(t_check *));
	if (!new)
		ft_error_push(pile, begin, *comp);
	start = new;
	while (temp)
	{
		new->n = temp->n;
		new->next = (t_check *)malloc(sizeof(t_check *));
		if (!new->next)
			ft_error_push(pile, begin, *comp);
		temp = temp->next;
		if (temp)
			new = new->next;
	}
	free(new->next);
	new->next = NULL;
	new = start;
	return (new);
}

int	ft_lst_comp(t_check *p, t_check *finish)
{
	while (p)
	{
		if (p->n != finish->n)
			return (0);
		p = p->next;
		finish = finish->next;
	}
	return (1);
}
