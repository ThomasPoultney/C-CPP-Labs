
#include "cat.h"

Cat::Cat() : name("Tom"),lives(9)  {
	std ::cout << "Default constructor called..." << std ::endl;
}
Cat::Cat(std::string name) {
	this->name = name;
	std ::cout << "Constructor called with name ..." << std ::endl;
}

Cat::Cat(std::string name,int lives) {
	this->name = name;
	this->lives = lives;
	std::cout << "Constructor called with name and lives..." << std ::endl;
}

Cat::~Cat() {
	std::cout << "Deconstructor called:" << std ::endl;
}

const std::string& Cat::get_name() {
	return name;
}
const unsigned int& Cat::get_lives() {
	return lives;
}

void Cat::set_name(const std::string &catName) {
	this->name = catName;
	std::cout << "set name called...:" << std ::endl;
}
void Cat::set_lives(const unsigned int &catLives){
	std::cout << "set lives called...:" << std ::endl;
	if(catLives >= this->lives){
		std::cout << "cat  cannot gain lives dummy..." << std ::endl;
	} else {
		this-> lives = catLives;
	}

	if (catLives == 0) {
		set_name("The cat formely known as " + get_name());
		this-> lives = 0;
	}

}

void Cat::printCat() {
		std::cout << this->get_name() << " has " << this->get_lives()<< " lives" << std::endl;
}
