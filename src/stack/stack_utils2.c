/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:13:37 by moodeh            #+#    #+#             */
/*   Updated: 2025/10/18 20:30:18 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_node *stack)
{
	if (stack == NULL)
		return (TRUEE);
	return (FALSEE);
}

t_node	*pop(t_node **stack)
{
	t_node	*popped_node;

	if (is_empty(*stack))
		return (NULL);
	popped_node = *stack;
	*stack = popped_node->next;
	popped_node->next = NULL;
	return (popped_node);
}

// void	print_stack(t_node *stack, char name)
// {
// 	printf("-------stack %c ------\n", name);
// 	if (is_empty(stack))
// 	{
// 		printf("its empty\n");
// 		printf("---------------\n");
// 		return ;
// 	}
// 	while (!is_empty(stack))
// 	{
// 		printf("%d\n", stack->value);
// 		stack = stack->next;
// 	}
// 	printf("---------------\n");
// }
