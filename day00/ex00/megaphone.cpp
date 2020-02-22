/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:58:12 by jacens            #+#    #+#             */
/*   Updated: 2020/02/21 01:15:33 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdio.h>
#include <ctype.h>

int		main(int ac, char **av)
{
	int		i = 0;
	int		j;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		while (av[++i])
		{
			j = -1;
			while (av[i][++j])
				av[i][j] = toupper(av[i][j]);
			std::cout << av[i];
		}
	std::cout << std::endl;
	return (0);
}