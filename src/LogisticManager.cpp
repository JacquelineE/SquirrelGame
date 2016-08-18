/*
 * LogisticManager.cpp
 *
 *  Created on: Aug 15, 2016
 *      Author: je
 */

#include "logisticManager.hpp"
#include <iostream>

namespace sgame {

LogisticManager::LogisticManager() { }

LogisticManager::LogisticManager(LogisticManager & ref) {
	this->currEnvironment = ref.currEnvironment;
}

//var är spelet?
void LogisticManager::look(std::map<std::string, Environment*> & environmentMap) { //cant be const?
	std::cout << "You are in " << currEnvironment << "." << std::endl;
	std::map<std::string,Environment*>::iterator iter = environmentMap.find(currEnvironment);
	if (iter != environmentMap.end()) {
		iter->second->desc();
	}

	//look for items in current environment
	iter = environmentMap.find(currEnvironment);
	if(iter != environmentMap.end()) {
		(iter -> second)->print_items();
	}
	std::cout << std::endl;

	//look where to go
	std::cout << "Where do you want to go?";
	for(std::map<std::string, Environment*>::iterator itr = environmentMap.begin(); itr != environmentMap.end(); itr++) {
		if(itr->first.compare(currEnvironment) != 0) {
			std::cout << " " << itr->second->location();
		}
	}
	std::cout << std::endl;
}

void LogisticManager::changeGameLocation(std::string const location) {
	this->currEnvironment = location;
}

LogisticManager::~LogisticManager() {
}

}
