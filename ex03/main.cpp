#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat a("Arbeiter_des_Gehobenen_Dienstes",12);
	Bureaucrat b("Arbeiter_des_Niederen_Dienstes",150);
	Bureaucrat f(a);
	Intern StuHilKra;
	AForm* scf;
	AForm* ppf;
	AForm* rrf;
	scf = StuHilKra.makeForm("shrubbery creation", "scf");
	ppf = StuHilKra.makeForm("presidential pardon", "Your MUM");
	rrf = StuHilKra.makeForm("robotomy request", "rrf");
	try {
		f.signForm(*scf);
		f.executeForm(*scf);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
		f.signForm(*ppf);
		f.executeForm(*ppf);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
		f.signForm(*rrf);
		f.executeForm(*rrf);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	while(f.getGrade() > 5) {
		f.promotion();
	}
	try
	{
		f.executeForm(*ppf);
	}
	catch (std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}
	delete ppf;
	delete scf;
	delete rrf;
	/*
	try
	{
		Bureaucrat c("Wegbefoerderter_Idiot",-1);
	}
	catch (Bureaucrat::gradeToHighException &exception)
	{
		std::cout << exception.what() << ": " << exception.getGrade() << std::endl;
	}
	try
	{
		Bureaucrat d("Studentische_hilfskraft", 160);
	}
	catch (Bureaucrat::gradeToLowException &exception)
	{
		std::cout << exception.what() << ": " << exception.getGrade() << std::endl;
	}
	std::cout << a << std::endl;
	std::cout << a << " got an promotion to grade: ";
	a.promotion();
 	std::cout << a.getGrade() << std::endl;
	std::cout << b << std::endl;
	std::cout << b << " got an demotion to grade: ";
	b.demotion();
	std::cout << b.getGrade() << std::endl;
	try
	{
		std::cout << a.getName() << " is on a promotion spree!" << std::endl;
		while(true)
		{
			std::cout << a.getGrade() << ", ";
			a.promotion();
		}
	}
	catch (Bureaucrat::gradeToHighException &exception)
	{
		std::cout << exception.what() << ": " << exception.getGrade() << std::endl;
	}
	std::cout << a << std::endl;*/
	return 0;
}
