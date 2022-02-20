/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:50:45 by rmoujan           #+#    #+#             */
/*   Updated: 2022/02/14 21:56:03 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunks_sorthree(t_stack *a, t_stack *b)
{
	pb(a, b);
	sa(a);
	pa(a, b);
}

//hard-coded sort 3 with 24 lines:
void	sort_three(t_stack *a, t_stack *b)
{
	if (a->array[a->p] > a->array[a->p - 1]
		&& a->array[a->p - 1] > a->array[a->p - 2])
	{
		ra(a);
		sa(a);
	}
	else if (a->array[a->p] < a->array[a->p - 1]
		&& a->array[a->p] < a->array[a->p - 2])
	{
		if (a->array[a->p - 1] > a->array[a->p - 2])
			chunks_sorthree(a, b);
	}
	else if (a->array[a->p] > a->array[a->p - 1]
		&& a->array[a->p] < a->array[a->p - 2])
		sa(a);
	else if (a->array[a->p] > a->array[a->p - 1]
		&& a->array[a->p] > a->array[a->p - 2])
	{
		ra(a);
		if (a->array[a->p] > a->array[a->p - 1])
			sa(a);
	}
	else if (a->array[a->p] < a->array[a->p - 1]
		&& a->array[a->p] > a->array[a->p - 2])
		rra(a);
}

void	small_sort(t_stack *a, t_stack *b, int argc)
{
	if (argc == 4)
		sort_three(a, b);
	else if (argc == 3)
		sa(a);
	else
		sort_five(a, b);
}
