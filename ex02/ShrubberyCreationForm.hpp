#ifndef CPP05_SHRUBBERYCREATIONFORM_HPP
#define CPP05_SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:

public:
	ShrubberyCreationForm();
	explicit ShrubberyCreationForm(const std::string &name);
	ShrubberyCreationForm(ShrubberyCreationForm &src);
	~ShrubberyCreationForm();
	void Purpose();

	ShrubberyCreationForm &operator=(ShrubberyCreationForm src);
};
#endif //CPP05_SHRUBBERYCREATIONFORM_HPP
