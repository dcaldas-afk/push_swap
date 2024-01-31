/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:59:18 by dcaldas-          #+#    #+#             */
/*   Updated: 2024/01/29 20:51:03 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

int	is_sign(int c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	is_digit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

int	is_space(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	is_alphanumerical(int c)
{
	if ((c >= 33 && c <= 42) || (c == 44)
		|| (c >= 47 && c <= 47) || (c >= 58 && c <= 126))
		return (0);
	return (1);
}

bool	argv_check(char **argv, int i, int j)
{
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (is_sign(argv[i][j]))
			{
				j++;
				if (!is_digit(argv[i][j]))
					return (false);
			}
			else if (is_digit(argv[i][j]))
			{
				j++;
				if (!is_digit(argv[i][j]) && !is_space(argv[i][j]))
					return (false);
				if (argv[i][j] == '\0')
					break ;
			}
			j++;
		}
		i++;
	}
	return (true);
}
