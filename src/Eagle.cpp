/*
 * Eagle.cpp
 *
 *  Created on: Aug 14, 2016
 *      Author: je
 */

#include "eagle.hpp"
#include <iostream>

namespace sgame {

Eagle::Eagle() {
	//vector with items
	nickName = "Default Eagle";

}

Eagle::Eagle(std::string name) {
	//vector with items
	nickName = name;

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

void Eagle::action() {
	std:: cout << "action" << std::endl;
}

}
