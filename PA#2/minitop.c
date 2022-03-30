#include "types.h"
#include "user.h"
#include "stat.h"

int main(int argv, char *argc[]){
  printf(1,"pid\tppid\tprio\tstate\tname\n");

  if(argv < 1)
    ps(0);
  else{
    ps(atoi(argc[1]));
  }
  exit();
}
