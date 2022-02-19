/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:40:20 by rmoujan           #+#    #+#             */
/*   Updated: 2022/02/19 17:57:58 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//swap a - swap the first 2 elements at the top of t_stack a
void	sa(t_stack *a)
{
	int	k;
	int	tmp;

	if (a->p > 0)
	{
		k = a->p;
		tmp = a->array[k];
		a->array[k] = a->array[k - 1];
		a->array[k - 1] = tmp;
		write(1, "sa\n", 3);
	}
}

//rb : The first element becomes the last one :
void	rb(t_stack *b)
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
		write(1, "rb\n", 3);
	}
}

//rrb : The last element becomes the first one 13 lines :
void	rrb(t_stack *b)
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

void	chunks_swap(t_stack *a, t_stack *b, char *argv[], int j)
{
	unsigned long	nbr;
	int				f;

	while (j > 1)
	{
		f = 0;
		if (ft_strcmp(argv[j - 1], "42") == 0)
			f++;
		if (ft_atoi(argv[j - 1]) == '*' && f == 0)
			ft_check_integers(&a, &b);
		nbr = ft_atoi(argv[j - 1]);
		push(a, nbr);
		j--;
	}
}
