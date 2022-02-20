/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoujan < rmoujan@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:38:09 by rmoujan           #+#    #+#             */
/*   Updated: 2022/02/20 22:23:32 by rmoujan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# define BUFFER_SIZE 10

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
int		ft_check_doublons(t_stack **a, t_stack **b, int argc);
void	pa(t_stack *a, t_stack *b);
void	rra(t_stack *a);
int		ft_strcmp(char *s1, char *s2);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rrb(t_stack *b);
void	chunks_swap(t_stack *a, t_stack *b, char *argv[], int j);
int		ft_check_integers(t_stack **a, t_stack **b);
void	ft_checker(t_stack *c, t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);
char	*get_next_line(int fd);
char	*ft_strjoin(char **s1, char **s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
int		ft_check(char *str);
char	*ft_process(char **rest);
void	*ft_free(char **p1);
char	*ft_work(char **buffer, char **rest, int fd);
#endif