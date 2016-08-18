/*
 * Squirrel.cpp
 *
 *  Created on: Aug 14, 2016
 *      Author: je
 */

#include "squirrel.hpp"
#include <iostream>

namespace sgame {

Squirrel::Squirrel() {
	this->nickName = "Kurre";
	nuts = 0;
	location = "here";
	std::cout << nickName << " has health " << health << std::endl;
}

Squirrel::~Squirrel() { }

std::string Squirrel::name() const {
	return nickName;
}

void Squirrel::type() const {
	std::cout << "squirrel" << std::endl;
}

void Squirrel::action(std::string location, int locationCount) {
	std:: cout << "action" << std::endl;
}


void Squirrel::pick(std::string itemName) {
	this->bag[itemName]++;
	if (itemName.compare("nut") == 0) {
		this->nuts++;
	}
}

void Squirrel::change_nr_nuts(int n) {
	this->bag["nut"] +=n;
	this->nuts +=n;
}

int Squirrel::nr_of_nuts() const {
	return nuts;
}

void Squirrel::print_bag() {
	std::cout << "YOUR BAG CONTENT: " << std::endl;
	for (bagIterator = bag.begin(); bagIterator != bag.end(); bagIterator++) {
		std::cout << "Item: " << bagIterator->first << " Quantity:" << bagIterator ->second << std::endl;
	}
}

void Squirrel::move(std::string locationName) {
	this->location = locationName;
}

int Squirrel::strength() {
	int strength = 1;
	if (health == startHealth) {
		strength++;
	}
	std::map<std::string,int>::iterator iter = bag.find("slingshot");
	if (iter != bag.end()) {
		strength++;
	}
	return strength;
	}

}
