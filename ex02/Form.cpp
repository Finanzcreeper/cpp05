#include "Form.hpp"

Form::Form() : signed_status(false), sign_grade(155), execution_grade(155), name("Altpapier")
{}

Form::Form(const std::string& name, int sign, int exe) :  signed_status(false), sign_grade(sign), execution_grade(exe), name(name)
{
	if (sign < 1)
		throw Form::gradeToHighException(sign);
	if (sign > 155)
		throw Form::gradeToLowException(sign);
	if (exe < 1)
		throw Form::gradeToHighException(exe);
	if (exe > 155)
		throw Form::gradeToLowException(exe);
}

Form::Form(Form &src) : signed_status(src.signed_status), sign_grade(src.sign_grade), execution_grade(src.execution_grade), name(src.name)
{}

Form::~Form()
{}

Form &Form::operator=(const Form &src) {

	this->signed_status = src.signed_status;
	return (*this);
}

bool Form::getSignedStatus() const {
	return this->signed_status;
}

int Form::getSignGrade() const {
	return this->sign_grade;
}

int Form::getExecutionGrade() const {
	return this->execution_grade;
}

std::string Form::getName() const {
	return this->name;
}

void Form::BeSigned(Bureaucrat &signee) {
	if (signee.getGrade() > this->sign_grade)
		throw Form::gradeToLowException(signee.getGrade());
	else
		this->signed_status = true;
}

std::ostream &operator<<(std::ostream &out, Form &src)
{
	out << "Form " << src.getName() << " is ";
	if (src.getSignedStatus() == false)
		out << "not ";
	out << "signed, it needs a grade " << src.getSignGrade() << " Bureaucrat to sign it, and a grade " << src.getExecutionGrade() << " Bureaucrat to execute it." << std::endl;
	return (out);
}

Form::gradeToLowException::gradeToLowException(int input) : grade(input)
{}

const char *Form::gradeToLowException::what() const throw() {
	return "Grade to low";
}

int Form::gradeToLowException::getGrade() const {
	return this->grade;
}

Form::gradeToHighException::gradeToHighException(int input) : grade(input)
{}

const char *Form::gradeToHighException::what() const throw() {
	return "Grade to high";
}

int Form::gradeToHighException::getGrade() const {
	return this->grade;
}
