/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:36:43 by rmoujan           #+#    #+#             */
/*   Updated: 2022/02/18 22:36:43 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//25 lines
void	sort_five(t_stack *a, t_stack *b)
{
	int	min;
	int	k;
	int	index;
	int	i;

	k = a->p;
	i = a->p;
	while (i != 2)
	{
		min = a->array[a->p];
		index = -1;
		k = a->p;
		while (k >= 0)
		{
			if (min >= a->array[k])
			{
				index = k;
				min = a->array[k];
			}
			k--;
		}
		process_sortfive(a, b, index);
		i--;
	}
	final_call(a, b);
}

void	final_call(t_stack *a, t_stack *b)
{
	sort_three(a, b);
	while (b->p >= 0)
		pa(a, b);
}

//25 lines
void	process_sortfive(t_stack *a, t_stack *b, int index)
{
	if (index == 0)
	{
		rra(a);
		pb(a, b);
	}
	else if (index == 1)
		chunk2_sortfive(a, b);
	else if (index == 2 && a->p == 4)
		chunk1_sortfive(a, b);
	else if (index == 2 && a->p == 3)
	{
		sa(a);
		pb(a, b);
	}
	else if (index == 3 && a->p != 3)
	{
		sa(a);
		pb(a, b);
	}
	else
		pb(a, b);
}

void	chunk1_sortfive(t_stack *a, t_stack *b)
{
	rra(a);
	rra(a);
	rra(a);
	pb(a, b);
}

void	chunk2_sortfive(t_stack *a, t_stack *b)
{
	rra(a);
	rra(a);
	pb(a, b);
}