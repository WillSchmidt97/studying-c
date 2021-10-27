#include <stdio.h>

main()
{   float tempC, tempF;
    printf("Declare o tempo em celsius que queres saber: \n");
    scanf("%f",&tempC);
    tempF = 50;
    while (tempF == 50)
    {   tempF = (tempC * 1.8) + 32;
        printf("%.0f graus celsius equivale a %.0f graus fahrenheit.",tempC,tempF);

    }
    return 0;
}