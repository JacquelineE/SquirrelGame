/*
 * character.hpp Abstract class for characters in the game
 *
 *  Created on: 12 aug. 2016
 *      Author: Mitra and Jacqueline
 */

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <string>

class Character {
protected:
	int health;
	int age;
	//vector with items
	bool hasTreasure;
	std::string nickName;

public:
	Character();
	virtual ~Character();

	void name();
	virtual void type() const = 0;
	virtual void action() = 0;
	void attack(Character &);
	//virtual std::string pick(const Item& item) const = 0;
	//virtual std::string drop(const Item& item) const = 0;
	void set_health(int);
	int get_health()const;


};

#endif /* CHARACTER_HPP_ */
