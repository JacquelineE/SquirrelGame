/*
 * CommandHandler.cpp
 *
 *  Created on: Aug 14, 2016
 *      Author: je
 */

#include "commandHandler.hpp"
#include "eagle.hpp"
#include "nut.hpp"
#include "slingshot.hpp"

#include <iostream>
#include <sstream>

CommandHandler::CommandHandler() {
	player = new Squirrel();
	init_commandMap();
	init_actorMap();

	// TODO Auto-generated constructor stub

}

CommandHandler::~CommandHandler() {
	// TODO Auto-generated destructor stub
}


void CommandHandler::write_output() {
	std::cout  << "Be wise " << std::endl;
	std::cout << " \n >";
}


void CommandHandler::read_input() {
	std::string input;
	getline(std::cin, input);
	std::string cmd = "";
	std::string msg = "";
	std::stringstream ss(input);
	ss >> cmd;
	ss >> msg;

	itCmdPtr = commandMap.find(cmd);

	if(itCmdPtr != commandMap.end()) {
		cmd_pointer mp2 = commandMap.find(cmd) -> second;
		((*this).*mp2)(msg);
	} else {
		std::cout <<"You better try a valid command" << std::endl;
	}

}

void CommandHandler::run() {
	print_intro();

	while(isRunning) {
		write_output();
		read_input();
	}
}

void CommandHandler::print_intro() {
	std::cout << "Decisio game, your choices will count!" << std::endl;
}


void CommandHandler::attack_cmd(std::string & enemy) {
	//TODO if someone dies--> remember to remove that obj!!! both from map but also from memory
	std::cout << "attacked" << enemy << std::endl;
	itActors = actorMap.find(enemy);
	if(itActors != actorMap.end()) {
		(itActors -> second)->set_health(-1);
		player->change_nr_nuts(-1);
	} else {
		std::cout << "You better save your nuts for real enemies" << std::endl;
	}

}

void CommandHandler::pick_cmd(std::string & item) {
	std::cout << "will pick" << item << std::endl;
	itItems = itemMap.find(item);

	if(itItems != itemMap.end()) {
	player -> pick((*(itItems -> second)));
	} else {
		std::cout << "Try pick something else!" << std::endl;
	}

}

void CommandHandler::init_commandMap() {
	//using member function pointers
	//void(Controller::*mp)(std::istream &);
	//cmd_pointer mp =
	commandMap["attack"] = &CommandHandler::attack_cmd;
	commandMap["tick"] = &CommandHandler::pick_cmd;
	commandMap["bag"] = &CommandHandler::show_bag_cmd;

	//void(Character::*mp2)();
	//((*player).*mp2)();

	//void(Character::*mp)() const;
	//((*player).*mp)();


}


void CommandHandler::show_bag_cmd(std::string & str) {
	player->print_bag();
}


void CommandHandler::init_itemMap() {
	itemMap["nut"] = new Nut();
	itemMap["slingshot"] = new Slingshot();
}

void CommandHandler::init_actorMap() {
	actorMap["eagle"] = new Eagle();
}



