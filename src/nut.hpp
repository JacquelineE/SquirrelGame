/*
 * nut.hpp
 *
 *  Created on: Aug 14, 2016
 *      Author: je
 */

#ifndef NUT_HPP_
#define NUT_HPP_

#include "item.hpp"
#include <string>

class Nut: public Item {
private:
	std::string nutName;
public:
	Nut();
	virtual ~Nut();
	virtual std::string get_name();
};

#endif /* NUT_HPP_ */
