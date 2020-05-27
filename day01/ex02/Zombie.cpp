/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 08:49:12 by jacens            #+#    #+#             */
/*   Updated: 2020/05/27 15:57:45 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void    Zombie::announce()
{
    std::cout << "<" << name << " " << "(" << type << ")" << "> ";
    puts("Braiiiiiiinnnssss ...");
}

int     Zombie::get_Zombie()
{
  std::cout << "Your name kawaii is " << name << "\n";
  std::cout << "Your type kawaii is " << type << "\n";
  return (1);
}

int     Zombie::set_Zombie()
{
    std::string newname;
	std::string newtype;
	puts("\nNew name :");
  	std::cin >> newname;
  	puts("\nNew type :");
  	std::cin >> newtype;
  	name = newname;
  	type = newtype;
  	return (1);
}

Zombie::Zombie(std::string name, std::string type)
{
  this->name = name;
  this->type = type;
};

Zombie::Zombie()
{
  this->name = "default";
  this->type = "default";
};
