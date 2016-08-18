/*
 * Eagle.cpp
 *
 *  Created on: Aug 14, 2016
 *      Author: je
 */

#include "eagle.hpp"
#include "commandHandler.hpp"
#include <cstdlib>
#include <iostream>

namespace sgame {

Eagle::Eagle() {
	nickName = "DefaultEagle";
}

Eagle::Eagle(std::string name, std::string startLocation) {
	nickName = name;
	location = startLocation;
	health = 5;
	startHealth = health;
}

Eagle::Eagle(Eagle const & ref) : Character(ref){ }

Eagle::~Eagle() {
	// TODO Auto-generated destructor stub
}

std::string Eagle::name() const {
	return nickName;
}

void Eagle::type() const {
	std::cout << "eagle" << std::endl;
}

void Eagle::action(std::string location, int moveOptions) {
	int option = (rand() % moveOptions); //0-(loc-1)
	this->location = CommandHandler::environmentNames[option];
}

int Eagle::strength() {
	if (health == startHealth) {
		return 2;
	} else {
		return 1;
	}
}

}
