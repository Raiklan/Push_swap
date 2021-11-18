/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:26:31 by saich             #+#    #+#             */
/*   Updated: 2021/11/18 01:27:15 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include <libft.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_check
{
	int				n;
	struct s_check	*next;
}					t_check;

typedef struct s_pile
{
	t_check		*a;
	t_check		*b;
	t_check		*tmp;
}				t_pile;

typedef struct s_push
{
	int				median;
	int				nb_bloc;
	int				size;
	struct s_push	*next;
}					t_push;

typedef struct s_begin
{
	t_check		*begin_a;
	t_check		*begin_b;
	t_push		*begin_comp;
}				t_begin;

int		ft_list_size(t_check **p);
t_check	*ft_lst_dup(t_check *temp, t_pile *pile, t_begin *begin, t_push **comp);
int		ft_lst_comp(t_check *p, t_check *finish);
void	ft_error(t_check *p);
void	ft_init_begin(t_begin *begin, t_check *a, t_check *b, t_push *comp);
void	ft_init_comp(t_push **comp, t_pile *pile, t_begin *begin, int i);
void	ft_error_push(t_pile *pile, t_begin *begin, t_push *comp);
void	ft_mergesort(t_check **head);
int		ft_recup(int ac, char **av);
int		ft_checkav(char **av);
void	ft_free_lst(t_check **p);
void	ft_free_lst_push(t_push *p);
int		ft_is_sorted(t_check *a);
int		ft_median(t_pile *pile, t_begin *begin, t_push **comp, int n);
t_check	*ft_choose(t_pile *pile);

#endif
