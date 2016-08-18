/*
 * commandHandler.hpp
 *
 *  Created on: Aug 14, 2016
 *      Author: je
 */

#ifndef SRC_COMMANDHANDLER_HPP_
#define SRC_COMMANDHANDLER_HPP_

#include <map>
#include <functional>
#include "item.hpp"
#include "eagle.hpp"
#include "squirrel.hpp"
#include "environment.hpp"
#include "logisticManager.hpp"

namespace sgame {

//typedef void (CommandHandler::*cmd_pointer)(std::string &);

class CommandHandler {

private:

	//Characters
	std::map<std::string,Eagle*>::iterator itEagles;
	std::map<std::string, Eagle*> eagleMap;
	Squirrel player;

	//Logistic Manager & environments
	LogisticManager logManager;
	std::map<std::string,Environment*>::iterator itEnvironments;
	std::map<std::string, Environment*> environmentMap;

	bool isRunning = true;
	int totalNumberOfNuts;

	void print_intro();
	void write_output();
	void look();
	void read_input();
	void init_actorMap();
	void init_environments();
	void other_characters_action();
	void eagles_action();

public:
	CommandHandler();
	CommandHandler(CommandHandler & ref);
	virtual ~CommandHandler();

	static std::string environmentNames[3];

	void run();

	CommandHandler& operator=(const CommandHandler& ref);

};

}

#endif /* SRC_COMMANDHANDLER_HPP_ */
