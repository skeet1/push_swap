/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 10:41:00 by mkarim            #+#    #+#             */
/*   Updated: 2022/03/27 13:33:05 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack_a {
    int n;
    struct s_stack_a *p;
}               t_stack_a;

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int     ft_check_arg(char *s);
void    ft_putstr(char *s);
int     ft_atoi(char *s);
void    print(t_stack_a *head);
int ft_check_dup(t_stack_a *arg);
int ft_check_sort(t_stack_a *arg);

#endif