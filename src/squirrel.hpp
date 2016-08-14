/*
 * squirrel.hpp
 *
 *  Created on: Aug 14, 2016
 *      Author: je
 */

#ifndef SQUIRREL_HPP_
#define SQUIRREL_HPP_

#include "character.hpp"

class Squirrel: public Character {

private:
	int nuts;
public:
	Squirrel();
	virtual ~Squirrel();
	virtual void type() const;
	virtual void action();
	void pick();
	void change_nr_nuts(int n);
};

#endif /* SQUIRREL_HPP_ */
