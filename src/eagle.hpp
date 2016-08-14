/*
 * eagle.hpp
 *
 *  Created on: Aug 14, 2016
 *      Author: je
 */

#ifndef EAGLE_HPP_
#define EAGLE_HPP_

#include "character.hpp"

class Eagle: public Character {
public:
	Eagle();
	virtual ~Eagle();
	virtual void type() const;
	virtual void action();

};

#endif /* EAGLE_HPP_ */
