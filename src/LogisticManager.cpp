/*
 * LogisticManager.cpp
 *
 *  Created on: Aug 15, 2016
 *      Author: je
 */

#include "logisticManager.hpp"
#include "oakForest.hpp"
#include <iostream>

namespace sgame {

LogisticManager::LogisticManager() {
	init_environments();
}

LogisticManager::LogisticManager(LogisticManager & ref) {
	std::cout << "copy logmanager" << std::endl;
//	for(std::map<std::string, Environment*>::iterator itr = ref.environmentMap.begin(); itr != ref.environmentMap.end(); itr++) {
//		//Environment e = *(itr->second); //kopiera ny miljö
//		this->environmentMap[itr->first] = Environment(*(itr->second));
//	}
	this->currEnvironment = ref.currEnvironment;
	this->environmentMap = ref.environmentMap;
}

LogisticManager::~LogisticManager() {
//	std::cout << "LOG DESTRUCT" << std::endl;
//	for(std::map<std::string, Environment*>::iterator itr = environmentMap.begin(); itr != environmentMap.end(); itr++) {
//		delete itr->second;
//	} COULD WORK ANYWAY?
}

void LogisticManager::init_environments() { //bygg spelplanen
	std::string start = "OakForest1";
	Environment * oak = new OakForest(start);
	environmentMap[oak->location()] = oak;
	this->currEnvironment = start;
	delete oak;
}

}
