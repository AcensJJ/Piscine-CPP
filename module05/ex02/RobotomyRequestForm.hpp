#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class RobotomyRequestForm : public Form
{

	public:
		RobotomyRequestForm(std::string _target);
		RobotomyRequestForm( const RobotomyRequestForm & src );
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );

		void 	execute(Bureaucrat const & executor) const;

	private:
		RobotomyRequestForm();

};

#endif /* ********************************************* ROBOTOMYREQUESTFORM_H */