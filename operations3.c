/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:41:18 by rmoujan           #+#    #+#             */
/*   Updated: 2022/02/19 16:48:33 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sb(t_stack *b)
{
	int	k;
	int	tmp;

	k = b->p;
	tmp = b->array[k];
	b->array[k] = b->array[k - 1];
	b->array[k - 1] = tmp;
	write(1, "sb\n", 3);
}

//push a - take the first element at the top of b and put it at the top of a.
void	pa(t_stack *a, t_stack *b)
{
	int	k;

	k = b->p;
	push(a, b->array[k]);
	pop(b);
	write(1, "pa\n", 3);
}

//push b - take the first element at the top of a and put it at the top of b
void	pb(t_stack *a, t_stack *b)
{
	int	i;

	i = a->p;
	push(b, a->array[i]);
	pop(a);
	write(1, "pb\n", 3);
}

//The last element becomes the first one 13 lines :
void	rra(t_stack *a)
{
	int	k;
	int	tmp1;

	k = 0;
	tmp1 = a->array[k];
	while (k < a->p)
	{
		a->array[k] = a->array[k + 1];
		k++;
	}
	a->array[k] = tmp1;
	write(1, "rra\n", 4);
}

//ra : The first element becomes the last one
void	ra(t_stack *a)
{
	int	k;
	int	tmp1;

	k = a->p;
	tmp1 = a->array[k];
	while (k > 0)
	{
		a->array[k] = a->array[k - 1];
		k--;
	}
	a->array[k] = tmp1;
	write(1, "ra\n", 3);
}
