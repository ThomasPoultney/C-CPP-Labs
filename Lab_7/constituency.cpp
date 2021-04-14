#include "constituency.h"

Constituency :: Constituency (const std::string & name ,const std::vector<int> & neighbours ): name(name), neighbours(neighbours) {}

const std::string & Constituency :: get_name () const {
	return name ;
}
const std::vector<int>& Constituency :: get_neighbours () const {
	return neighbours ;
}
