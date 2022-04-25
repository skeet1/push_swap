/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 10:41:00 by mkarim            #+#    #+#             */
/*   Updated: 2022/04/24 22:33:34 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_a
{
	int					n;
	struct s_stack_a	*p;
	struct s_stack_a	*prev;
	int					ind;
	int					l;
	int					prev_ind;
	int					lis;
	int					ind_pair;
	int					trpl_r;
	int					need;
}				t_stack_a;

typedef struct s_variables
{
	int		l;
	int		i;
	int		j;
	int		cl;
}				t_variables;

int			ft_check_arg(char *s);
void		ft_putstr(char *s);
long long	ft_atoi(char *s);
int			ft_check_dup(t_stack_a *arg);
int			ft_check_int(long long n);
int			ft_check_sort(t_stack_a *arg);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char *s1, char *s2);
void		ft_add_back(t_stack_a **s, int n);
void		ft_add_front(t_stack_a **s, int n);
t_stack_a	*ft_new_node(int n);
void		ft_sa(t_stack_a **s, int p);
void		ft_sb(t_stack_a **b, int p);
void		ft_ss(t_stack_a **a, t_stack_a **b);
void		ft_pa(t_stack_a **a, t_stack_a **b);
void		ft_pb(t_stack_a **a, t_stack_a **b);
void		ft_ra(t_stack_a **a, int p);
void		ft_rb(t_stack_a **b, int p);
void		ft_rr(t_stack_a **a, t_stack_a **b);
void		ft_rra(t_stack_a **a, int p);
void		ft_rrb(t_stack_a **b, int p);
void		ft_rrr(t_stack_a **a, t_stack_a **b);
void		ft_sort(t_stack_a **a, t_stack_a **b);
void		ft_sort_three(t_stack_a **a);
int			ft_ind_of_max(t_stack_a **a);
int			ft_ind_of_min(t_stack_a **a);
void		ft_sort_four(t_stack_a **a, t_stack_a **b);
void		ft_sort_five(t_stack_a **a, t_stack_a **b);
void		ft_sort1(t_stack_a **a, t_stack_a **b);
int			ft_lstsize(t_stack_a *a);
void		ft_ind_stack(t_stack_a **a);
int			ft_find_lis(t_stack_a **a);
void		ft_mark_lis(t_stack_a **a, int lis);
void		ft_leave_lis_in_a(t_stack_a **a, t_stack_a **b, int size);
int			ft_ind_pair(t_stack_a **a, int n);
int			ft_max(int a, int b);
void		ft_num_of_move_need(t_stack_a **a, t_stack_a **b);
int			ft_ind_pmm(t_stack_a **b, t_stack_a **a);
int			ft_ind_min_move(t_stack_a **b);
int			ft_min_move(t_stack_a **b);
void		ft_final_sort(t_stack_a **a);
int			ft_gbi(t_stack_a **s, int ind_min_move);
void		ft_move_with_rrr(t_stack_a **a, t_stack_a **b, int ind_min_move);
void		ft_move_with_rr(t_stack_a **a, t_stack_a **b, int ind_min_move);
int			if_rrr(t_stack_a **a, t_stack_a **b,
				int ind_min_move, int ind_pair);
int			if_rr(t_stack_a **a, t_stack_a **b, int ind_min_move, int ind_pair);
int			if_rra(t_stack_a **a, int ind);
void		ft_move_to_a(t_stack_a **a, t_stack_a **b,
				int ind_min_move, int ind_p_min_move);
char		*ft_get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(char *s);
void		ft_let(int *a, int fa, int *b, int fb);
int			ft_min_in_stack(t_stack_a **a);
int			ft_max_in_stack(t_stack_a **a);
int			ft_miiin(t_stack_a **a, int ind);
int			ft_maaax(t_stack_a **a, int ind);

#endif
