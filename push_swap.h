/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 10:41:00 by mkarim            #+#    #+#             */
/*   Updated: 2022/04/20 16:35:08 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct s_stack_a
{
    int n;
    struct s_stack_a *p;
    struct s_stack_a *prev;
    int ind;
    int l;
    int prev_ind;
    int lis;
    int ind_pair;
    int trpl_r;
    int need; // how many move need an element in stack b to be in right poistion in stack a
} t_stack_a;

typedef struct s_variables
{
    int l;
    int i;
    int j;
    int cl;
}           t_variables;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1

int ft_check_arg(char *s);
void ft_putstr(char *s);
int ft_atoi(char *s);
void print(t_stack_a *arg);
int ft_check_dup(t_stack_a *arg);
int ft_check_sort(t_stack_a *arg);
char **ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
void    addBack(t_stack_a **s, int n);
void    addFront(t_stack_a **s, int n);
t_stack_a *newNode(int n);
void    sa(t_stack_a **s, int p);
void    sb(t_stack_a **b, int p);
void    ss(t_stack_a **a, t_stack_a **b);
void    pa(t_stack_a **a, t_stack_a **b);
void    pb(t_stack_a **a, t_stack_a **b);
void    ra(t_stack_a **a, int p);
void    rb(t_stack_a **b, int p);
void    rr(t_stack_a **a, t_stack_a **b);
void    rra(t_stack_a **a, int p);
void    rrb(t_stack_a **b, int p);
void    rrr(t_stack_a **a, t_stack_a **b);
void    ft_sort(t_stack_a **a, t_stack_a **b);
void    sort_three(t_stack_a **a);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int     ft_strlen(char *s);

#endif