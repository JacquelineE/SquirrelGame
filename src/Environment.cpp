/*
 * Environment.cpp
 *
 *  Created on: Aug 15, 2016
 *      Author: je
 */

#include "environment.hpp"
#include <iostream>

using namespace std;

namespace sgame {

Environment::Environment() {

}

Environment::Environment(std::string locName) {
	this->locationName = locName;
}

Environment::~Environment() {
	cout << "ENV DESTRUCT" << endl;
}

std::string Environment::location() const {
	return locationName;
}

//loop & print available items
void Environment::print_items() {
	cout << "Here is";
	int nutCount = 0;
	int slingshotCount = 0;
	vector<Item*>::iterator iter;
	for(iter = items.begin(); iter != items.end(); iter++) {
		if((*iter)->get_name().compare("nut") == 0) {
			++nutCount;
		}
		else if ((*iter)->get_name().compare("slingshot") == 0){
			++slingshotCount;
		}
	}
	if((nutCount > 0) || (slingshotCount > 0)) {
		cout << " " << nutCount << " nuts and " << slingshotCount << " slingshots.";
	}
}

}
