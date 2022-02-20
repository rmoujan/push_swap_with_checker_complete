/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_process.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:13:19 by rmoujan           #+#    #+#             */
/*   Updated: 2022/02/17 19:01:21 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_tab(int len, int *tab, t_stack *b)
{
	int	i;
	int	j;

	i = 0;
	j = b->p;
	while (i < len)
	{
		tab[i] = b->array[j];
		j--;
		i++;
	}
}

void	process_a(t_stack *a, t_stack *b, t_stack *chunks_a, t_stack *chunks_b)
{
	int	*tab;
	int	len;

	len = chunks_a->array[0];
	while (chunks_a->array[0] != 2)
	{
		len = chunks_a->array[0];
		tab = (int *) malloc (sizeof(int) * (len));
		create_tab(len, tab, a);
		selectionsort(tab, len);
		hlf2_a(a, b, tab, len);
		push(chunks_b, (len / 2));
		pop(chunks_a);
		push(chunks_a, len - (len / 2));
		free(tab);
	}
	hlf1_a(a, chunks_a);
}

void	hlf1_a(t_stack *a, t_stack *chunks_a)
{
	if (check_sorted(a) != 0)
	{
		if (a->array[a->p] > a->array[a->p - 1])
			sa(a);
		pop(chunks_a);
	}
	pop(chunks_a);
}

void	hlf2_a(t_stack *a, t_stack *b, int *tab, int len)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (i < (len / 2))
	{
		if (a->array[a->p] < (tab[len / 2]))
		{
			pb(a, b);
			i++;
		}
		else
		{
			ra(a);
			r++;
		}
	}
	i = 0;
	while (i < r)
	{
		rra(a);
		i++;
	}
}

void	sideb5(int in, int mid, t_stack *a, t_stack *b)
{
	int	i;
	int	r;

	i = 1;
	r = 0;
	while (i < in)
	{
		if (b->array[b->p] > mid)
		{
			pa(a, b);
			i++;
		}
		else
		{
			rb(b);
			r++;
		}	
	}
	i = 0;
	while (i < r)
	{
		rrb(b);
		i++;
	}	
}
