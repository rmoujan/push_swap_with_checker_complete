/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:35:25 by rmoujan           #+#    #+#             */
/*   Updated: 2022/02/19 16:49:03 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_sign(const char *str, int *sign)
{
	int	j;

	j = 0;
	if (str[j] == '+' || str[j] == '-')
	{
		if (str[j] == '-')
			*sign = *sign * (-1);
		j++;
	}
	return (j);
}

int	ft_atoi(const char *str)
{
	unsigned long	nb;
	int				i;
	int				sign;

	nb = 0;
	sign = 1;
	i = 0;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1] == '\0')
		return ('*');
	i = ft_sign(str, &sign);
	while (48 <= str[i] && str[i] <= 57)
	{
		nb = (nb * 10) + str[i] - '0';
		if (nb > 2147483647 && sign == 1)
			return ('*');
		else if (nb > 2147483648 && sign == -1)
			return ('*');
		i++;
	}
	if (str[i] != '\0' && (str[i] < 48 || str[i] > 57))
		return ('*');
	return (sign * nb);
}

// compare two strings :
int	ft_strcmp(char *s1, char *s2)
{
	int	compteur;
	int	resultat;

	compteur = 0;
	resultat = 0;
	while (s1[compteur] != '\0' || s2[compteur] != '\0' )
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

//delete the current elm at the top of a
void	pop(t_stack *a)
{
	if (a->p != -1)
	{
		a->p--;
	}
}

//check if the t_stack A is already sorted :
int	check_sorted(t_stack *a)
{
	int	k;
	int	i;
	int	flag;

	flag = 0;
	k = a->p;
	while (k > 0)
	{
		i = k - 1;
		while (i >= 0)
		{
			if (a->array[k] > a->array[i])
				flag++;
			i--;
		}
		k--;
	}
	return (flag);
}
