/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:26:31 by saich             #+#    #+#             */
/*   Updated: 2021/11/16 16:28:12 by saich            ###   ########.fr       */
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
	t_push		*begin_c;
}				t_begin;

#endif
