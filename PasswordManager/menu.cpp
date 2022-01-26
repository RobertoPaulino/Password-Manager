#include "PasswordGenerator.h"
#include "menu.h"



 menu::menu() : passGen(nullptr)
{
	 
}

void menu::mainMenu()
{
	
	PasswordGenerator* passGen = new PasswordGenerator;
	int menuChoice = 0;
	functions functions;

	while (menuChoice < 1 || menuChoice > 4) {	

		functions.Clear();
		std::cout << "------------------------ Main Menu ------------------------" << std::endl << std::endl;
		std::cout << "Options:" << std::endl;
		std::cout << "1. Add a password\n";
		std::cout << "2. Search an specific password\n";
		std::cout << "3. Show all passwords\n";
		std::cout << "4. Close program\n";


		std::cin >> menuChoice;
		
	}


	switch (menuChoice) {
	case 1:
		passGen->addPassword();
		break;
	case 2:
		passGen->searchPassword();
		break;
	case 3:
		passGen->printAllPasswords();
		break;
	case 4:
		exit(0);
		break;
	}

}

