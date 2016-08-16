/*
 * forest.hpp
 *
 *  Created on: Aug 15, 2016
 *      Author: je
 */

#ifndef FOREST_HPP_
#define FOREST_HPP_

#include "environment.hpp"
class Forest : public Environment {

private:


public:
	Forest();
	virtual ~Forest();
	virtual void pick_nut() = 0;

};

#endif /* FOREST_HPP_ */
