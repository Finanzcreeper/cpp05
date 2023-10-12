
#include "Intern.hpp"
#include "AForm.hpp"
#include <string>
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"



AForm *Intern::makeForm(const std::string& docName, const std::string& target) {
	AForm* CreatedForm;
	int i = 0;
	std::string docLib[4];
	docLib[0] = "shrubbery creation";
	docLib[1] = "presidential pardon";
	docLib[2] = "robotomy request";
	while (docLib[i].empty() == false){
		if (docLib[i] == docName)
			break;
		i++;
	}
	switch (i) {
		default:
			CreatedForm = NULL;
			break;
		case 0:
			CreatedForm = new ShrubberyCreationForm(target);
			break;
		case 1:
			CreatedForm = new PresidentialPardonForm(target);
			break;
		case 2:
			CreatedForm = new RobotomyRequestForm(target);
			break;
	}
	if(CreatedForm == NULL)
		std::cout << "Intern could not find the right Template in the Library to create a " << docName << std::endl;
	else
		std::cout << "Intern created: " << docLib[i] << " form" << std::endl;
	return (CreatedForm);
}

Intern::Intern()
{}

Intern::Intern(Intern &src) {
	*this = src;
}

Intern::~Intern()
{}

Intern &Intern::operator=(Intern const &src) {
	(void)src;
	return *this;
}
