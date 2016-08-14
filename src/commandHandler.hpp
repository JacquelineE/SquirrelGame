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
#include "classes.h"
#include "squirrel.hpp"

typedef void (CommandHandler::*cmd_pointer)(std::string &);

class CommandHandler {

private:

	std::map<std::string,cmd_pointer>::iterator itCmdPtr;
	std::map<std::string,Character*>::iterator itActors;
	std::map<std::string,Item*>::iterator itItems;

	Squirrel * player;

	std::map<std::string, cmd_pointer> commandMap;
	//std::map<std::string, std::function<void(Controller&)>> commandMap;
	std::map<std::string, Character*> actorMap;
	std::map<std::string, Item*> itemMap;

	bool isRunning = true;

	void print_intro();
	void write_output();
	void read_input();
	void init_commandMap();
	void init_actorMap();
	void attack_cmd(std::string &);

public:
	CommandHandler();
	virtual ~CommandHandler();
	void run();

};

#endif /* SRC_COMMANDHANDLER_HPP_ */
