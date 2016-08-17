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

namespace sgame {

class OakForest: public Forest {

private:
	//std::string locationName;
	int acorn = 5;
public:
	OakForest();
	OakForest(std::string locName);
	virtual ~OakForest();
	virtual void pick_nut();
};

}

#endif /* OAKFOREST_HPP_ */
