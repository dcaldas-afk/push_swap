/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:21:29 by dcaldas-          #+#    #+#             */
/*   Updated: 2024/01/12 16:01:49 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	unsigned int	result;

	sign = 1;
	result = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
		sign *= -1;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
		result = result * 10 + *nptr++ - '0';
	return (result * sign);
}

void	ft_strcpy(char *dst, const char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
}

size_t	ft_wordcounter(const char *str, char c)
{
	size_t	i;
	size_t	wordcount;

	i = 0;
	wordcount = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			wordcount++;
		i++;
	}
	return (wordcount);
}

char	*ft_mallocnstr(const char *s, char n, int *i)
{
	char	*str;
	int		start;
	int		len;

	start = *i;
	while (s[*i] != '\0' && s[*i] != n)
		(*i)++;
	len = *i - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, s + start);
	return (str);
}

char	**ft_split(char const *str, char c)
{
	char	**s;
	int		i;
	int		j;
	int		k;

	if (str == NULL)
		return (NULL);
	i = 0;
	k = 0;
	j = ft_wordcounter(str, c);
	s = (char **)malloc(sizeof(char *) * (j + 1));
	if (s == NULL)
		return (NULL);
	while (i < j)
	{
		while (str[k] == c)
			k++;
		s[i] = ft_mallocnstr(str, c, &k);
		if (s[i] == NULL)
		{
			while (i > 0)
				free(s[--i]);
			free(s);
			return (NULL);
		}
		i++;
	}
	s[i] = NULL;
	return (s);
}

/*int main()
{
    char str[] = "Hello World";
    char **result;
    int i;

    result = ft_split(str, ' ');
    if (result == NULL)
    {
        printf("Erro na alocação de memória ou entrada nula.\n");
        return 1;
    }

    i = 0;
    while (result[i] != NULL)
    {
        printf("%s\n", result[i]);
        free(result[i]); // Liberar cada substring
        i++;
    }

    free(result); // Liberar a matriz de strings

    return 0;
}*/
