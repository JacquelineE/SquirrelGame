/*
 * character.hpp Abstract class for characters in the game
 *
 *  Created on: 12 aug. 2016
 *      Author: Mitra and Jacqueline
 */

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <string>

namespace sgame {

class Character {
protected:
	int health;
	int startHealth;
	std::string nickName;
	std::string location;

public:
	Character();
	virtual ~Character();

	virtual std::string name() const = 0;
	virtual void type() const = 0;
	void attack(Character &);
	virtual void action(std::string location, int moveOptions) = 0;
	//virtual std::string pick(const Item& item) const = 0;
	//virtual std::string drop(const Item& item) const = 0;
	void set_health(int);
	int get_health()const;
	std::string characterLocation() const;
	virtual int strength() = 0;
	int strength_character();
	void action_character(std::string location, int moveOptions);


};

}

#endif /* CHARACTER_HPP_ */
