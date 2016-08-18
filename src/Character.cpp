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
	health = 5;
	startHealth = health;
}

Character::~Character() {}

void Character::set_health(int diff) {
	health+=diff;
}

int Character::get_health() const {
	return health;
}

void Character::attack(Character & character) {
	character.set_health(-1);
}

std::string Character::characterLocation() const {
	return location;
}

}
