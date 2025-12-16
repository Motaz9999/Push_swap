/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 01:57:50 by motaz             #+#    #+#             */
/*   Updated: 2025/10/18 01:17:19 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// lest swap first 2 elements in a
//*stack is pointer to the node and **stack is enter the node
// here we need to push the top of stack_b to stack_a
void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*del;

	if (*stack_b == NULL)
		return ;
	del = *stack_b;
	*stack_b = (*stack_b)->next;
	del->next = NULL;
	push(stack_a, del);
	write(1, "pa\n", 3);
}

void	sa(t_node **stack_a)
{
	t_node	*temp;

	if (is_empty(*stack_a) || 1 >= get_stack_size(*stack_a))
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = temp->next;
	(*temp).next = *stack_a;
	*stack_a = temp;
	write(1, "sa\n", 3);
}

void	ra(t_node **stack_a)
{
	t_node	*top;
	t_node	*temp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	top = *stack_a;
	*stack_a = (*stack_a)->next;
	temp = *stack_a;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	top->next = NULL;
	temp->next = top;
	write(1, "ra\n", 3);
}

void	rra(t_node **stack_a)
{
	t_node	*temp;
	t_node	*temp2;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	temp = *stack_a;
	while ((temp->next)->next != NULL)
	{
		temp = temp->next;
	}
	temp2 = temp->next;
	temp->next = NULL;
	temp2->next = *stack_a;
	*stack_a = temp2;
	write(1, "rra\n", 4);
}
