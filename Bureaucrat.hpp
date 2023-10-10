#ifndef CPP05_BUREAUCRAT_HPP
#define CPP05_BUREAUCRAT_HPP

#include <string>
#include <stdexcept>
#include <iostream>

class Bureaucrat
{
private:
	const std::string name;
	int grade;
public:
	class gradeToHighException : public std::exception
	{
	private:
		int grade;
	public:
		explicit gradeToHighException(int input);
		const char * what() const throw();
		int getGrade();
	};
	class GradeToLowException : public std::exception
	{
	private:
		int grade;
	public:
		explicit GradeToLowException(int input);
		const char * what() const throw();
	};

	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(Bureaucrat& src);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;
	void setGrade(int input);
	void promotion();
	void demotion();

	Bureaucrat& operator=(const Bureaucrat& src);
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat& src);

#endif
