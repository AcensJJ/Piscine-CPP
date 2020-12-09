#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character()
{
	amateria = new t_amateria;
	amateria->next = NULL;
	amateria->content = NULL;
}

Character::Character(std::string const & name)
{
	amateria = new t_amateria;
	amateria->next = NULL;
	amateria->content = NULL;
	this->name = name;
}

Character::Character( const Character & src )
{
	amateria = new t_amateria;
	t_amateria	*temp;

	while(amateria)
	{
		temp = amateria;
		amateria = amateria->next;
		delete temp->content;
		delete temp;
	}
	amateria->next = NULL;
	amateria->content = NULL;
	temp = src.amateria;
	while (temp)
	{
		equip(temp->content->clone());
		temp = temp->next;
	}
	this->name = src.getName();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	t_amateria	*temp;

	while(amateria)
	{
		temp = amateria;
		amateria = amateria->next;
		delete temp->content;
		delete temp;
	}
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	name = rhs.getName();
	amateria = new t_amateria;
	amateria->next = NULL;
	amateria->content = NULL;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Character const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Character::equip(AMateria* m)
{
	if (m)
	{
		if (!amateria->content)
			amateria->content = m;
		else if (!amateria->next)
		{
			amateria->next = new t_amateria;
			amateria->next->content = m;
			amateria->next->next = NULL;
		}
		else if (!amateria->next->next)
		{
			amateria->next->next = new t_amateria;
			amateria->next->next->content = m;
			amateria->next->next->next = NULL;
		}
		else if (!amateria->next->next->next)
		{
			amateria->next->next->next = new t_amateria;
			amateria->next->next->next->content = m;
			amateria->next->next->next->next = NULL;
		}
		else
			delete m;
	}
}

void Character::unequip(int idx)
{
	t_amateria *tmp;
	t_amateria *tmp_prev;

	if (amateria->content)
	{
		tmp = amateria;
		while (--idx < -1 && tmp->next)
		{
			tmp_prev = tmp;
			tmp = tmp->next;
		}
		if (idx == -1 && tmp_prev != tmp && tmp->content)
		{
			tmp_prev->next = tmp->next;
			tmp->next = NULL;
			tmp->content = NULL;
			delete tmp;
		}
		else if (idx == -1 && tmp->content)
			tmp->content = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	int			i;
	t_amateria	*tmp;

	tmp = amateria;
	i = -1;
	while (++i < idx && tmp->next)
		tmp = tmp->next;
	if (i == idx && tmp->content)
		tmp->content->use(target);
}


/* ************************************************************************** */