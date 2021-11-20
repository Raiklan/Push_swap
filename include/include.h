/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:26:31 by saich             #+#    #+#             */
/*   Updated: 2021/11/20 02:57:39 by saich            ###   ########.fr       */
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
void	ft_sa(t_check **a, t_check **start_a, int n);
void	ft_sb(t_check **b, t_check **start_b, int n);
void	ft_ss(t_check **a, t_check **b, t_check **start_a, t_check **start_b);
void	ft_pa(t_check **a, t_check **b, t_check **start_a, t_check **start_b);
void	ft_pb(t_check **a, t_check **b, t_check **start_a, t_check **start_b);
void	ft_ra(t_check **a, t_check **start_a, int n);
void	ft_rb(t_check **b, t_check **start_b, int n);
void	ft_rr(t_check **a, t_check **b, t_check **start_a, t_check **start_b);
void	ft_rra(t_check **a, t_check **start_a, int n);
void	ft_rrb(t_check **b, t_check **start_b, int n);
t_check	*ft_3fast(t_check **a, t_begin *b);
t_check	*ft_lst_n_dup_a(t_pile *pile, t_begin *begin, t_push **comp, int n);
t_check	*ft_lst_n_dup_b(t_pile *pile, t_begin *begin, t_push **comp, int n);
void	ft_case1(t_check **a, t_check **start_a);
void	ft_case2(t_check **a, t_check **start_a);
void	ft_case3(t_check **a, t_check **start_a);
void	ft_case4(t_check **a, t_check **start_a);
t_check	*ft_quicksort(t_pile *pile, t_begin *st, t_push **comp,
			t_check *finish);

#endif
