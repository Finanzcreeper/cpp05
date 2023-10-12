#ifndef CPP05_AFORM_HPP
#define CPP05_AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	bool signed_status;
	const int sign_grade;
	const int execution_grade;
	const std::string name;
	const std::string target;
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
	class formNotSignedException: public std::exception
	{
	private:
		bool isSigned;
	public:
		explicit formNotSignedException(bool signstatus);
		const char * what() const throw();
		bool getSignStatus() const;
	};
	AForm();
	AForm(const std::string& name, int sign, int exe, const std::string& target);
	AForm(AForm& src);
	~AForm();

	bool getSignedStatus() const;
	int getSignGrade() const;
	int getExecutionGrade() const;
	std::string getName() const;
	std::string getTarget() const;

	void BeSigned(Bureaucrat &signee);
	void execute(Bureaucrat const &executor);

	virtual void Purpose() = 0;

	AForm& operator=(const AForm &src);
};

std::ostream &operator<<(std::ostream &out, AForm &src);

#endif //CPP05_AFORM_HPP
