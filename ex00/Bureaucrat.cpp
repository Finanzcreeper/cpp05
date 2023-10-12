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
		throw gradeToHighException(input);
	if (input > 155)
		throw gradeToLowException(input);
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
	this->setGrade(this->getGrade() + 1);
}

void Bureaucrat::promotion()
{
	this->setGrade(this->getGrade() - 1);
}

Bureaucrat::gradeToHighException::gradeToHighException(int input) : grade(input)
{}

const char *Bureaucrat::gradeToHighException::what() const throw()
{
	return ("Grade to high");
}

int Bureaucrat::gradeToHighException::getGrade() const
{
	return this->grade;
}

Bureaucrat::gradeToLowException::gradeToLowException(int input) : grade(input)
{}

const char *Bureaucrat::gradeToLowException::what() const throw()
{
	return ("Grade to low:");
}

int Bureaucrat::gradeToLowException::getGrade() const
{
	return (this->grade);
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