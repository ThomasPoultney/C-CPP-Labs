#include <stdio.h>
#include "constituency.h"

int main (int argc, char* argv []) {
	//struct Constituency test;
	//construct_Constituency (&test ,"Swansea East",(unsigned int[]){1 , 2 , 3 , 4} , 4);
    //print_Constituency (&test);
    //printf("\n");
	//destruct_Constituency(&test);
	const int num_constituencies = 5;
	struct Constituency constituencies[num_constituencies];
	construct_Constituency(&constituencies[0] ,"Swansea East" , ( unsigned int []){1 , 2 , 3 , 4} , 4);
	construct_Constituency(&constituencies[1] ,"Swansea West" , ( unsigned int []){0 , 2} , 2);
	construct_Constituency(&constituencies[2] ,"Gower" , ( unsigned int []){0 , 1 , 3} , 3);
	construct_Constituency(&constituencies[3] ,"Neath" , ( unsigned int []){0 , 2 , 4} , 3);
	construct_Constituency(&constituencies[4] ,"Aberavon" , ( unsigned int []){0 , 3} , 2);

	int i = 0;
	int leastNeighbours = 0;
	int mostNeighbours = 0;
	for (i; i < num_constituencies ; i++) {
		int currentNoNeighbours = (constituencies[i].num_neighbours);
		printf("%d\t ",currentNoNeighbours);
		if (currentNoNeighbours > leastNeighbours) {
			leastNeighbours = i;
		}

		if (currentNoNeighbours < mostNeighbours) {
			mostNeighbours = i;
		}
		print_Constituency(&constituencies[i]);
	}


	printf("----------------------------------------\n");
	printf("leastneighbors: %d \n",leastNeighbours);
	printf("constituency with fewest neighbors is:\n");
	print_Constituency(&constituencies[leastNeighbours]);
	printf("----------------------------------------\n");
	printf("mostNeighbours: %d \n",mostNeighbours);;
	printf("constituency with most neighbors is:\n");
	print_Constituency(&constituencies[mostNeighbours]);
	for (i; i < num_constituencies ; i++) {
	destruct_Constituency(&constituencies[i]);
}
	return 0;
}
