#include "menu.h"
#include "PasswordGenerator.h"


PasswordGenerator::PasswordGenerator() : menuPtr(nullptr)
{
	menu* menuPtr = new menu;
}

void PasswordGenerator::printAllPasswords()
{
	std::string d;
	std::ifstream PasswordData("PasswordData.txt");

	if (PasswordData.is_open())
		std::cout << PasswordData.rdbuf();

	
	system("pause");

}

std::string PasswordGenerator::randomPasswordGenerator()
{

	int passwordLenght;

	char special;
	char caps;
	char nums;

	bool specialBool;
	bool capsBool;
	bool numsBool;

	std::cout << "enter the lenght of the password (Max 50 characters)" << std::endl;
	do {
		std::cin >> passwordLenght;
		while (std::cin.fail())
		{

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			functions.Clear();
			std::cout << "enter the lenght of the password (Max 50 characters)" << std::endl;
			std::cin >> passwordLenght;

		}
	} while (passwordLenght > 50 || passwordLenght < 1);
	functions.Clear();

	std::cout << "Include special characters? Y/N" << std::endl;
	do {
		std::cin >> special;
	} while ((special != 'Y' ) && ( special != 'N') && (special != 'y') && (special != 'n'));
	functions.Clear();

	std::cout << "Include caps? Y/N" << std::endl;
	do {
		std::cin >> caps;
	} while ((caps != 'Y') && ( caps != 'N') && (caps != 'y') && (caps != 'n'));
	functions.Clear();

	std::cout << "Include numbers? Y/N" << std::endl;
	do {
		std::cin >> nums;
	} while ((nums != 'Y') && (nums != 'N') && (nums != 'y') && (nums != 'n'));
	functions.Clear();

	if (special == 'y' || special == 'Y')
	{ 
		specialBool = true;
	}
	else
	{
		specialBool = false;
	}

	if (caps == 'y' || caps == 'Y')
	{
		capsBool = true;
	}
	else
	{
		capsBool = false;
	}

	if (nums == 'y' || caps == 'Y')
	{
		numsBool = true;
	}
	else
	{
		numsBool = false;
	}

	return passwordGenerator(passwordLenght, capsBool, specialBool, numsBool);

}

std::string PasswordGenerator::passwordStringCreator()
{

	std::string note = "N/A";
	std::string password = "N/A";
	std::string name = "N/A";
	std::string passwordString = "N/A";
	char passwordChoice = '0';
	char noteChoice = '0';

	functions.Clear();

	std::cout << "Do you want to create a random password or do you want to use your own password?\n \n";
	std::cout << "1. Use your own password\n";
	std::cout << "2. Create a random password\n";

	do
	{
		std::cin >> passwordChoice;
	} while (passwordChoice != '1' && passwordChoice != '2');

	if (passwordChoice == '1')
	{
		functions.Clear();
		std::cout << "Please enter the password: \n";
		std::getline(std::cin, password);
		
	}
	else if (passwordChoice == '2')
	{
		functions.Clear();
		
		password = randomPasswordGenerator();
	}
	
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "New password created: \n" << password << "\n \n";
	std::cout << "Please enter the account name: \n";
	std::getline(std::cin, name);

	std::cout << "\nPlease enter a note: \n";
	std::getline(std::cin, note);

	passwordString = "Username: " + name + " | " + "Password: " + password + " | " + "Note: " + note;

	return passwordString;
}



void PasswordGenerator::addPassword()
{

	std::fstream passwordData;
	passwordData.open("PasswordData.txt", std::ios::app);

	if (passwordData.is_open())
	{
		passwordData << passwordStringCreator() << std::endl;
	}

	menuPtr->mainMenu();

}


char PasswordGenerator::randomCapletter()
{

	int randomPos = functions.pickRandom(25);
	char capLetterRandom = lettersCaps[randomPos];
	return capLetterRandom;

}

char PasswordGenerator::randomletter()
{

	int randomPos = functions.pickRandom(25);
	char letterRandom = letter[randomPos];
	return letterRandom;

}

char PasswordGenerator::randomNum()
{

	int randomPos = functions.pickRandom(9);
	char numberRandom = num[randomPos];
	return numberRandom;
}

char PasswordGenerator::randomSpecial()
{

	int randomPos = functions.pickRandom(7);
	char specialRandom = special[randomPos];
	return specialRandom;

}

std::string PasswordGenerator::passwordGenerator(int passwordLenght, bool caps, bool special, bool nums)
{

	char generatedPassword[51] = {0};

	for (unsigned int a = 0; a < passwordLenght; a += 1)
	{
		{
			int charType = functions.pickRandom(3);

			switch (charType) {
				case 0:

					if (caps == true)
					{
						generatedPassword[a] = randomCapletter();
					}
					else
					{
						a--;
					}
					break;
				case 1:

					generatedPassword[a] = randomletter();
					break;
				case 2:

					if (nums == true)
					{
						generatedPassword[a] = randomNum();
					}
					else
					{
						a--;
					}
					break;
				case 3:

					if (special == true)
					{
						generatedPassword[a] = randomSpecial();
					}
					else
					{
						a--;
					}
					break;
			}
		}
	}


	int stringSize = sizeof(generatedPassword) / sizeof(char);

	std::string generatedPasswordString(generatedPassword);

	return generatedPassword;
}

void PasswordGenerator::searchPassword()
{
	functions.Clear();
	std::string passName = " ";
	
	bool passFound = false;
	std::string line;
	std::fstream passwordData;
	passwordData.open("PasswordData.txt", std::ios::in | std::ios::out);
	
	std::cout << "Please enter the name of the password: \n";
	std::cin.ignore();
	std::getline(std::cin, passName);

	if (passwordData.is_open())                               
	{
		while (std::getline(passwordData, line))
		{ 
			if (line.find(passName) != std::string::npos)
			{ 
				if (passFound == false)
				{
					std::cout << "Passwords found: \n" << line << std::endl;
				}
				else
				{
					std::cout << line << std::endl;
				}
				passFound = true;
			}
		}

		if (passFound == false)
			std::cout << "No password found\n \n";
		system("PAUSE");
		menuPtr->mainMenu();
	}
	else
	{
		std::cout << "\nSearch Failed..." << std::endl;
		system("PAUSE");
	}
}