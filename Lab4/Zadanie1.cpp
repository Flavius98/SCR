#include <stdio.h>
#include <unistd.h>
#include <iostream>


int main()
{
    int i = 0;

    while(1)
    {
        i++;
        std::cout << i;
    }

    sleep (1);
}