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

namespace sgame {

CommandHandler::CommandHandler() {
	this->player = Squirrel();
	this->logManager = LogisticManager(); //now the commandHandler can know the tate of the game
	init_environments();
	std::cout << environmentMap.find(logManager.currEnvironment)->second->location() << std::endl;
	init_actorMap();
	std::cout << actorMap.find("Mr. Eagle")->second->name() << std::endl;
}

CommandHandler::CommandHandler(CommandHandler & ref) { //TODO MOVE!?
	this->actorMap = ref.actorMap;
	this->isRunning = ref.isRunning;
	this->itActors = ref.itActors;
	this->itItems = ref.itItems; //TODO flytta items till environment?
	this->itemMap = ref.itemMap;
	this->logManager = ref.logManager;
	this->player = ref.player;
}

CommandHandler::~CommandHandler() {
	std::cout << "LOG DESTRUCT" << std::endl;
	for(std::map<std::string, Environment*>::iterator itr = environmentMap.begin(); itr != environmentMap.end(); itr++) {
		delete itr->second;
	}
	std::cout << "CMD DESTRUCT" << std::endl;
	for(std::map<std::string, Character*>::iterator itr = actorMap.begin(); itr != actorMap.end(); itr++) {
		delete itr->second;
	}
	for(std::map<std::string, Item*>::iterator itr = itemMap.begin(); itr != itemMap.end(); itr++) {
		delete itr->second;
	}
}

CommandHandler& CommandHandler::operator=(const CommandHandler& ref) { //TODO MOVE!?
	std::cerr << "copy =" << std::endl;
	this->actorMap = ref.actorMap;
	this->isRunning = ref.isRunning;
	this->itActors = ref.itActors;
	this->itItems = ref.itItems; //TODO flytta items till environment?
	this->itemMap = ref.itemMap;
	this->logManager = ref.logManager;
	this->player = ref.player;
	return *this;
}

void CommandHandler::write_output() {
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
		itActors = actorMap.find(msg);
		if(itActors != actorMap.end()) {
			(itActors -> second)->set_health(-1);
			player.change_nr_nuts(-1);
		} else {
			std::cout << "You better save your nuts for real enemies" << std::endl;
		}
	} else if(cmd.compare("pick") == 0) {
		std::cout << "will pick" << msg << std::endl;
		itItems = itemMap.find(msg);

		if(itItems != itemMap.end()) {
			player.pick((*(itItems -> second)));
		} else {
			std::cout << "Try pick something else!" << std::endl;
		}
	} else if(cmd.compare("bag") == 0){
		player.print_bag();
	}
	else if(cmd.compare("go") == 0){
		itEnvironments = environmentMap.find(msg);
		if (itEnvironments != environmentMap.end()) {
			logManager.changeGameLocation(msg);
		} else {
			std::cout << "Where the hell is that?" << std::endl;
		}
	}else {
		std::cout <<"You better try a valid command" << std::endl;
	}

}

void CommandHandler::run() {
	print_intro();

	int i = 3;
	while(i > 0) { //isRunning
		write_output();
		read_input();
		i--;
	}
}

void CommandHandler::print_intro() {
	std::cout << "Welcome to decisio game, your choices will count!" << std::endl;
	std::cout << "You must be the squirrel " << player.name() << "! Winter is coming..." << std::endl;
	std::cout << "collect all the nuts to be prepared! But beware of the dangerous predators..." << std::endl;
}

void CommandHandler::init_actorMap() {
	this->actorMap["Mr. Eagle"] = new Eagle("Mr. Eagle"); //Mem leak?
}

void CommandHandler::init_environments() { //bygg spelplanen med environment object
	std::string start = "OakForest1";
	this->environmentMap[start] = new OakForest(start);
	this->logManager.currEnvironment = start;
	start = "PineForest1";
	Environment * env2 = new PineForest("PineForest1");
	environmentMap[env2->location()] = env2;
	Environment * env3 = new PineForest("OakForest2");
	environmentMap[env3->location()] = env3;
}


}
