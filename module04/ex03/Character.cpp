#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character()
{
	for (int i = 0; i < 4; i++)
		this->inv[i] = NULL;
}

Character::Character(std::string const & name)
{
	for (int i = 0; i < 4; i++)
		this->inv[i] = NULL;
	this->name = name;
}

Character::Character( const Character & src )
{
	for (int i = 0; i < 4; i++)
		if (this->inv[i])
			delete this->inv[i];
	for (int i = 0; i < 4; i++)
		this->inv[i] = NULL;
	for (int i = 0; i < 4 && src.inv[i] ; i++)
		this->inv[i] = src.inv[i]->clone();
	this->name = src.getName();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	for (int i = 0; i < 4 ; i++)
		if (this->inv[i])
			delete this->inv[i];
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	if ( this != &rhs )
	{
		this->name = rhs.getName();
		for (int i = 0; i < 4; i++)
			if (rhs.inv[i])
				this->inv[i] = rhs.inv[i];
			else
				this->inv[i] = NULL;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Character::equip(AMateria* m)
{
	int i = 0;

	for (i = 0; i < 4 && this->inv[i] != NULL; i++);

	if (i < 4)
		this->inv[i] = m;
	else if (m)
		delete m;
}
	

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		this->inv[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->inv[idx])
		this->inv[idx]->use(target);
}


/* ************************************************************************** */
