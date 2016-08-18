/*
 * OakForest.cpp
 *
 *  Created on: Aug 16, 2016
 *      Author: je
 */

#include "oakForest.hpp"
#include "nut.hpp"
#include <iostream>
using namespace std;

namespace sgame {

OakForest::OakForest() {
	locationName = "defaultOakForest";
}

OakForest::OakForest(std::string locName) { //set locname
	this->locationName = locName;
	this->place_items();
}

OakForest::~OakForest() {
	for(std::vector<Item*>::iterator itr = items.begin(); itr != items.end(); itr++) {
		delete (*itr);
	}
}

void OakForest::pick_nut() {
	acorn--;
}

void OakForest::place_items() {
	//	Nut n;
	//	items.push_back(n);
	this->items.push_back(new Nut());
	this->items.push_back(new Nut());
}

}
