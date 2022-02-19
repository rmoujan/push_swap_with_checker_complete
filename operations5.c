/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:38:16 by rmoujan           #+#    #+#             */
/*   Updated: 2022/02/19 17:58:26 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//The last element becomes the first one 13 lines :
void	rra1(t_stack *a)
{
	int	k;
	int	tmp1;

	if (a->p > 0)
	{
		k = 0;
		tmp1 = a->array[k];
		while (k < a->p)
		{
			a->array[k] = a->array[k + 1];
			k++;
		}
		a->array[k] = tmp1;
	}
}

//ra : The first element becomes the last one
void	ra1(t_stack *a)
{
	int	k;
	int	tmp1;

	if (a->p > 0)
	{
		k = a->p;
		tmp1 = a->array[k];
		while (k > 0)
		{
			a->array[k] = a->array[k - 1];
			k--;
		}
		a->array[k] = tmp1;
	}
}

//rb : The first element becomes the last one :
void	rb1(t_stack *b)
{
	int	k;
	int	tmp1;

	if (b->p > 0)
	{
		k = b->p;
		tmp1 = b->array[k];
		while (k > 0)
		{
			b->array[k] = b->array[k - 1];
			k--;
		}
		b->array[k] = tmp1;
	}
}

//rrb : The last element becomes the first one 13 lines :
void	rrb1(t_stack *b)
{
	int	k;
	int	tmp1;

	if (b->p > 0)
	{
		k = 0;
		tmp1 = b->array[k];
		while (k < b->p)
		{
			b->array[k] = b->array[k + 1];
			k++;
		}
		b->array[k] = tmp1;
		write(1, "rrb\n", 4);
	}
}
