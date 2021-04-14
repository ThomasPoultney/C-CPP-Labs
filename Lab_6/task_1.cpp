# include <iostream>
# include "Cat.h"
int main ( int argc , char * argv []) {
	Cat a ( " Garfield " , 42);
	std::cout << std::hash<Cat>()(a) << " = " << a << std::endl;
	// Note the double ()() syntax !
	// std :: hash < Cat >() default constructs an
	// object of type std :: hash < Cat >
	// std :: hash < Cat >()( a ) invokes the call
	// operator () on that object with parameter ‘a ‘
	// std :: hash < Cat >()( a ) returns an unsigned long integer
	return 0;
}
