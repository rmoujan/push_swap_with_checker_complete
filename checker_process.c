/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:02:55 by rmoujan           #+#    #+#             */
/*   Updated: 2022/02/19 17:33:18 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_cmp(char *s1, char *s2)
{
	int	compteur;
	int	resultat;

	compteur = 0;
	resultat = 0;
	while (s1[compteur] != '\0' || s2[compteur] != '\0')
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

void	half_process(t_stack *c, t_stack *b, char *ptr)
{
	if (ft_cmp(ptr, "sa\0") == 0)
		sa(c);
	else if (ft_cmp(ptr, "sb\0") == 0)
		sb(c);
	else if (ft_cmp(ptr, "pa\0") == 0)
		pa(c, b);
	else if (ft_cmp(ptr, "pb\0") == 0)
		pb(c, b);
	else if (ft_cmp(ptr, "ra\0") == 0)
		ra(c);
	else if (ft_cmp(ptr, "rb\0") == 0)
		rb(b);
	else if (ft_cmp(ptr, "rra\0") == 0)
		rra(c);
	else if (ft_cmp(ptr, "rrb\0") == 0)
		rrb(b);
	else if (ft_cmp(ptr, "ss\0") == 0)
		ss(c, b);
	else if (ft_cmp(ptr, "rr\0") == 0)
		rr(c, b);
	else if (ft_cmp(ptr, "rrr\0") == 0)
		rrr(c, b);
	else
		ft_error();
}

void	process(t_stack *c, t_stack *b, char *str2)
{
	char	**ptr;
	int		i;

	ptr = ft_split(str2, '\n');
	i = 0;
	while (ptr[i] != NULL)
	{
		half_process(c, b, ptr[i]);
		i++;
	}
}

void	ft_checker(t_stack *c, t_stack *b)
{
	int		r;
	char	*str1;
	char	*str2;
	int		i;

	str2 = malloc(1);
	str2[0] = '\0';
	str1 = malloc(5);
	r = read(0, str1, 5);
	r = 0;
	i = 0;
	while (str1[i] != '\n')
	{
		if (str1[2] == '\n')
			str1[3] = '\0';
		else if (str1[3] == '\n')
			str1[4] = '\0';
		str2 = ft_strjoin(str2, str1);
		free(str1);
		str1 = malloc(5);
		r = read(0, str1, 5);
	}
	free(str1);
	process(c, b, str2);
}
