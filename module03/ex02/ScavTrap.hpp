#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

  public :
  	ScavTrap();
  	ScavTrap(std::string name);
  	ScavTrap(const ScavTrap &src);
	ScavTrap &	operator=( ScavTrap const & rhs );
	virtual ~ScavTrap();
	void challengNewcomer(std::string const & target);
};

#endif
