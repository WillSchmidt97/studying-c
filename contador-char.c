#include <stdio.h>
int main()
{
    int c;
    c = 33;

    while (c<127)
    {
        printf("\n%c",c);
        c = c + 1;
    }
} 