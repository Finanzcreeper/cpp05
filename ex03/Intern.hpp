#ifndef CPP05_INTERN_HPP
#define CPP05_INTERN_HPP

#include "AForm.hpp"
#include <string>


class Intern
{
public:
	Intern();
	Intern(Intern &src);
	~Intern();

	AForm *makeForm(const std::string& docName, const std::string& target);

	Intern &operator=(Intern const &src);
};

#endif //CPP05_INTERN_HPP
