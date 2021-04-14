#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>
#include <vector>
#include "constituency.h"

std::istream& operator>>(std::istream& in, Constituency& constituency);

int main ( int argc , char * argv []) {
	std::ifstream inputFile ("wales.graph");
	if (! inputFile.is_open()) {
		return 1;
	}

	// Read file header
	int expected_constituencies ;
	inputFile >> expected_constituencies ;
	std :: cout << "expected_constituencies = "
	<< expected_constituencies << std :: endl ;

	 std::string discardString;
	 std::getline(inputFile,discardString);

	// Read the first constituency
	Constituency constituency;
	inputFile >> constituency;

	// Print the parsed values
	std::cout << constituency.get_name();

	for ( auto & neighbour:constituency.get_neighbours()) {
		std :: cout << " , " << neighbour;
	}

	std::cout << std :: endl ;
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
	std::cout << "hello" << inString.c_str();

	Constituency newConstituency(name, neighbours);
	constituency = newConstituency;
}
