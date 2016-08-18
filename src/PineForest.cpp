/*
 * PineForest.cpp
 *
 *  Created on: Aug 16, 2016
 *      Author: je
 */

#include "pineForest.hpp"
#include "nut.hpp"
#include "slingshot.hpp"
#include <iostream>

using namespace std;

namespace sgame {

PineForest::PineForest() {
	locationName = "defaultPineForest";
	cones = 2;
}

PineForest::PineForest(std::string locName) { //set locname
	this->locationName = locName;
	place_items();
}

PineForest::~PineForest() {
	for(std::vector<Item*>::iterator itr = items.begin(); itr != items.end(); itr++) {
		delete (*itr);
	}
}

void PineForest::pick_nut() {
	cones--;
}

void PineForest::place_items() {
	items.push_back(new Nut());
	items.push_back(new Slingshot());
}

std::string PineForest::get_description() const {
	return "Ah, the pine forest is green during the winter, maybe I should CHILL here then..";
}

}
