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
#include <memory>
#include "environment.hpp"
#include "eagle.hpp"

namespace sgame {

class LogisticManager {

private:
	void init_environments();
public:
	LogisticManager();
	LogisticManager(LogisticManager & ref);
	virtual ~LogisticManager();
	std::string currEnvironment;

	void look(std::map<std::string, Environment*> & environmentMap);
	void changeGameLocation(std::string const location);

};

}

#endif /* LOGISTICMANAGER_HPP_ */
