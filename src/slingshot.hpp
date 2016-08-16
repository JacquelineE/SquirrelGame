/*
 * slingshot.hpp
 *
 *  Created on: Aug 15, 2016
 *      Author: je
 */

#ifndef SLINGSHOT_HPP_
#define SLINGSHOT_HPP_

#include "item.hpp"
#include <string>

class Slingshot : public Item {
	std::string name;
public:
	Slingshot();
	virtual ~Slingshot();
	std::string get_name();
};

#endif /* SLINGSHOT_HPP_ */
