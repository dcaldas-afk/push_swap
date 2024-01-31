/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:19:03 by dcaldas-          #+#    #+#             */
/*   Updated: 2024/01/30 16:46:31 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

void	ko_exit(void);
void	ok_exit(void);
void	checker(t_stack **stack_a);
t_stack	*checker_parser(int argc, char **argv);

#endif
