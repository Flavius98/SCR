#include <stdio.h>
#include <unistd.h>
#include <signal.h>

 
void handlerA()
{
  printf("zakonczenie programu\n");
  exit(0);
}
 
void handlerB()
{
  printf("wstrzymanie programu\n");
}

void handlerC()
{
  printf("zatrzymanie na 1000 iteracji\n");
  sleep(1)
  i = i + 1000;
}

void handlerD(){}

int main(){
 
    signal(SIGTERM, handlerA);
    signal(SIGALRM, handlerB);
    signal(SIGUSR1, handlerC);
    signal(SIGUSR2, handlerD);
 
    while(1)
    {
        i++;
        printf("%d\n", i);

        sleep(1);  
    }

    return 0;
}