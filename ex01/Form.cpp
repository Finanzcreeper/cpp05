#include "Form.hpp"

AForm::AForm() : signed_status(false), sign_grade(155), execution_grade(155), name("Altpapier")
{}

AForm::AForm(const std::string& name, int sign, int exe) : signed_status(false), sign_grade(sign), execution_grade(exe), name(name)
{
	if (sign < 1)
		throw AForm::gradeToHighException(sign);
	if (sign > 155)
		throw AForm::gradeToLowException(sign);
	if (exe < 1)
		throw AForm::gradeToHighException(exe);
	if (exe > 155)
		throw AForm::gradeToLowException(exe);
}

AForm::AForm(AForm &src) : signed_status(src.signed_status), sign_grade(src.sign_grade), execution_grade(src.execution_grade), name(src.name)
{}

AForm::~AForm()
{}

AForm &AForm::operator=(const AForm &src) {

	this->signed_status = src.signed_status;
	return (*this);
}

bool AForm::getSignedStatus() const {
	return this->signed_status;
}

int AForm::getSignGrade() const {
	return this->sign_grade;
}

int AForm::getExecutionGrade() const {
	return this->execution_grade;
}

std::string AForm::getName() const {
	return this->name;
}

void AForm::BeSigned(Bureaucrat &signee) {
	if (signee.getGrade() > this->sign_grade)
		throw AForm::gradeToLowException(signee.getGrade());
	else
		this->signed_status = true;
}

std::ostream &operator<<(std::ostream &out, AForm &src)
{
	out << "AForm " << src.getName() << " is ";
	if (src.getSignedStatus() == false)
		out << "not ";
	out << "signed, it needs a grade " << src.getSignGrade() << " Bureaucrat to sign it, and a grade " << src.getExecutionGrade() << " Bureaucrat to execute it." << std::endl;
	return (out);
}

AForm::gradeToLowException::gradeToLowException(int input) : grade(input)
{}

const char *AForm::gradeToLowException::what() const throw() {
	return "Grade to low";
}

int AForm::gradeToLowException::getGrade() const {
	return this->grade;
}

AForm::gradeToHighException::gradeToHighException(int input) : grade(input)
{}

const char *AForm::gradeToHighException::what() const throw() {
	return "Grade to high";
}

int AForm::gradeToHighException::getGrade() const {
	return this->grade;
}
