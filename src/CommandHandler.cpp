/*
 * CommandHandler.cpp
 *
 *  Created on: Aug 14, 2016
 *      Author: je
 */

#include "commandHandler.hpp"
#include "eagle.hpp"
#include "squirrel.hpp"
#include "oakForest.hpp"
#include "pineForest.hpp"
#include <iostream>
#include <sstream>
#include <typeinfo>

namespace sgame {

CommandHandler::CommandHandler() {
	this->player = Squirrel();
	this->totalNumberOfNuts = 0;
	this->logManager = LogisticManager(); //now the commandHandler can know the state of the game
	init_environments();
	init_actorMap();
}

CommandHandler::CommandHandler(CommandHandler & ref) { //TODO MOVE!?
	this->eagleMap = ref.eagleMap;
	this->isRunning = ref.isRunning;
	this->itEagles = ref.itEagles;
	this->logManager = ref.logManager;
	this->player = ref.player;
}

CommandHandler::~CommandHandler() {
	std::cout << "LOG DESTRUCT" << std::endl;
	for(std::map<std::string, Environment*>::iterator itr = environmentMap.begin(); itr != environmentMap.end(); itr++) {
		delete itr->second;
	}
	std::cout << "CMD DESTRUCT" << std::endl;
	for(std::map<std::string, Eagle*>::iterator itr = eagleMap.begin(); itr != eagleMap.end(); itr++) {
		delete itr->second;
	}
}

CommandHandler& CommandHandler::operator=(const CommandHandler& ref) { //TODO MOVE!?
	this->eagleMap = ref.eagleMap;
	this->isRunning = ref.isRunning;
	this->itEagles = ref.itEagles;
	this->logManager = ref.logManager;
	this->player = ref.player;
	return *this;
}

void CommandHandler::write_output() {
	for(std::map<std::string, Eagle*>::iterator itr = eagleMap.begin(); itr != eagleMap.end(); itr++) {
		if (itr->second->characterLocation().compare(logManager.currEnvironment) == 0) {
			std::cout << "You see " << itr->second->name() << " in " << itr->second->characterLocation() << std::endl;
		}
	}

	logManager.look(environmentMap);
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
		std::cout << "You attacked " << msg << std::endl;
		itEagles = eagleMap.find(msg);
		if (player.nr_of_nuts() < 1) {
			std::cout << "You don't have nuts." << std::endl;
		}
		else if (itEagles != eagleMap.end()) {
			player.change_nr_nuts(-1);
			if (itEagles->second->characterLocation().compare(logManager.currEnvironment) == 0) {
				(itEagles -> second)->set_health(-(player.strength()));
				if (itEagles->second->get_health() < 1) {
					delete (itEagles->second);
					eagleMap.erase(itEagles);
					std::cout << "You defeated " << msg << std::endl;
				} else {
					std::cout << msg << " got health " << itEagles->second->get_health() << std::endl;
				}
			} else {
				std::cout << msg << "is not here!" << std::endl;
			}
		} else {
			player.change_nr_nuts(-1);
			std::cout << "You better save your nuts for real enemies" << std::endl;
		}
	} else if(cmd.compare("pick") == 0) {
		std::cout << "will pick" << msg << std::endl;
		itEnvironments = environmentMap.find(logManager.currEnvironment);
		if (itEnvironments != environmentMap.end()) {
			//try to remove item from environment
			if ((itEnvironments->second)->try_pick_item(msg)) {
				player.pick(msg);
				if (msg.compare("nut") == 0) {
					this->totalNumberOfNuts--;
				}
			} else {
				std::cout << "Try pick something else!" << std::endl;
			}
		}
	} else if(cmd.compare("bag") == 0){
		player.print_bag();
	}
	else if(cmd.compare("go") == 0){
		itEnvironments = environmentMap.find(msg);
		if (itEnvironments != environmentMap.end()) {
			logManager.changeGameLocation(msg);
			player.move(msg);
		} else {
			std::cout << "Where the hell is that?" << std::endl;
		}
	}else {
		std::cout <<"You better try a valid command" << std::endl;
	}

}

void CommandHandler::run() {
	print_intro();

	while(isRunning) {
		write_output();
		read_input();
		if (0 == totalNumberOfNuts) {
			std::cout << "YOU WON WITH " << player.nr_of_nuts() << " NUTS!" << std::endl;
			isRunning = false;
		}

		if (isRunning) {
			other_characters_action();

			if (player.get_health() < 1) {
				std::cout << "Oh no you died! GAME OVER" << std::endl;
				isRunning = false;
			}
		}
	}
}

void CommandHandler::other_characters_action() {
	eagles_action();
}

void CommandHandler::eagles_action() {
	for(std::map<std::string, Eagle*>::iterator itr = eagleMap.begin(); itr != eagleMap.end(); itr++) {
		if (itr->second->characterLocation().compare(logManager.currEnvironment) == 0) {
			int option = (rand() % 2); //0-(loc-1)
			if (option == 0) {
				player.set_health(-(itr->second->strength()));
				std::cout << itr->second->name() << " attacked you! Health is now " << player.get_health() << std::endl;
				return;
			}
		}
		itr->second->action(logManager.currEnvironment, environmentMap.size());
	}
}

void CommandHandler::print_intro() {
	std::cout << "Welcome to decisio game, your choices will count!" << std::endl;
	std::cout << "You must be the squirrel " << player.name() << "! Winter is coming..." << std::endl;
	std::cout << "collect all the nuts to be prepared! But beware of the dangerous predators..." << std::endl;
	std::cout << "Pick up items with: pick <item>" << std::endl;
	std::cout << "See what's in you bag: bag" << std::endl;
	std::cout << "Attack others with: attack <name>" << std::endl;
	std::cout << "Go to another part of the forest: go <location>" << std::endl << std::endl;
}

void CommandHandler::init_actorMap() {
	this->eagleMap["Mr.Eagle"] = new Eagle("Mr.Eagle", "PineForest1");
	this->eagleMap["Eagleius"] = new Eagle("Eagleius", "OakForest2");
}

std::string CommandHandler::environmentNames[4] = {"OakForest1", "PineForest1", "OakForest2", "PineForest2"};

void CommandHandler::init_environments() { //bygg spelplanen med environment object
	std::string start = environmentNames[0];
	this->environmentMap[start] = new OakForest(start);
	this->logManager.currEnvironment = start;
	Environment * env2 = new PineForest(environmentNames[1]);
	environmentMap[env2->location()] = env2;
	Environment * env3 = new OakForest(environmentNames[2]);
	environmentMap[env3->location()] = env3;
	Environment * env4 = new PineForest(environmentNames[3]);
	environmentMap[env4->location()] = env4;

	for(std::map<std::string, Environment*>::iterator itr = environmentMap.begin(); itr != environmentMap.end(); itr++) {
		this->totalNumberOfNuts += itr->second->get_number_of_nuts();
	}
	std::cout << "Total number of nuts: " << totalNumberOfNuts << std::endl;
}


}
