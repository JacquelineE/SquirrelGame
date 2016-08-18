/*
 * forest.hpp
 *
 *  Created on: Aug 15, 2016
 *      Author: je
 */

#ifndef FOREST_HPP_
#define FOREST_HPP_

#include "environment.hpp"

namespace sgame {

class Forest : public Environment {

private:

public:
	Forest();
	Forest(std::string locName);
	virtual ~Forest();

	virtual void pick_nut() = 0;
	virtual void place_items() = 0;
	virtual std::string get_description() const = 0;

};

}

#endif /* FOREST_HPP_ */
