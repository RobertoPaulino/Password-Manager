#pragma once
#ifndef menu_h
#define menu_h
#include <iostream>
#include "functions.h"

class PasswordGenerator;

class menu {

public:
	
	PasswordGenerator* passGen;

	menu();
	void mainMenu();

};

#endif