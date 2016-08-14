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

protected:
	std::string name ="";
public:
	Item();
	virtual ~Item();
	std::string get_name();
};

#endif /* ITEM_HPP_ */
