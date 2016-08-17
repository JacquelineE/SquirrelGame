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

namespace sgame {

class Squirrel: public Character {

private:
	std::string nickName;
	int nuts;
	std::map<std::string, int> bag;
	std::map<std::string, int>::const_iterator bagIterator;

public:
	Squirrel();
	virtual ~Squirrel();

	virtual std::string name() const;
	virtual void type() const;
	virtual void action();
	void pick(Item &);
	void change_nr_nuts(int n);
	void print_bag();
};

}

#endif /* SQUIRREL_HPP_ */
