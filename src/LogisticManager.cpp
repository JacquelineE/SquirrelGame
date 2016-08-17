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
	std::cout << "copy logmanager" << std::endl;
	this->currEnvironment = ref.currEnvironment;
}

LogisticManager::~LogisticManager() {
}

}
