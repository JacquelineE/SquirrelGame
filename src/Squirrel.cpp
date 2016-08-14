/*
 * Squirrel.cpp
 *
 *  Created on: Aug 14, 2016
 *      Author: je
 */

#include "squirrel.hpp"
#include <iostream>

Squirrel::Squirrel() {
	nickName = "Kurre";
	nuts = 0;

}

Squirrel::~Squirrel() {
	// TODO Auto-generated destructor stub
}

void Squirrel::type() const {
	std::cout << "squirrel" << std::endl;
}

void Squirrel::action() {
	std:: cout << "action" << std::endl;
}


void Squirrel::pick(Item & item) {
	bag[item.get_name()]++;

}

void Squirrel::change_nr_nuts(int n) {
	nuts +=n;
}

void Squirrel::print_bag() {
	for (bagIterator = bag.begin(); bagIterator != bag.end(); bagIterator++) {
	    std::cout << "Item: " << bagIterator->first << " Quantity:" << bagIterator ->second << std::endl;
	}
}
