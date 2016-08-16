/*
 * LogisticManager.cpp
 *
 *  Created on: Aug 15, 2016
 *      Author: je
 */

#include "logisticManager.hpp"
#include "forest.hpp"

LogisticManager::LogisticManager() {
	init_environments();

}

LogisticManager::~LogisticManager() {
	// TODO Auto-generated destructor stub
}

void LogisticManager::init_environments() {
	Forest * forestPtr = new Forest();
	environmentMap[forestPtr -> location()] = forestPtr;
}
