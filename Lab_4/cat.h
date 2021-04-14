#pragma once
#include <string>
#include <iostream>


class Cat {
public:
	~Cat();
	Cat();
	Cat(std::string name);
	Cat(std::string name,int lives);
	const std::string& get_name();
	const unsigned int& get_lives();
	void set_name(const std::string &catName);
	void set_lives(const unsigned int &catLives);
	void printCat();
private:
	std::string name;
	unsigned int lives;
};
