/*
 * squirrel.hpp
 *
 *  Created on: Aug 14, 2016
 *      Author: je
 */

#ifndef SQUIRREL_HPP_
#define SQUIRREL_HPP_

#include "character.hpp"
#include "item.hpp"
#include <map>

class Squirrel: public Character {

private:
	int nuts;
	std::map<std::string, int> bag;
	std::map<std::string, int>::const_iterator bagIterator;

public:
	Squirrel();
	virtual ~Squirrel();
	virtual void type() const;
	virtual void action();
	void pick(Item &);
	void change_nr_nuts(int n);
	void print_bag();
};

#endif /* SQUIRREL_HPP_ */
