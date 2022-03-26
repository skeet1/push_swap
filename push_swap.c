/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 10:33:24 by mkarim            #+#    #+#             */
/*   Updated: 2022/03/26 12:11:24 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print(t_stack_a *arg)
{
    while (arg != NULL)
    {
        printf("%d\n", arg->n);
        arg = arg->p;
    }
}

int main(int argc, char **argv)
{
    int     i;
    t_stack_a *arg;
    
    i = 1;
    if (argc == 1)
        return (0);
    else
    {
        while (i < argc)
        {
            if (ft_check_arg(argv[i]) == 0)
            {
                ft_putstr("Error\n");
                return (0);
            }
            arg = malloc(sizeof(t_stack_a));
            if (!arg)
                return (NULL);
            arg->n = ft_atoi(argv[i]);
            arg->p = NULL;
            printf("%d\n" , arg->n);
            i++;
        }
    }
    ft_putstr("args good\n");
    print(p);
}