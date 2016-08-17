/*
 * PineForest.cpp
 *
 *  Created on: Aug 16, 2016
 *      Author: je
 */

#include "pineForest.hpp"

namespace sgame {

PineForest::PineForest() {
	locationName = "defaultPineForest";
	cones = 2;
}

PineForest::PineForest(std::string locName) : Forest(locName) { //set locname
	//acorn = 5;
}

PineForest::~PineForest() {
	// TODO Auto-generated destructor stub
}

void PineForest::pick_nut() {
	cones--;
}

}
