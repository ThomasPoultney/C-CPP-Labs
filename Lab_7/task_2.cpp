#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>
#include <vector>
#include "constituency.h"

std::istream& operator>>(std::istream& in, Constituency& constituency);

int main ( int argc , char * argv []) {
	std::ifstream inputFile ("wales.graph");
	if (! inputFile . is_open ()) {
		return 1;
	}
	// Read file header
	int expected_constituencies ;
	inputFile >> expected_constituencies ;
	std :: cout << "expected_constituencies = "
	<< expected_constituencies << std :: endl ;
	// Read the first constituency
	std::vector<Constituency> constituencies;
	std::copy(std::istream_iterator<Constituency>(inputFile), std::istream_iterator<Constituency>(), std::back_inserter(constituencies));

	for (int i = 0; i < expected_constituencies; i++) {
		std::vector<int> c = constituencies[i].get_neighbours();
		for (int i = 0; i < c.size(); i++) {
			std::cout << c[i] << " , ";
		}
		std::cout << constituencies[i].get_name() << std::endl;
	}
	return 0;
}

std::istream& operator>>(std::istream& in, Constituency& constituency) {
	std::string inString;
	std::getline(in,inString);
	std::istringstream strStream(inString);

	std::string numNeighboursStr;
	strStream >> numNeighboursStr;
	int numNeighbours = atoi(numNeighboursStr.c_str());

	std::string buffer;
	std::vector<int> neighbours;
	for (int i = 0; i < numNeighbours; i++) {
		strStream >>buffer;
		neighbours.push_back(atoi(buffer.c_str()));
	}
	std::string name;
	strStream >> name;


	Constituency newConstituency(name, neighbours);
	constituency = newConstituency;
}
