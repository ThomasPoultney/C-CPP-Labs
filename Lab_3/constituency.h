#ifndef CONSTITUENCY_H
#define CONSTITUENCY_H

struct Constituency
{
  char *name;
  unsigned int *neighbours;
  unsigned int num_neighbours;

};

void construct_Constituency(struct Constituency* constituency, char* name, unsigned int* neighbours, unsigned int num_neighbours);
void destruct_Constituency(struct Constituency* constituency);
void print_Constituency(struct Constituency* constituency);
int load_Constituencies(char* filename,  struct Constituency** constituencies, unsigned int* numLoaded);

#endif
