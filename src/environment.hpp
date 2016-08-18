/*
 * environment.hpp
 *
 * Abstract class for environments in the game, the room of the first
 * character, maifia's headquarter, school etc
 *
 *  Created on: 12 aug. 2016
 *      Author: Mitra and Jacqueline
 */

#ifndef ENVIRONMENT_HPP_
#define ENVIRONMENT_HPP_

#include "item.hpp"
#include <string>
#include <vector>

namespace sgame {

class Environment {
	//vector with neighbors? static linked list?

protected:
	std::string locationName;
	std::vector<Item*> items;

public:
	Environment();
	Environment(std::string);
	virtual ~Environment();

	std::string location() const;
	virtual void place_items() = 0;
	void print_items();
	bool try_pick_item(std::string name);
	int get_number_of_nuts();
	virtual std::string get_description() const = 0;
	void desc() const;
};

}

#endif /* ENVIRONMENT_HPP_ */
