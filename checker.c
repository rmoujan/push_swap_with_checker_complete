/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:45:43 by rmoujan           #+#    #+#             */
/*   Updated: 2022/02/18 22:45:43 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// add an item into the t_stack :
void	push(t_stack *s, int n)
{
	s->array[++s->p] = n;
}

//check if the t_stack a has duplicated numbers
int	ft_check_doublons(t_stack **a, t_stack **b, int argc)
{
	t_stack	*p;
	int		i;
	int		j;

	i = 0;
	p = *a;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (p->array[i] == p->array[j])
			{
				free(*a);
				free(*b);
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_parameters(int argc)
{
	if (argc <= 2)
		exit(EXIT_FAILURE);
	return (1);
}

int	ft_check_integers(t_stack **a, t_stack **b)
{
	free(*a);
	free(*b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*c;
	int		j;

	ft_check_parameters(argc);
	j = argc;
	a = (t_stack *) malloc (sizeof(t_stack));
	a->array = (int *) malloc (sizeof(int) * (argc - 1));
	a->p = -1;
	b = (t_stack *) malloc (sizeof(t_stack));
	b->array = (int *) malloc (sizeof(int) * (argc - 1));
	b->p = -1;
	chunks_swap(a, b, argv, j);
	j = argc;
	ft_check_doublons(&a, &b, j);
	if (check_sorted(a) == 0)
		exit(EXIT_FAILURE);
	full_c(c, argv, argc, b);
	j = argc;
	if (j <= 6)
		small_sort(a, b, j);
	else
		side_a(a, b);
	ft_checker(c, b); 
}