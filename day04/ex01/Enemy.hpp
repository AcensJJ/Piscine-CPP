/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacens <jacens@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:02:09 by jacens            #+#    #+#             */
/*   Updated: 2020/03/06 15:02:27 by jacens           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "AWeapon.hpp"

class Enemy
{
	private:
	std::string Type;
	int			HP;

	public:
	Enemy(int hp, std::string const & type);
	virtual ~Enemy();
	Enemy(Enemy const &copied);
	Enemy& operator=(const Enemy &copied);
	std::string getType() const;
	void setType(std::string);
	int getHP() const;
	void	setHP(int);
	virtual void takeDamage(int);
};

#endif