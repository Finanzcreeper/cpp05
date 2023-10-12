#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Altpapier", 72, 45, "none")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm(target, 72, 45, target)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src) : AForm(src)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void RobotomyRequestForm::Purpose() {
	srand((unsigned int)std::time(NULL));
	int a = std::rand() % 2;
	std::cout << "*DriLliNg sOuNDs*" << std::endl;
	if (a == 1)
		std::cout << this->getTarget() << " has been robotomized successfully." <<std::endl;
	else
		std::cout << "robotomy of " << this->getTarget() << " failed" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm src) {
	if(this != &src)
		AForm::operator=(src);
	return (*this);
}
