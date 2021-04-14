#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct Constituency {
	char*			name;
	unsigned int*	neighbours;
	unsigned int	num_neighbours;
};

void construct_Constituency(struct Constituency* constituency, char* name, unsigned int* neighbours, unsigned int num_neighbours) {
	// Assign name
	constituency->name = malloc(strlen(name)*sizeof(char));
	strcpy(constituency->name, name);

	// Assign neighbours array
	constituency->num_neighbours = num_neighbours;
	constituency->neighbours = malloc(sizeof(unsigned int) * num_neighbours);
	int i;
	for (i = 0; i < num_neighbours; i++)
		constituency->neighbours[i] = neighbours[i];
}
void destruct_Constituency(struct Constituency* constituency){
	free(constituency->name);
	constituency->name = NULL;
	free(constituency->neighbours);
	constituency->neighbours = NULL;
}
void print_Constituency(struct Constituency* constituency) {
	printf("%s|%d Neighbours| ", constituency->name, constituency->num_neighbours);
	int i = 0;
	for (i; i < constituency->num_neighbours; i++)
		printf("%d ", constituency->neighbours[i]);
		printf("\n");

}

int load_Constituencies(char* filename, struct Constituency** constituencies, int* numLoaded) {
	FILE *fp = fopen(filename, "r");
 	if ( !fp ) {
 		return 0;
 	}


	fscanf(fp ,"%d",numLoaded);
	*constituencies = malloc(*numLoaded*sizeof(struct Constituency));
	int i = 0;
	int numNeighbours = 0;
	for (i; i < *numLoaded; i++) {
		int numNeighbours;

		fscanf(fp,"%d\n",&numNeighbours);
	//	printf("\nnumber of neigbours = %d\t",numNeighbours);
		int k;
		char charStored[1];
		fscanf(fp,"%c",charStored);
		unsigned int *currentNeighbours = malloc(numNeighbours*sizeof(unsigned int));
		for(k=0; k<numNeighbours;k++) {


			fscanf(fp,"%is",&currentNeighbours[k]);
			fscanf(fp,"%c",charStored);
		//	printf("%d ",currentNeighbours[k]);

		}
		char name[256];
		fscanf(fp,"%s\n",name);
		construct_Constituency(*constituencies+i,name, currentNeighbours, numNeighbours);

		numNeighbours = 0;

	}
	fclose(fp);

	return 1;
}
