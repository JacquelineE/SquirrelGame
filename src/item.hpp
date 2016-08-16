/*
 * item.hpp
 *
 *  Created on: Aug 14, 2016
 *      Author: je
 */

#ifndef ITEM_HPP_
#define ITEM_HPP_

#include <string>
class Item {


public:
	Item();
	virtual ~Item();
	virtual std::string get_name() = 0;
};

#endif /* ITEM_HPP_ */
