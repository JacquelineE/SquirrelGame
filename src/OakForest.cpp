/*
 * OakForest.cpp
 *
 *  Created on: Aug 16, 2016
 *      Author: je
 */

#include "oakForest.hpp"

OakForest::OakForest() {
	locationName = "OakForest";
	acorn = 10;

}

OakForest::~OakForest() {
	// TODO Auto-generated destructor stub
}

void OakForest::pick_nut() {
	acorn--;
}


