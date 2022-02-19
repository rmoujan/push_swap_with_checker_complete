/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:41:57 by rmoujan           #+#    #+#             */
/*   Updated: 2022/02/19 16:30:36 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

void rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}

void rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}