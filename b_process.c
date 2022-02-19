/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_process.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:43:18 by rmoujan           #+#    #+#             */
/*   Updated: 2022/02/18 22:43:18 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	side_b(t_stack *a, t_stack *b, t_stack *chunks_b)
{
	t_stack	*chunks_a;

	chunks_a = (t_stack *) malloc (sizeof(t_stack));
	chunks_a->array = (int *) malloc (sizeof(int) * (500));
	chunks_a->p = -1;
	sideb1(a, b, chunks_a, chunks_b);
	free(chunks_a->array);
	free(chunks_a);
}

void	sideb1(t_stack *a, t_stack *b, t_stack *chunks_a, t_stack *chunks_b)
{
	int	len;
	int	*tab;

	while (b->p != -1)
	{
		len = chunks_b->array[chunks_b->p];
		tab = (int *) malloc (sizeof(int) * (len));
		sideb2(a, b, len);
		if (len >= 3)
		{
			create_tab(len, tab, b);
			selectionsort(tab, len);
			sideb5((len - (len / 2)), tab[len / 2], a, b);
			if (len % 2 == 0)
				push(chunks_a, (len / 2) - 1);
			else
				push(chunks_a, (len / 2));
		}
		free(tab);
		sideb4(chunks_b, len, (len / 2));
		sideb3(a, b, chunks_a, chunks_b);
	}
}

void	sideb2(t_stack *a, t_stack *b, int len)
{
	if (len == 2)
	{
		if (b->array[b->p] < b->array[b->p - 1])
		{
			sb(b);
			pa(a, b);
			pa(a, b);
		}
		else
		{
			pa(a, b);
			pa(a, b);
		}
	}
	else if (len == 1)
		pa(a, b);
}

void	sideb3(t_stack *a, t_stack *b, t_stack *chunks_a, t_stack *chunks_b)
{
	if (chunks_a->p == -1)
	{
		if (check_sorted(a) != 0)
		{
			if (a->array[a->p] > a->array[a->p - 1])
				sa(a);
		}
	}
	else if (chunks_a->p != -1)
	{
		if (chunks_a->array[chunks_a->p] <= 2)
		{
			if (check_sorted(a) != 0)
			{
				if (a->array[a->p] > a->array[a->p - 1])
					sa(a);
			}
			pop(chunks_a);
		}
		else
		{
			process_a(a, b, chunks_a, chunks_b);
		}
	}	
}

void	sideb4(t_stack *chunks_b, int len, int index_mid)
{
	pop(chunks_b);
	if (len > 2 && len % 2 == 0)
		push(chunks_b, len - index_mid + 1);
	else if (len > 2 && len % 2 != 0)
		push(chunks_b, len - index_mid);
}