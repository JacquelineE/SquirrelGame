/*
 * OakForest.cpp
 *
 *  Created on: Aug 16, 2016
 *      Author: je
 */

#include "oakForest.hpp"

namespace sgame {

OakForest::OakForest() {
	locationName = "defaultOakForest";
	acorn = 5;
}

OakForest::OakForest(std::string locName) : Forest(locName) { //set locname
	//acorn = 5;
}

OakForest::~OakForest() {
	// TODO Auto-generated destructor stub
}

void OakForest::pick_nut() {
	acorn--;
}

}
