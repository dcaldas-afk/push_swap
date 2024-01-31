/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:21:29 by dcaldas-          #+#    #+#             */
/*   Updated: 2024/01/30 16:48:42 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

int	is_alpha(const char *c)
{
	if ((*c >= '0') && (*c <= '9'))
		return (0);
	return (1);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	chr;

	chr = (unsigned char)c;
	while (*s)
	{
		if (*s == chr)
			return ((char *)s);
		s++;
	}
	if (chr == '\0')
		return ((char *)s);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int				sign;
	unsigned int	result;

	sign = 1;
	result = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
		sign *= -1;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	if (is_alpha(nptr) || ft_strchr(nptr, '.'))
		error_exit();
	while (*nptr >= '0' && *nptr <= '9')
		result = result * 10 + *nptr++ - '0';
	if (result > INT_MAX)
		error_exit();
	return (result * sign);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dst, const char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
}
