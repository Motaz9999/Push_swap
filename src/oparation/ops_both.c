/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_both.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 01:57:56 by motaz             #+#    #+#             */
/*   Updated: 2025/10/18 20:31:25 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*temp;
	t_node	*temp2;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	temp2 = *stack;
	while (temp2->next != NULL)
	{
		temp2 = temp2->next;
	}
	temp2->next = temp;
}

static void	rrotate(t_node **stack)
{
	t_node	*temp;
	t_node	*temp2;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	while ((temp->next)->next != NULL)
	{
		temp = temp->next;
	}
	temp2 = temp->next;
	temp->next = NULL;
	temp2->next = *stack;
	*stack = temp2;
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
	write(1, "rrr\n", 3);
}
