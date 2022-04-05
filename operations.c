/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:33:14 by mkarim            #+#    #+#             */
/*   Updated: 2022/04/05 10:53:20 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_stack_a **s)
{
    int size;
    t_stack_a *tmp;
    t_stack_a *sf;
    int ind;

    size = 0;
    tmp = *s;
    ind = 0;
    while (tmp)
    {
        size++;
        tmp = tmp->p;
    }
    printf("%d\n", size);
    if (size > 1)
    {
        tmp = *s;
        sf = tmp->p;
        while (tmp)
        {
            if (ind == 1)
            {
                *s = tmp;
            }
            ind++;
            tmp = tmp->p;
        }
    }
}