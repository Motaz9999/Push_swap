/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 01:58:03 by motaz             #+#    #+#             */
/*   Updated: 2025/10/18 01:18:32 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int val)
{
	t_node	*new_node;

	new_node = NULL;
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->index = -1;
	new_node->value = val;
	new_node->next = NULL;
	return (new_node);
}

// if stack dose not exisit or new node dose not exisit
void	push(t_node **stack, t_node *new_node)
{
	if (new_node == NULL)
		return ;
	new_node->next = *stack;
	*stack = new_node;
}

int	get_stack_size(t_node *stack)
{
	int	count;

	count = 0;
	if (stack == NULL)
		return (count);
	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
// its ok to use the same var to shift and free the stack

void	free_stack(t_node **stack)
{
	t_node	*del;

	del = NULL;
	if (stack == NULL || *stack == NULL)
		return ;
	while (*stack != NULL)
	{
		del = (*stack);
		*stack = (*stack)->next;
		free(del);
	}
	*stack = NULL;
}
// tp point to the first node then con with loop
// ask why used *stack not stack and the same for if
// thers somitheing in next keep going
// now we are at the last elemnt

void	add_back(t_node **stack, t_node *node)
{
	t_node	*temp;

	if (node == NULL)
		return ;
	if (*stack == NULL)
	{
		*stack = node;
		return ;
	}
	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = node;
}
