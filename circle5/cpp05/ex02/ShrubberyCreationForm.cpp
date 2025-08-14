#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("ShrubberyCreationForm", 145, 137), target("default")
{
	std::cout << GREEN << "ShrubberyCreationForm target \'" << target << "\' default constructor called (gradeToSign: \'" << getGradeToSign() << "\' & gradeToExecute: \'" << getGradeToExecute() << "\')" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target)
: AForm("ShrubberyCreationForm", 145, 137), target(resolveName(_target))
{
	std::cout << GREEN << "ShrubberyCreationForm target \'" << target << "\' constructor called (gradeToSign: \'" << getGradeToSign() << "\' & gradeToExecute: \'" << getGradeToExecute() << "\')" << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "ShrubberyCreationForm target \'" << target << "\' destructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(other), target(other.target)
{
	std::cout << BLUE << "ShrubberyCreationForm copy constructor called" << RESET << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << BLUE << "ShrubberyCreationForm copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

const std::string	ShrubberyCreationForm::getTarget() const
{
	return (target);
}

void	ShrubberyCreationForm::executeAction(Bureaucrat const & executor) const
{
	std::ofstream	outfile;
	std::string		outfilename = target + "_shrubbery";

	std::cout << "Bureaucrat " << executor.getName() << " will now try to draw an ASCII tree!" << std::endl;
	outfile.open(outfilename);
	if (!outfile.is_open())
		throw std::runtime_error("Could not open file \"" + outfilename + "\"");

	outfile << "       ccee88oo\n" << std::endl
			<< "    C8O8O8Q8PoOb o8oo\n" << std::endl
			<< "  dOB69QO8PdUOpugoO9bD\n" << std::endl
			<< "CgggbU8OU qOp qOdoUOdcb\n" << std::endl
			<< "    6OuU  /p u gcoUodpP\n" << std::endl
			<< "      \\\\//  /douUP\n" << std::endl
			<< "        \\\\////\n" << std::endl
			<< "         |||/\\\n" << std::endl
			<< "         |||\\/\n" << std::endl
			<< "         |||||\n" << std::endl
			<< "   .....//||||\\....\n" << std::endl;

	outfile.close();
	std::cout << "Bureaucrat " << executor.getName() << " mission is successful!" << std::endl;
}

std::ostream&	operator<<(std::ostream& out, const ShrubberyCreationForm& shrubberyCreationForm)
{
	out << static_cast<const AForm&>(shrubberyCreationForm);
	out << ", target: " << shrubberyCreationForm.getTarget();
	return (out);
}
