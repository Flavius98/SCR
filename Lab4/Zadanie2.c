#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
 
void handlerA()
{
  printf("wykonanie podpunktu a)\n");
  exit(0);
}
 
void handlerB()
{
  printf("wykonanie podpunktu b)\n");
}

void handlerC()
{
  printf("wykonanie podpunktu c)\n");
  for (int i = 0; i < 100; i++)
  {
      printf("%d \n", i);
      sleep(1);
  }
}

void handlerD(){}

int main(){
 
    signal(SIGTERM, handlerA);
    signal(SIGALRM, handlerB);
    signal(SIGUSR1, handlerC);
    signal(SIGUSR2, handlerD);
 
    for(int i = 0;; i++)
    {
        printf("%d", i++);
        sleep(1);  
    }

    return 0;
}