/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:02:05 by jacens            #+#    #+#             */
/*   Updated: 2020/03/06 15:02:06 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const & type)
{
	HP = hp;
	Type = type;
}

Enemy::~Enemy()
{
	
}

std::string Enemy::getType() const
{
	return Type;
}

void Enemy::setType(std::string i)
{
	Type = i;
}

void Enemy::setHP(int i)
{
	HP = i;
}

int Enemy::getHP() const
{
	return HP;
}

Enemy::Enemy(Enemy const &copied)
{
	HP = copied.getHP();
	Type = copied.getType();
}

void	Enemy::takeDamage(int i)
{
	if (getHP() > i)
		setHP(getHP() - i);
	else
		setHP(0);
}

Enemy& Enemy::operator=(const Enemy &copied)
{
	HP = copied.getHP();
	Type = copied.getType();
	return (*this);
}
