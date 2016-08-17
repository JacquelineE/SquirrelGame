/*
 * CommandHandler.cpp
 *
 *  Created on: Aug 14, 2016
 *      Author: je
 */

#include "commandHandler.hpp"
#include "eagle.hpp"
#include "squirrel.hpp"

#include <iostream>
#include <sstream>

namespace sgame {

CommandHandler::CommandHandler() {
	this->player = Squirrel();
	this->logManager = LogisticManager(); //now the commandHandler can access environments
	std::cout << logManager.environmentMap.find(logManager.currEnvironment)->second->location() << std::endl;
	init_actorMap();
	std::cout << actorMap.find("Mr. Eagle")->second->name() << std::endl;
	//player = Squirrel();
}

CommandHandler::CommandHandler(CommandHandler & ref) {
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
	for(std::map<std::string, Environment*>::iterator itr = logManager.environmentMap.begin(); itr != logManager.environmentMap.end(); itr++) {
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

CommandHandler& CommandHandler::operator=(const CommandHandler& ref) {
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
	std::cout << logManager.currEnvironment << std::endl;
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
	} else {
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
	std::cout << "You must be the squirrel " << player.name() << "! Collect all the nuts" << std::endl;
	std::cout << "for the winter, but beware of the dangerous predators..." << std::endl;
}

void CommandHandler::init_actorMap() {
	actorMap["Mr. Eagle"] = new Eagle("Mr. Eagle"); //Mem leak?
}

}
