/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:49:53 by rmoujan           #+#    #+#             */
/*   Updated: 2022/02/17 19:08:24 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void	selectionsort(int *arr, int n)
{
	int		i;
	int		j;
	int		min_idx;

	i = 0;
	while (i < n - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < n)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
			j++;
		}
		swap(&arr[min_idx], &arr[i]);
		i++;
	}
}

void	tab_initial(int *mid, int *index_mid, t_stack *a)
{
	int	cnt;
	int	i;
	int	*tab;

	tab = (int *) malloc (sizeof(int) * (a->p + 1));
	cnt = a->p;
	i = 0;
	while (cnt >= 0)
	{
		tab[i] = a->array[cnt];
		cnt--;
		i++;
	}
	selectionsort(tab, a->p + 1);
	*index_mid = (a->p + 1) / 2;
	*mid = tab[(a->p + 1) / 2];
	free(tab);
}

void	side_a(t_stack *a, t_stack *b)
{
	int		mid;
	int		index_mid;
	t_stack	*chunks_b;

	chunks_b = (t_stack *) malloc (sizeof(t_stack));
	chunks_b->array = (int *) malloc (sizeof(int) * (500));
	chunks_b->p = -1;
	while (a->p != 1)
	{
		tab_initial(&mid, &index_mid, a);
		push(chunks_b, index_mid);
		half_sidea(a, b, mid, index_mid);
	}
	if (check_sorted(a) != 0)
		sa(a);
	side_b(a, b, chunks_b);
	free(chunks_b->array);
	free(chunks_b);
}

void	half_sidea(t_stack *a, t_stack *b, int mid, int index_mid)
{
	int	i;

	i = 0;
	while (i < index_mid)
	{
		if (a->array[a->p] < mid)
			pb(a, b);
		else
		{
			if (a->array[0] < mid)
			{
				rra(a);
				pb(a, b);
			}
			else
			{
				while (a->array[a->p] >= mid)
					ra(a);
				pb(a, b);
			}
		}
		i++;
	}
}
