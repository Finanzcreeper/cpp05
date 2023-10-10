#include "Bureaucrat.hpp"

int main() {
	new Bureaucrat("Arbeiter_des_Gehobenen_Dienst",12);
	new Bureaucrat("Arbeiter_des_Niederen_Dienst",100);
	try {
		new Bureaucrat("Wegbefoerderter_Idiot",0);
	}
	catch (Bureaucrat::gradeToHighException &exception) {
		std::cout << exception.what() << ": " << exception.getGrade() << std::endl;
	}
	return 0;
}
