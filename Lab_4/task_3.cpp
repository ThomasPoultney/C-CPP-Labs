#include <string>
#include <iostream>
#include <math.h>       /* ceil */
#include "cat.h"

int main (int argc,char * argv []) {

  const int numberOfCats = ceil((argc)/2);
  std ::cout << numberOfCats << std ::endl;
  Cat catArray[numberOfCats];
  int j = 1;
  for (int i = 0; i < numberOfCats; i++) {
    catArray[i].set_name(argv[j]);
    if (j < argc - 1) {
      catArray[i].set_lives((atoi(argv[j+1])));
    }
    catArray[i].printCat();
    j+=2;
  }
  return 0;
}
