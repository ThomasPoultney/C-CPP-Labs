#include <stdio.h>
#include "constituency.h"

int main (int argc, char* argv []) {

	// Parse the input file in to a new array and return
	// the pointer and size in the variables provided
	struct Constituency * constituencies;
	unsigned int num_constituencies;
	if (!load_Constituencies("wales.graph",& constituencies,&num_constituencies)) {
		// If function returns error code terminate ...
		return -1;
	}

	printf("\nnumber of constituencies loaded is:\t%d\n",num_constituencies);
	int i = 0;
	int leastNeighbours = 0;
	int mostNeighbours = 0;

	for (i; i < num_constituencies ; i++) {
		int currentNoNeighbours = (constituencies[i].num_neighbours);

		if (currentNoNeighbours <= constituencies[leastNeighbours].num_neighbours) {
			leastNeighbours = i;
		}

		if (currentNoNeighbours >= constituencies[mostNeighbours].num_neighbours) {
			mostNeighbours = i;
		}
		print_Constituency(&constituencies[i]);
	}


	printf("----------------------------------------\n");
	printf("least neighbors index: %d \n",leastNeighbours);
	printf("constituency with fewest neighbors is:\n");
	print_Constituency(&constituencies[leastNeighbours]);
	printf("The names of the neighbours are: ");
	i=0;

	for (i; i < constituencies[leastNeighbours].num_neighbours ; i++) {
		printf("%s, ",constituencies[constituencies[leastNeighbours].neighbours[i]].name);
	}
	printf("\n----------------------------------------\n");
	printf("most neighbours index: %d \n",mostNeighbours);;
	printf("constituency with most neighbors is:\n");
	print_Constituency(&constituencies[mostNeighbours]);
	printf("\n----------------------------------------\n");
	printf("The names of the neighbours are: ");
	i=0;

	for (i; i < constituencies[mostNeighbours].num_neighbours ; i++) {
		printf("%s, ",constituencies[constituencies[mostNeighbours].neighbours[i]].name);
	}


	for (i; i < num_constituencies ; i++) {
		destruct_Constituency(&constituencies[i]);
	}


	// If we have reached this line , the file has
	// been successfully loaded and the variables
	// constituencies and num_constituencies have
	// been set properly .
	// ... the rest of the program ...
	// Don ’t forget to deallocate when done !
return 0;
}
