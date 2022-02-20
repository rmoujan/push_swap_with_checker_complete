/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:02:55 by rmoujan           #+#    #+#             */
/*   Updated: 2022/02/20 22:26:23 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_cmp(char *s1, char *s2)
{
	int	compteur;
	int	resultat;

	compteur = 0;
	resultat = 0;
	while (s1[compteur] != '\n' || s2[compteur] != '\n')
	{
		resultat = s1[compteur] - s2[compteur];
		if (resultat > 0)
		{
			return (resultat);
		}
		else if (resultat < 0)
		{
			return (resultat);
		}
		compteur++;
	}
	return (resultat);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	process(t_stack *c, t_stack *b, char *ptr)
{
	if (ft_cmp(ptr, "sa\n") == 0)
		sa(c);
	else if (ft_cmp(ptr, "sb\n") == 0)
		sb(c);
	else if (ft_cmp(ptr, "pa\n") == 0)
		pa(c, b);
	else if (ft_cmp(ptr, "pb\n") == 0)
		pb(c, b);
	else if (ft_cmp(ptr, "ra\n") == 0)
		ra(c);
	else if (ft_cmp(ptr, "rb\n") == 0)
		rb(b);
	else if (ft_cmp(ptr, "rra\n") == 0)
		rra(c);
	else if (ft_cmp(ptr, "rrb\n") == 0)
		rrb(b);
	else if (ft_cmp(ptr, "ss\n") == 0)
		ss(c, b);
	else if (ft_cmp(ptr, "rr\n") == 0)
		rr(c, b);
	else if (ft_cmp(ptr, "rrr\n") == 0)
		rrr(c, b);
	else
		ft_error();
}

void	ft_checker(t_stack *c, t_stack *b)
{
	char	*str1;

	str1 = get_next_line(0);
	while (str1)
	{
		process(c, b, str1);
		free(str1);
		str1 = NULL;
		str1 = get_next_line(0);
	}
}
