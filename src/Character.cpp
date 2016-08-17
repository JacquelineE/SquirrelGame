/*
 * Character.cpp
 *
 *  Created on: 12 aug. 2016
 *      Author: Mitra and Jacqueline
 */

#include "character.hpp"
#include <iostream>

namespace sgame {

Character::Character() {
	std::cout << "abstract constructor" << std::endl;
	age = 5;
	health = 10;
	hasTreasure = false;
}

Character::~Character() {}

void Character::set_health(int diff) {
	health+=diff;
}

int Character::get_health() const {
	return health;
}

void attack(Character & character) {
	character.set_health(-1);
}

}
