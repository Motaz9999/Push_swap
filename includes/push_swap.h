/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 22:05:49 by motaz             #+#    #+#             */
/*   Updated: 2025/10/18 20:36:44 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define FALSEE 0
# define TRUEE 1

# include "libft.h"
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

// for deal with the list (stack)
t_node				*create_node(int val);
int					get_stack_size(t_node *stack);
void				push(t_node **stack, t_node *new_node);
void				free_stack(t_node **stack);
void				add_back(t_node **stack, t_node *new_node);
int					is_empty(t_node *stack);
t_node				*pop(t_node **stack);
// void	print_stack(t_node *stack, char name);

// for error handle and vald
void				error_happend(t_node **stack);
long				ft_atol(const char *str);
int					check_for_dup(char **str, int argc);
int					check_for_type(char **argv, int argc);
t_node				*valdtion_and_dup(int argc, char **argv);
int					check_for_str(char *str);

// stack a
void				pa(t_node **stack_a, t_node **stack_b);
void				sa(t_node **stack_a);
void				ra(t_node **stack_a);
void				rra(t_node **stack_a);

// stack b
void				pb(t_node **stack_b, t_node **stack_a);
void				sb(t_node **stack_b);
void				rb(t_node **stack_b);
void				rrb(t_node **stack_b);

// both
void				rr(t_node **stack_a, t_node **stack_b);
void				rrr(t_node **stack_a, t_node **stack_b);

// sorting
void				sort_stack(t_node **stack_a, t_node **stack_b);
void				radixsort(t_node **stack_a, t_node **stack_b, int size);
void				initialization(t_node **stack);

// main
int					main(int argc, char *argv[]);

#endif