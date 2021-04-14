# include <iostream>
# include "cat.h"

int main ( int argc , char * argv []) {
	//Cat a ("Garfield ");
	//std::cout << a.get_name () << "has "
	//			<< a.get_lives () <<" lives." << std :: endl ;
	Cat b ( "Mog " , 10);
	std::cout << b.get_name () << "has "
				<< b.get_lives () << " lives." << std :: endl ;
	b.set_lives(42);
	b.set_name("prince");
	b.set_lives(8);
	b.set_lives(0);
	b.set_lives(0);

	return 0;

}
