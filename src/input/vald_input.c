/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vald_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:25:53 by motaz             #+#    #+#             */
/*   Updated: 2025/10/18 20:31:04 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// here we make the stack btw i want to added to the
// last one (7 8 10) be like 7(top) then 7top,8,10(last)
// i have a problem with (more than one sign) 
//  the num is zero and this is bad
// cheack argc and argv in the main
t_node	*valdtion_and_dup(int argc, char **argv)
{
	t_node	*stack;
	int		i;
	long	num;

	i = 1;
	stack = NULL;
	if (!check_for_type(argv, argc))
	{
		error_happend(&stack);
		return (NULL);
	}
	while (argv[i] != NULL)
	{
		num = ft_atol(argv[i++]);
		if (num > INT_MAX || num < INT_MIN)
		{
			error_happend(&stack);
			return (NULL);
		}
		add_back(&stack, create_node(num));
	}
	return (stack);
}
// not int then i have dup then limits //here we check on if it str

int	check_for_type(char **argv, int argc)
{
	char	**str;
	int		i;

	i = 1;
	str = argv;
	while (str[i] != NULL)
	{
		if (!check_for_str(str[i]))
			return (FALSEE);
		i++;
	}
	if (check_for_dup(argv, argc - 1))
	{
		return (FALSEE);
	}
	return (TRUEE);
}
// if it found str return false if there is no str return true

int	check_for_str(char *str)
{
	if (str == NULL || *str == '\0')
		return (FALSEE);
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (FALSEE);
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (FALSEE);
		str++;
	}
	return (TRUEE);
}
// check on every arg if it the same

int	check_for_dup(char **str, int argc)
{
	int	i;
	int	j;
	int	*nums;

	i = 0;
	nums = malloc(sizeof(int) * argc);
	if (nums == NULL)
		return (TRUEE);
	while (i++ < argc)
		nums[i - 1] = ft_atol(str[i]);
	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (nums[i] == nums[j++])
			{
				return (free(nums), TRUEE);
			}
		}
		i++;
	}
	free(nums);
	return (FALSEE);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (10 * result) + (*str - '0');
		str++;
	}
	return (result * sign);
}
