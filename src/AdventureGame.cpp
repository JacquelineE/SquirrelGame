//============================================================================
// Name        : AdventureGame.cpp
// Author      : Jacqueline and Mitra
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "commandHandler.hpp"
using namespace std;

int main() {


	CommandHandler * cmd = new CommandHandler();
	cmd->run();
	return 0;
}
