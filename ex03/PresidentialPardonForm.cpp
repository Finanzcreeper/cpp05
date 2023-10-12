#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5, "none")
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src)  : AForm(src)
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5, target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void PresidentialPardonForm::Purpose() {
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm src) {
	if(this != &src)
		AForm::operator=(src);
	return (*this);
}
