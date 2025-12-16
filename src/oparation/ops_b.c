/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 01:57:53 by motaz             #+#    #+#             */
/*   Updated: 2025/10/18 01:17:38 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_node **stack_b, t_node **stack_a)
{
	t_node	*temp;

	if (*stack_a == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	push(stack_b, temp);
	write(1, "pb\n", 3);
}

void	sb(t_node **stack_b)
{
	t_node	*temp;
	t_node	*swap;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	temp = *stack_b;
	swap = (*stack_b)->next;
	*stack_b = (*stack_b)->next;
	temp->next = swap->next;
	swap->next = temp;
	swap = NULL;
	temp = NULL;
	write(1, "sb\n", 3);
}

void	rb(t_node **stack_b)
{
	t_node	*temp;
	t_node	*temp2;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = NULL;
	temp2 = *stack_b;
	while (temp2->next != NULL)
	{
		temp2 = temp2->next;
	}
	temp2->next = temp;
	write(1, "rb\n", 3);
}

void	rrb(t_node **stack_b)
{
	t_node	*temp;
	t_node	*temp2;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	temp = *stack_b;
	while ((temp->next)->next != NULL)
	{
		temp = temp->next;
	}
	temp2 = temp->next;
	temp->next = NULL;
	temp2->next = *stack_b;
	*stack_b = temp2;
	write(1, "rrb\n", 3);
}
