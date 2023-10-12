#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat a("Arbeiter_des_Gehobenen_Dienstes",12);
	Bureaucrat b("Arbeiter_des_Niederen_Dienstes",100);
	Bureaucrat f(a);
	AForm q("72a-1", 15, 11);
	AForm h;
	std::cout << q << std::endl;
	std::cout << h << std::endl;
	try
	{
		b.signForm(h);
		b.signForm(q);
	}
	catch (AForm::gradeToLowException &exception)
	{
		std::cout << exception.what() << std::endl;
	}
	try
	{
		f.signForm(h);
		f.signForm(q);
	}
	catch (AForm::gradeToLowException &exception)
	{
		std::cout << exception.what() << std::endl;
	}
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
