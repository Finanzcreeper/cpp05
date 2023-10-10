#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("Arbeiter_des_Gehobenen_Dienstes",12);
	Bureaucrat b("Arbeiter_des_Niederen_Dienstes",100);
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
	std::cout << a << std::endl;
	return 0;
}
