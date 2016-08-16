/*
 * LogisticManager.cpp
 *
 *  Created on: Aug 15, 2016
 *      Author: je
 */

#include "logisticManager.hpp"
#include "oakForest.hpp"

LogisticManager::LogisticManager() {
	init_environments();

}

LogisticManager::~LogisticManager() {
	// TODO Auto-generated destructor stub
}

void LogisticManager::init_environments() {
	Forest * forestPtr = new OakForest();
	environmentMap[forestPtr -> location()] = forestPtr;
}
