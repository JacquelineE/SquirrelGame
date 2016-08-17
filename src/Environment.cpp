/*
 * Environment.cpp
 *
 *  Created on: Aug 15, 2016
 *      Author: je
 */

#include "environment.hpp"

namespace sgame {

Environment::Environment() {

}

Environment::Environment(std::string locName) {
	this->locationName = locName;
}

Environment::~Environment() {
	// TODO Auto-generated destructor stub
}

std::string Environment::location() const {
	return locationName;
}

}
