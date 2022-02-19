/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:38:09 by rmoujan           #+#    #+#             */
/*   Updated: 2022/02/19 16:47:44 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>

typedef struct s_stack	t_stack;
struct	s_stack{
	int	*array;
	int	p;
};

int		ft_atoi(const char *str);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	push(t_stack *s, int n);
int		check_sorted(t_stack *a);
void	pop(t_stack *a);
void	small_sort(t_stack *a, t_stack *b, int argc);
void	pa(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	final_call(t_stack *a, t_stack *b);
void	process_sortfive(t_stack *a, t_stack *b, int index);
void	chunk1_sortfive(t_stack *a, t_stack *b);
void	chunk2_sortfive(t_stack *a, t_stack *b);
void	sort_three(t_stack *a, t_stack *b);
void	side_a(t_stack *a, t_stack *b);
void	side_b(t_stack *a, t_stack *b, t_stack *chunks);
void	rb(t_stack *b);
void	rrb(t_stack *b);
void	process_a(t_stack *a, t_stack *b, t_stack *chunks_a, t_stack *chunks_b);
int		ft_strcmp(char *s1, char *s2);
void	chunks_sorthree(t_stack *a, t_stack *b);
void	chunks_swap(t_stack *a, t_stack *b, char *argv[], int j);
int		ft_check_integers(t_stack **a, t_stack **b);
void	half_sidea(t_stack *a, t_stack *b, int mid, int index_mid);
void	sideb1(t_stack *a, t_stack *b, t_stack *chunks_a, t_stack *chunks_b);
void	sideb3(t_stack *a, t_stack *b, t_stack *chunks_a, t_stack *chunks_b);
void	sideb4(t_stack *chunks_b, int len, int index_mid);
void	sideb5(int in, int mid, t_stack *a, t_stack *b);
void	sideb2(t_stack *a, t_stack *b, int len);
void	create_tab(int len, int *tab, t_stack *b);
void	hlf1_a(t_stack *a, t_stack *chunks_a);
void	hlf2_a(t_stack *a, t_stack *b, int *tab, int len);
void	side_b(t_stack *a, t_stack *b, t_stack *chunks_b);
void	selectionsort(int *arr, int n);
void	full_c(t_stack *c, char **argv, int argc, t_stack *b);
void	ft_checker(t_stack *c, t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);
char	**ft_split(char const *s1, char c);
char	*ft_strjoin(char *s1, char *s2);
void	rra1(t_stack *a);
void	ra1(t_stack *a);
void	rrb1(t_stack *b);
void	rb1(t_stack *b);
#endif