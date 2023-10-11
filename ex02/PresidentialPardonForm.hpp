#ifndef CPP05_PRESIDENTIALPARDONFORM_HPP
#define CPP05_PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(PresidentialPardonForm &src);
	~PresidentialPardonForm();
	void Purpose(std::string target);

	PresidentialPardonForm& operator=(PresidentialPardonForm src);
};

#endif //CPP05_PRESIDENTIALPARDONFORM_HPP
