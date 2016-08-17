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
#include "character.hpp"
#include "squirrel.hpp"
#include "environment.hpp"
#include "logisticManager.hpp"

namespace sgame {

//typedef void (CommandHandler::*cmd_pointer)(std::string &);

class CommandHandler {

private:

	//Characters & Items
	std::map<std::string,Character*>::iterator itActors;
	std::map<std::string,Item*>::iterator itItems; //TODO flytta items till environment?
	Squirrel player;
	std::map<std::string, Character*> actorMap;
	std::map<std::string, Item*> itemMap;

	//Logistic Manager & environments
	LogisticManager logManager;
	std::map<std::string, Environment*> environmentMap;

	bool isRunning = true;

	void print_intro();
	void write_output();
	void read_input();
	void init_actorMap();
	void init_environments();

public:
	CommandHandler();
	CommandHandler(CommandHandler & ref);
	virtual ~CommandHandler();
	void run();

	CommandHandler& operator=(const CommandHandler& ref);

};

}

#endif /* SRC_COMMANDHANDLER_HPP_ */
