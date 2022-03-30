#include "types.h"
#include "user.h"
#include "stat.h"

int main(int argv, char *argc[]){
  int g_nice;
  char *man = " * set nice: $nice [s] [pid] [nice value]\n * get nice: $nice [g] [pid]\n";
  if(argv < 3)
    printf(1, "Need more arguments\n%s", man);
  else if(*(argc[1]) == 's'){
    if(argv < 4)
      printf(1, "Need more arguments\n%s", man);
    else if(setnice(atoi(argc[2]), atoi(argc[3])) < 0)
      printf(1, "Error.\n");
    else
      printf(1, "Complete.\n");

  }
  else if(*(argc[1]) == 'g'){
    g_nice = getnice( atoi(argc[2]) );

    if(g_nice < 0)
      printf(1, "Error: maybe there is no process that pid is %d.\n", atoi(argc[2]));
    else
      printf(1, "nice value of %c = %d\n", *(argc[2]), g_nice);
  }
  else{
    printf(1, "No such that option.\n%s", man);
  }
  exit();
}
