/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:50:51 by motaz             #+#    #+#             */
/*   Updated: 2025/10/18 20:31:54 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// i want to sort this stack using the ops and the indexis
// here to how many bits it contains
static int	find_how_many_bits(int size)
{
	int	bits;

	bits = 0;
	while (((size - 1) >> bits) != 0)
	{
		bits++;
	}
	return (bits);
}
// now how to use radix sort 1. initialzation 
//2.we need to know the biggest how much node it have
// size of node == how many indexis it have ! -1 bc it 0 - (size -1)
// how many time the loop well be done
// i need to see if it the BIT is 0 or 1 (if 1 -> pb) else (ra)

void	radixsort(t_node **stack_a, t_node **stack_b, int size)
{
	int	max_bits;
	int	i;
	int	j;

	i = 0;
	max_bits = find_how_many_bits(size);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				pb(stack_b, stack_a);
			else
				ra(stack_a);
			j++;
		}
		while (*stack_b != NULL)
			pa(stack_a, stack_b);
		i++;
	}
}
