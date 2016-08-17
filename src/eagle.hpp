/*
 * eagle.hpp
 *
 *  Created on: Aug 14, 2016
 *      Author: je
 */

#ifndef EAGLE_HPP_
#define EAGLE_HPP_

#include "character.hpp"

namespace sgame {

class Eagle: public Character {
public:
	Eagle();
	Eagle(std::string name);
	Eagle(Eagle const & ref);
	virtual ~Eagle();

	virtual std::string name() const;
	virtual void type() const;
	virtual void action();

};

}

#endif /* EAGLE_HPP_ */
