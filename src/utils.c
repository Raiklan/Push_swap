/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:33:54 by saich             #+#    #+#             */
/*   Updated: 2021/11/16 18:38:52 by saich            ###   ########.fr       */
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
