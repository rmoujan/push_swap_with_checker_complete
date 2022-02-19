/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan <rmoujan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:02:55 by rmoujan           #+#    #+#             */
/*   Updated: 2022/02/18 23:02:55 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void full_c(t_stack *c, char **argv, int argc, t_stack *b)
{
    c = (t_stack *)malloc(sizeof(t_stack));
    c->array = (int *)malloc(sizeof(int) * (argc - 1));
    c->p = -1;
    chunks_swap(c, b, argv, argc);
}


char	*ft_copy(char const *s1, char const *s2, char *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		p[i] = s2[j];
		j++;
		i++;
	}
	p[i] = '\0';
	return (p);
}
static int	c_words(char const *s1, char c)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (s1[i] == c)
		i++;
	while (s1[i] != '\0')
	{
		if (s1[i] == c && s1[i + 1] != c)
			total++;
		i++;
	}
	if (i != 0)
	{
		if (s1[i - 1] != c)
			total++;
	}
	return (total);
}

static char	*ft_cpy(char const *s1, int k, int j)
{
	int		size;
	int		i;
	char	*p;

	size = (j - k) + 1;
	i = 0;
	p = malloc (size * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (k < j)
	{
		p[i] = s1[k];
		i++;
		k++;
	}
	p[i] = '\0';
	return (p);
}

static void	ft_free(char **tab, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(tab[j]);
		j++;
	}
	free(tab);
}

static char	**f_str(char const *s1, char c, char **tab)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = -1;
	while (s1[++k] != '\0')
	{
		if (s1[k] != c)
		{
			j = k;
			while (s1[j] != c && s1[j] != '\0')
				j++;
			tab[i] = ft_cpy(s1, k, j);
			if (!(tab[i]))
			{
				ft_free(tab, i);
				return (NULL);
			}
			i++;
			k = j - 1;
		}
	}
	tab[i] = NULL;
	return (tab);
}

char	**ft_split(char const *s1, char c)
{
	char	**tab;

	if (!s1)
		return (NULL);
	tab = malloc ((c_words(s1, c) + 1) * sizeof(char *));
	if (c_words(s1, c) == 0)
	{
		tab[0] = NULL;
		return (tab);
	}
	if (tab == NULL)
		return (NULL);
	return (f_str(s1, c, tab));
}







size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	p = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	p = ft_copy(s1, s2, p);
	//ft_free(s1);
	return (p);
}




static int	ft_cmp(char *s1, char *s2)
{
	int	compteur;
	int	resultat;

	compteur = 0;
	resultat = 0;
	while (s1[compteur] != '\n' || s2[compteur] != '\0' )
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

void    ft_checker(t_stack *c, t_stack *b)
{
    int r;
    char *str1;
    char *str2;
    char **ptr;
    
    str2 = malloc(1);
    str2[0] = '\0';
    str1 = malloc(5);
    r = read(0,str1, 5);
    r = 0;
    int i = 0;
    while (str1[i] != '\n')
    {
        if (str1[2] == '\n')
            str1[3]= '\0';
        else if (str1[3] == '\n')
            str1[4]= '\0';
        str2 = ft_strjoin(str2,str1);
        free(str1);
        str1 = malloc(5);
        r = read(0,str1, 5);
    }
        
        
    
        ptr = ft_split(str2, '\n');
     i = 0;
        while (ptr[i] != NULL)
        {
        if (ft_cmp(ptr[i], "sa") == 0)
            sa(c);
        else if (ft_cmp(ptr[i], "sb") == 0)
            sb(c);
        else if (ft_cmp(ptr[i], "pa") == 0)
            pa(c, b);
        else if (ft_cmp(ptr[i], "pb") == 0)
            pb(c, b);
        else if (ft_cmp(ptr[i], "ra") == 0)
            ra(c);
        else if (ft_cmp(ptr[i], "rb") == 0)
            rb(b);
        else if (ft_cmp(ptr[i], "rra") == 0)
            rra(c);
        else if (ft_cmp(ptr[i], "rrb") == 0)
            rrb(b);
         //   printf("%s\n", ptr[i]);
            i++;
        }
        printf("test");
    if (check_sorted(c) == 0 && b->p == -1)
    {
        write(1, "ok\n", 3);
    }
    else
    {
        write(1, "ko\n", 3);
    }
}


