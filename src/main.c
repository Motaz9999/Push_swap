/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:25:20 by motaz             #+#    #+#             */
/*   Updated: 2025/10/22 16:26:55 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
/*
**
** How to run:
** 1. Test valid input: ./push_swap 8 5 10 3 7
** 2. Test invalid input (should print "Error" and exit):
**    ./push_swap 1 2 1          (duplicates)
**    ./push_swap 1 hello 3      (not a number)
**    ./push_swap 2147483648     (overflow)
**    ./push_swap ""             (empty string)
*/
#include "push_swap.h"

static void	ft_free_split(char **substring)
{
	int	i;

	if (!substring)
		return ;
	i = 0;
	while (substring[i])
	{
		free(substring[i]);
		i++;
	}
	free(substring);
}

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	words;

	count = 0;
	words = 0;
	while (*s != '\0')
	{
		if (*s != c && !words)
		{
			words = 1;
			count++;
		}
		else if (*s == c)
			words = 0;
		s++;
	}
	return (count);
}

static char	**make_argv(char *argv)
{
	char	**arr;
	char	*argv2;

	argv2 = ft_strjoin("z ", argv);
	if (argv2 == NULL)
		return (NULL);
	arr = ft_split(argv2, ' ');
	free(argv2);
	if (arr == NULL)
		return (NULL);
	return (arr);
}

static	void	init(t_node **stac_a, t_node **stack_b)
{
	*stac_a = NULL;
	*stack_b = NULL;
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**fake_argv;

	init(&stack_a, &stack_b);
	if (argc == 1)
		return (1);
	if (argc == 2)
	{
		fake_argv = make_argv(argv[1]);
		if (ft_strlen(argv[1]) == 0 || fake_argv == NULL)
		{
			error_happend(&stack_a);
			return (0);
		}
		stack_a = valdtion_and_dup(ft_count_words(argv[1], ' ') + 1, fake_argv);
		ft_free_split(fake_argv);
	}
	else
		stack_a = valdtion_and_dup(argc, argv);
	if (!stack_a)
		return (1);
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
