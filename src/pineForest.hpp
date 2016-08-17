/*
 * pineForest.hpp
 *
 *  Created on: Aug 16, 2016
 *      Author: je
 */

#ifndef PINEFOREST_HPP_
#define PINEFOREST_HPP_

#include "forest.hpp"

namespace sgame {

class PineForest: public Forest {

private:
	int cones = 2;
public:
	PineForest();
	PineForest(std::string locName);
	virtual ~PineForest();

	virtual void pick_nut();
	virtual void place_items();
};

}

#endif /* PINEFOREST_HPP_ */
