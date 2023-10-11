#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("altpapier",145,137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name): AForm(name, 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &src) : AForm(src.getName(), 145, 137)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::Purpose(std::string target) {
	std::ofstream OFile;
	target = target+"_shrubbery";
	OFile.open(target.c_str());
	srand((unsigned int)std::time(NULL));
	int a = std::rand() % 7;
	switch(a) {
		default:{
			OFile << "       $" << std::endl;
			OFile << "      $$$" << std::endl;
			OFile << "     $$$$$" << std::endl;
			OFile << "       |" << std::endl;
			break;
		}
		case 0: {
			OFile << "       ^       ^       ^       ^" << std::endl;
			OFile << "      ^^^     ^^^     ^^^     ^^^" << std::endl;
			OFile << "     ^^^^^   ^^^^^   ^^^^^   ^^^^^" << std::endl;
			OFile << "       |       |       |       |" << std::endl;
			break;
		}
		case 1: {
			OFile << "       ^" << std::endl;
			OFile << "      ^^^" << std::endl;
			OFile << "     ^^^^^" << std::endl;
			OFile << "       |" << std::endl;
			break;
		}
		case 2: {
			OFile << "      ^^^" << std::endl;
			OFile << "     ^^^^^" << std::endl;
			OFile << "    ^^^^^^^" << std::endl;
			OFile << "   ^^^^^^^^^" << std::endl;
			OFile << "       ||" << std::endl;
			break;
		}
		case 3: {
			OFile << "       ^" << std::endl;
			OFile << "      ^^^" << std::endl;
			OFile << "     ^^^^^" << std::endl;
			OFile << "    ^^^^^^^" << std::endl;
			OFile << "   ^^^^^^^^^" << std::endl;
			OFile << "  ^^^^^^^^^^^" << std::endl;
			OFile << " ^^^^^^^^^^^^^" << std::endl;
			OFile << "^^^^^^^^^^^^^^^" << std::endl;
			OFile << "     |||||" << std::endl;
			break;
		}
		case 4: {
			OFile << "       ^" << std::endl;
			OFile << "      ^^^" << std::endl;
			OFile << "     ^^^^^" << std::endl;
			OFile << "    ^^^^^^^" << std::endl;
			OFile << "   ^^^^^^^^^          ^" << std::endl;
			OFile << "  ^^^^^^^^^^^        ^^^" << std::endl;
			OFile << " ^^^^^^^^^^^^^      ^^^^^" << std::endl;
			OFile << "^^^^^^^^^^^^^^^    ^^^^^^^" << std::endl;
			OFile << "     |||||           |||" << std::endl;
			break;
		}
		case 5: {
			OFile << "                ^^" << std::endl;
			OFile << "               ^^^^             @" << std::endl;
			OFile << "       ^      ^^^^^^      *    @@@" << std::endl;
			OFile << "      ^^^   4^^^^^^^^    ***  @@@@@" << std::endl;
			OFile << "     ^^^^^ 444^^^^^^^^  *****@@@@@#%%%#" << std::endl;
			OFile << "    ^^^^^^44444^^^^^^^^*******@@@#%%%%%#" << std::endl;
			OFile << "   ^^^^^^4444444^^^^^^*********@@@#%%%#" << std::endl;
			OFile << "      |||   |   |||      |||    |   |" << std::endl;
			break;
		}
	}
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm src) {
	if(this != &src)
		AForm::operator=(src);
	return (*this);
}
