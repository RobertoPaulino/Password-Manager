#pragma once
#ifndef PasswordGenerator_h
#define PasswordGenerator_h
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include "functions.h"
#include "charArrays.h"

class menu;

class PasswordGenerator {

public:

	
	PasswordGenerator();
	menu* menuPtr;
	functions functions;


	std::string randomPasswordGenerator();
	std::string passwordStringCreator();
	std::string passwordGenerator(int passwordLenght, bool caps, bool special, bool nums);

	void printAllPasswords();
	void addPassword();
	void searchPassword();

private:

	char randomCapletter();
	char randomletter();
	char randomNum();
	char randomSpecial();

};

#endif