/*
 * logisticManager.hpp
 *
 *  Created on: Aug 15, 2016
 *      Author: je
 */

#ifndef LOGISTICMANAGER_HPP_
#define LOGISTICMANAGER_HPP_

#include <map>
#include <string>
#include "environment.hpp"
class LogisticManager {

private:
	void init_environments();
public:
	LogisticManager();
	virtual ~LogisticManager();
	std::string currEnvironment;
	std::map<std::string, Environment *> environmentMap;

};

#endif /* LOGISTICMANAGER_HPP_ */
