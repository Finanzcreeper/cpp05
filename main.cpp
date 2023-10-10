#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a("Arbeiter_des_Gehobenen_Dienst",12);
	Bureaucrat b("Arbeiter_des_Niederen_Dienst",100);
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
	std::cout << b << std::endl;
	return 0;
}
