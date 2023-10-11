#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Altpapier", 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src)  : AForm(src)
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm(target, 25, 5)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void PresidentialPardonForm::Purpose(std::string target) {
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm src) {
	if(this != &src)
		AForm::operator=(src);
	return (*this);
}
