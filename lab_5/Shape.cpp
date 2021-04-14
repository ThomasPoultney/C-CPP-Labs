
#include "shape.h"
#include <iostream>
#include <sstream>
#include <math.h>

Shape::Shape(){
	std::cout << "Constructor called: Shape" << std ::endl;
}

Shape::~Shape() {
	std::cout << "Deconstructor called: Shape" << std ::endl;
}

//-----------------------Circle--------------------------//
Circle::Circle(float x, float y, float r):Shape(){
	this->x = x;
	this->y = y;
	this->r = r;
	std::cout << "Constructor called: Circle" << std::endl;
}

Circle::~Circle() {
	std::cout << "Deconstructor called: Circle" << std::endl;
}

std::string Circle::to_string() const {
	std::stringstream sstr;
	sstr << "Circle centred at (" << this->x << "," << this->y <<") with radius " << this->r;
	std::string str = sstr.str();
	return str;
}

void Circle::centre_at(float x, float y) {
 	this->x = x;
	this->y = y;
}

//-----------------------Rectangle--------------------------//
Rectangle::Rectangle(float x0, float y0, float x1, float y1):Shape(){
	this->x0 = x0;
	this->y0 = y0;
	this->x1 = x1;
	this->y1 = y1;
	std::cout << "Constructor called: Rectangle" << std::endl;
}

Rectangle::~Rectangle() {
	std::cout << "Deconstructor called: Rectangle" << std::endl;
}

std::string Rectangle::to_string() const {
	float width = (this->x1 - this->x0);
	float height = (this->y1 -this->y0);
	std::stringstream sstr;
	sstr << "Rectangle at [(" << this->x0 << "," << this->y0 <<") , ("<< this->x1 << "," << this->y1 << ")] with width " << width << ", Height " << height;
	std::string str = sstr.str();
	return str;
}

void Rectangle::centre_at(float x, float y) {
	float width = (this->x1-this->x0);
	 float height = (this->y1-this->y0);

 	this->x0 = x-width/2;
	this->y0 = y-height/2;
	this->x1 = x+width/2;
	this->y1 = y+height/2;
}

//-----------------------Triangle--------------------------//
Triangle::Triangle(float x0, float y0, float x1, float y1,float x2,float y2):Shape(){
	this->x0 = x0;
	this->y0 = y0;
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
	std::cout << "Constructor called: Triangle" << std::endl;
}

Triangle::~Triangle() {
	std::cout << "Deconstructor called:	Triangle" << std::endl;
}

std::string Triangle::to_string() const {
	float sideLengthBottom =  x1 - x0;
	float sideLengthLeft = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
	float sideLengthRight = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
	std::stringstream sstr;
	sstr << "Triangle at [(" << this->x0 << "," << this->y0 <<") , ("<< this->x1 << "," << this->y1 << ")]  , ("<< this->x2 << "," << this->y2 << ")] with  side lengths " << sideLengthBottom << ", "<< sideLengthLeft <<", " << sideLengthRight;
	std::string str = sstr.str();
	return str;
}

void Triangle::centre_at(float x, float y) {
	float centreX = ((x2+x1+x0)/3);
	float centreY = ((y2+y1+y0)/3);

	float offsetX =  centreX - x;
	float offsetY =  centreY - y;

	this->x0 = x0 + offsetX;
	this->y0 = y0 + offsetY;
	this->x1 = x1 + offsetX;
	this->y1 = y1 + offsetY;
	this->x2 = x2 + offsetX;
	this->y2 = y2 + offsetY;

}
