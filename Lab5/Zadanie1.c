#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFOR 64

int main(int argc , char* argv[])
{

    int pidNum;
    int fileDescNum[2];

    pipe(fileDescNum);
    pidNum = fork();

    if (pidNum)
    {
        char bufor[MAX_BUFFOR];

        while (read(fileDescNum[0], bufor, MAX_BUFFOR))
        {
            if (bufor[MAX_BUFFOR - 1] == 0)
                break;
        
                bufor[MAX_BUFFOR - 1] = '\0';
                printf("#%s#\n", bufor);
        }
    }

    else
    {
        FILE *f = fopen(argv[1],"r");
        char buffor[MAX_BUFFOR];

        while (fgets(buffor, MAX_BUFFOR, f))
        {
            buffor[MAX_BUFFOR-1] = 1;
            write(fileDescNum[1],buffor,MAX_BUFFOR);
        }

        buffor[MAX_BUFFOR-1] = 0;
        write(fileDescNumb[1], buffor, MAX_BUFFOR);

        fclose(f);  
    }

}
