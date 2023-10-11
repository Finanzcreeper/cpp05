#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Altpapier", 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm(target, 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src) : AForm(src.getName(), 72, 45)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void RobotomyRequestForm::Purpose(std::string target) {
	srand((unsigned int)std::time(NULL));
	int a = std::rand() % 2;
	std::cout << "*DriLliNg sOuNDs*" << std::endl;
	switch(a) {
		default:
			std::cout << target << "has been robotomized successfully." <<std::endl;
			break;
		case 0:
			std::cout << target << "has been robotomized successfully." <<std::endl;
			break;
		case 1:
			std::cout << "robotomy of " << target << " failed" << std::endl;
			break;
	}
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm src) {
	if(this != &src)
		AForm::operator=(src);
	return (*this);
}
