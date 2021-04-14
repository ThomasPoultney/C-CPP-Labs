# include <iostream>
# include "Shape.h"

int main ( int argc , char * argv []) {
	Shape* shapeArray[10];
	shapeArray[0] = new Circle(3,5,6);
	shapeArray[1] = new Circle(2,5,8);
	shapeArray[2] = new Circle(4,5,7);
	shapeArray[3] = new Circle(2,4,6);
	shapeArray[4] = new Rectangle(3,5, 4,7);
	shapeArray[5] = new Rectangle(3,4, 6,7);
	shapeArray[6] = new Rectangle(3,2, 6,6);
	shapeArray[7] = new Triangle(0,0, 4,4,14,14);
	shapeArray[8] = new Triangle(0,0, 8,7,13,13);
	shapeArray[9] = new Triangle(0,0, 6,3,12,12);

	for (int i = 0; i < 10; i++) {
		std::cout << shapeArray[i]->to_string()<<std::endl;
		std::cout << "centre moved to 0,4" << std::endl;
		shapeArray[i]->centre_at(0,4);
		std::cout << shapeArray[i]->to_string() <<std::endl;
		std::cout << "" << std::endl;
	}
}
