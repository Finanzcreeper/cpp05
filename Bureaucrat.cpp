#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	this->grade = 155;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade()
{
	Bureaucrat::setGrade(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat &src) : name(src.name), grade(src.grade)
{}

void Bureaucrat::setGrade(const int input)
{
	if (input < 1)
		throw gradeToHighException(grade);
	if (input > 155)
		throw GradeToLowException(grade);
	this->grade = input;
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

void Bureaucrat::demotion()
{
	++this->grade;
}

void Bureaucrat::promotion()
{
	--this->grade;
}

Bureaucrat::gradeToHighException::gradeToHighException(int input) : grade(input)
{}

const char *Bureaucrat::gradeToHighException::what() const throw()
{
	return ("Grade to high");
}

int Bureaucrat::gradeToHighException::getGrade()
{
	return this->grade;
}

Bureaucrat::GradeToLowException::GradeToLowException(int input) : grade(input)
{}

const char *Bureaucrat::GradeToLowException::what() const throw()
{
	return ("Grade to low:");
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
		this->grade = src.getGrade();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src)
{
	out << src.getName() << ", bureaucrat grade " << src.getGrade();
	return out;
}

Bureaucrat::~Bureaucrat()
{}
