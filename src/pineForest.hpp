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
	int cones;
public:
	PineForest();
	virtual ~PineForest();
	virtual void pick_nut();
};

}

#endif /* PINEFOREST_HPP_ */
