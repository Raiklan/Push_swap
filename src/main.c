/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:21:39 by saich             #+#    #+#             */
/*   Updated: 2021/11/19 03:08:05 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	ft_recup(int ac, char **av)
{
	t_check	*p;
	t_check	*begin;
	int		i;

	i = 1;
	p = (t_check *)malloc(sizeof(t_check) * 1);
	if (!p)
		ft_error(p);
	begin = p;
	while (--ac)
	{
		p->next = (t_check *)malloc(sizeof(t_check) * 1);
		if (!p)
			ft_error(p);
		p->n = (int)ft_atol(av[i++]);
		if (ac > 1)
			p = p->next;
	}
	free(p->next);
	p->next = NULL;
	p = begin;
	return (p);
}

static int	ft_checkdup(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = 0;
		if (ft_strlen(av[i]) > 11 || ft_atol(av[i]) > __INT32_MAX__
			|| ft_atol (av[i]) < __INT32_MAX__ * -1)
			return (-1);
		while (++j != i)
			if (ft_atol(av[i]) == ft_atol(av[j]))
				return (-1);
	}
	return (0);
}

int	ft_checkav(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (j == 0 && (av[i][j] == '-' || av[i][j] == '+')
				&& ft_isalnum(av[i][j + 1] == 1))
				return (-1);
			else if (av[i][j] < '0' || av[i][j] > '9')
				return (-1);
		}
	}
	if (ft_checkdup(av) == -1)
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	t_pile	pile;

	pile.a = NULL;
	pile.b = NULL;
	if (ac < 2)
		return (write(1, "Usage: ./push_swap <listofnumbers>\n", 36));
	if (ft_checkav(av) == -1 && write(1, "Error\n", 7))
		return (0);
	pile.a = ft_recup(ac, av);
	if (ft_lstsize(&pile.a) > 1)
		pile.a = ft_choose(&pile);
	ft_free_lst(&pile.a);
	return (0);
}
