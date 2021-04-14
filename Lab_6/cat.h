#pragma once
#include <string>
#include <iostream>
#include <sstream>

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
	friend std::ostream& operator<<(std::ostream& l,const Cat& r) {
		l << r.name << r.lives;
		return l ;
	}

	friend bool operator==(const Cat& cat1,const Cat& cat2);

	friend bool operator<(const Cat& cat1,const Cat& cat2);
private:
	std::string name;
	unsigned int lives;
};


namespace std {
	template < >
	struct hash <Cat> {
		size_t operator()(const Cat &obj) const {
			// ... compute a hash as an unsigned long
			std::stringstream catString;
			catString << obj;
			std::string str = catString.str();
			size_t some_computed_hash = std::hash<std::string>{}(str);
			// integer and return it ...
			return some_computed_hash;
		}
	};
}
