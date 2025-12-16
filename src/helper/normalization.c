/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 20:41:50 by moodeh            #+#    #+#             */
/*   Updated: 2025/10/18 20:32:55 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// here we give the indexis
// put the indexis is from the small to big but NOT SORTED
// ok every node i take i make a loop to count who
// less than here in index and give it that index
void	initialization(t_node **stack)
{
	int		index;
	t_node	*temp;
	t_node	*temp2;

	temp = *stack;
	while (temp != NULL)
	{
		index = 0;
		temp2 = *stack;
		while (temp2 != NULL)
		{
			if (temp->value > temp2->value)
				index++;
			temp2 = temp2->next;
		}
		temp->index = index;
		temp = temp->next;
	}
}
