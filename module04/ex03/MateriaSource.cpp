#include "MateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->materia[i] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource & src )
{
	for (int i = 0; i < 4 ; i++)
		if (src.materia[i])
			this->materia[i] = src.materia[i];
		else
			this->materia[i] = NULL;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4 ; i++)
		if (this->materia[i])
			delete this->materia[i];
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource &				MateriaSource::operator=( MateriaSource const & rhs )
{
	if ( this != &rhs )
		for (int i = 0; i < 4; i++)
			if (rhs.materia[i])
				this->materia[i] = rhs.materia[i];
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void MateriaSource::learnMateria(AMateria* m)
{
	int i = 0;

	for (i = 0; i < 4 && this->materia[i] != NULL; i++);

	if (i < 4)
		this->materia[i] = m;
	else if (m)
		delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
		if (this->materia[i] != NULL && this->materia[i]->getType() == type)
				return (this->materia[i]->clone());
	return (0);
}

/* ************************************************************************** */
