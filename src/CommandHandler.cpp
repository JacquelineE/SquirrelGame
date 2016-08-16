/*
 * CommandHandler.cpp
 *
 *  Created on: Aug 14, 2016
 *      Author: je
 */

#include "commandHandler.hpp"
#include "eagle.hpp"

#include <iostream>
#include <sstream>

CommandHandler::CommandHandler() {
	player = new Squirrel();
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

	if(cmd.compare("attack") == 0) {
		std::cout << "attacked" << msg << std::endl;
		itActors = actorMap.find(msg);
		if(itActors != actorMap.end()) {
			(itActors -> second)->set_health(-1);
			player->change_nr_nuts(-1);
		} else {
			std::cout << "You better save your nuts for real enemies" << std::endl;
		}
	} else if(cmd.compare("pick") == 0) {
		std::cout << "will pick" << msg << std::endl;
			itItems = itemMap.find(msg);

			if(itItems != itemMap.end()) {
			player -> pick((*(itItems -> second)));
			} else {
				std::cout << "Try pick something else!" << std::endl;
			}
	} else if(cmd.compare("bag") == 0){
		player->print_bag();
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

void CommandHandler::init_actorMap() {
	actorMap["eagle"] = new Eagle();
}



