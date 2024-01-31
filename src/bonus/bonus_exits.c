/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_exits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 00:15:08 by dcaldas-          #+#    #+#             */
/*   Updated: 2024/01/30 16:43:28 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"
#include "../../lib/checker.h"

void	ko_exit(void)
{
	write(2, "KO\n", 3);
	exit(1);
}

void	ok_exit(void)
{
	write(1, "OK\n", 3);
	exit(1);
}
