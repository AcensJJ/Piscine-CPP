# include "Bureaucrat.hpp"
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

int main2()
{
	srand(time(NULL));
	Bureaucrat* bob = new Bureaucrat("bob", 150);
	Bureaucrat* jimmy = new Bureaucrat("jimmy", 1);
	PresidentialPardonForm* form;
	ShrubberyCreationForm* shrubForm = new ShrubberyCreationForm("forest");
	RobotomyRequestForm* roboform = new RobotomyRequestForm("Bill Potts");

	try
	{
		form = new PresidentialPardonForm("Daphne");
	}
	catch (std::exception & e)
	{
		std::cout << "Exception " << e.what() << std::endl;
	}
	std::cout << *form << std::endl;
	std::cout << *shrubForm << std::endl;
	std::cout << *roboform << std::endl;
	std::cout << *bob << std::endl;
	std::cout << *jimmy << std::endl;

	try
	{
		bob->incrementGrade();
		jimmy->incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << "Exception " << e.what() << std::endl;
	}
	std::cout << *bob << std::endl;
	std::cout << *jimmy << std::endl;

	try
	{
		jimmy->decrementGrade();
		bob->decrementGrade();
		bob->decrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << "Exception " << e.what() << std::endl;
	}
	std::cout << *bob << std::endl;
	std::cout << *jimmy << std::endl;
	bob->signForm(form);
	jimmy->signForm(form);
	std::cout << *form << std::endl;

	bob->executeForm(*form);
	jimmy->executeForm(*form);


	bob->executeForm(*roboform);
	jimmy->executeForm(*roboform);

	bob->signForm(roboform);
	jimmy->signForm(roboform);

	bob->executeForm(*shrubForm);
	bob->signForm(shrubForm);
	jimmy->signForm(shrubForm);

	try
	{
		int j = 0;
		while (j++ < 20)
			bob->incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << "Exception " << e.what() << std::endl;
	}

	bob->executeForm(*shrubForm);

	bob->executeForm(*roboform);
	jimmy->executeForm(*roboform);
	jimmy->executeForm(*roboform);
	jimmy->executeForm(*roboform);
	jimmy->executeForm(*roboform);
	delete (bob);
	delete (jimmy);
	delete (form);
	delete (roboform);
	delete (shrubForm);
	return (0);
}

int main()
{
	main2();
	/*while (1)
	{
		
	}*/
}