/*
 * oakForest.hpp
 *
 *  Created on: Aug 16, 2016
 *      Author: je
 */

#ifndef OAKFOREST_HPP_
#define OAKFOREST_HPP_


#include "forest.hpp"
#include <string>

class OakForest: public Forest {

private:
	int acorn;
public:
	OakForest();
	virtual ~OakForest();
	virtual void pick_nut();
};

#endif /* OAKFOREST_HPP_ */
