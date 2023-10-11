#ifndef CPP05_ROBOTOMYREQUESTFORM_HPP
#define CPP05_ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(RobotomyRequestForm &src);
	~RobotomyRequestForm();

	void Purpose(std::string target);
	RobotomyRequestForm &operator=(RobotomyRequestForm src);
};

#endif //CPP05_ROBOTOMYREQUESTFORM_HPP
