/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortstack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 21:20:25 by motaz             #+#    #+#             */
/*   Updated: 2025/10/18 20:32:19 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// ok i want to sort less than 6 nums soo i want to take
//
// i want to sort from the less to biggest

#include "push_swap.h"

static int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > (stack->next)->value)
			return (FALSEE);
		stack = stack->next;
	}
	return (TRUEE);
}

static t_node	*find_small(t_node *stack_a)
{
	t_node	*small;
	t_node	*temp;

	small = stack_a;
	temp = stack_a->next;
	while (temp != NULL)
	{
		if (temp->value < small->value)
		{
			small = temp;
		}
		temp = temp->next;
	}
	return (small);
}

static void	sort_2_3(t_node **stack_a, int size)
{
	if (size == 2)
	{
		sa(stack_a);
		return ;
	}
	if (((*stack_a)->value > (((*stack_a)->next)->next)->value)
		&& (((*stack_a)->next)->value < (*stack_a)->value))
		ra(stack_a);
	else if (((*stack_a)->value < ((*stack_a)->next)->value)
		&& (((*stack_a)->next)->value) > (((*stack_a)->next)->next)->value)
		rra(stack_a);
	if (!is_sorted(*stack_a))
		sa(stack_a);
}

// put the smallest in b then sort
// now after finding the smallest put it in stack_b but first 
//i want to be head soo i can push it to b//	pb(stack_b,stack_a);
static void	sort_4_5(t_node **stack_a, t_node **stack_b, int size)
{
	t_node	*small;
	t_node	*temp;
	int		count;

	count = 1;
	if (size == 5)
		count++;
	while (count != 0)
	{
		temp = *stack_a;
		small = find_small(*stack_a);
		while (temp != NULL && temp->value != small->value)
		{
			ra(stack_a);
			temp = *stack_a;
		}
		pb(stack_b, stack_a);
		count--;
	}
	sort_2_3(stack_a, 3);
	pa(stack_a, stack_b);
	if (size == 5)
		pa(stack_a, stack_b);
}

void	sort_stack(t_node **stack_a, t_node **stack_b)
{
	int	size;

	size = get_stack_size(*stack_a);
	if (is_sorted(*stack_a))
		return ;
	if (size == 2 || size == 3)
		sort_2_3(stack_a, size);
	else if (size == 4 || size == 5)
		sort_4_5(stack_a, stack_b, size);
	else if (size >= 6)
	{
		initialization(stack_a);
		radixsort(stack_a, stack_b, size);
	}
	return ;
}
