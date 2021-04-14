#pragma once
#include <string>
#include <iostream>

class Shape {
public:
	Shape();
	virtual  ~Shape();
	virtual std::string to_string() const = 0;
	virtual void centre_at(float x, float y) = 0;

};

class Circle : public Shape {
public:
	Circle(float x, float y, float r);
	virtual ~Circle();
	virtual std::string to_string() const ;
	virtual void centre_at(float x, float y);
	float x, y, r;
};

class Rectangle: public Shape {
public:
	Rectangle(float x0, float y0, float x1,float y1);
	virtual ~Rectangle();
	virtual std::string to_string() const ;
	virtual void centre_at(float x, float y);
	float x0, y0, x1, y1;
};

class Triangle: public Shape {
public:
	Triangle(float x0, float y0, float x1,float y1, float x2,float y2);
	virtual ~Triangle();
	virtual std::string to_string() const ;
	virtual void centre_at(float x, float y);
	float x0, y0, x1, y1, x2, y2;
};
