/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:41:57 by rmoujan           #+#    #+#             */
/*   Updated: 2022/02/19 17:57:05 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa1(t_stack *a)
{
	int	k;
	int	tmp;

	if (a->p > 0)
	{
		k = a->p;
		tmp = a->array[k];
		a->array[k] = a->array[k - 1];
		a->array[k - 1] = tmp;
	}
}

void	sb1(t_stack *b)
{
	int	k;
	int	tmp;

	if (b->p > 0)
	{
		k = b->p;
		tmp = b->array[k];
		b->array[k] = b->array[k - 1];
		b->array[k - 1] = tmp;
	}
}

void	ss(t_stack *a, t_stack *b)
{
	sa1(a);
	sb1(b);
	write(1, "ss\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ra1(a);
	rb1(b);
	write(1, "rr\n", 3);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra1(a);
	rrb1(b);
	write(1, "rrr\n", 4);
}
