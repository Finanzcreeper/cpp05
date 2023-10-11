#ifndef CPP05_FORM_HPP
#define CPP05_FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	bool signed_status;
	const int sign_grade;
	const int execution_grade;
	const std::string name;
public:
class gradeToLowException : public std::exception
	{
	private:
		int grade;
	public:
		explicit gradeToLowException(int input);
		const char * what() const throw();
		int getGrade() const;
	};
	class gradeToHighException: public std::exception
	{
	private:
		int grade;
	public:
		explicit gradeToHighException(int input);
		const char * what() const throw();
		int getGrade() const;
	};
	Form();
	Form(const std::string& name, int sign, int exe);
	Form(Form& src);
	~Form();

	bool getSignedStatus() const;
	int getSignGrade() const;
	int getExecutionGrade() const;
	std::string getName() const;

	void BeSigned(Bureaucrat &signee);

	Form& operator=(const Form &src);
};

std::ostream &operator<<(std::ostream &out, Form &src);

#endif //CPP05_FORM_HPP
