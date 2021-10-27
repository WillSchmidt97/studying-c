#include <stdio.h>

float fahrenheit(float celsius)
{       float tempF;
        tempF = 50;
        while (tempF == 50)
    {   tempF = (celsius * 1.8) + 32;
    }
        return(tempF);
}

main()
{   float tempC;
    printf("Declare o tempo em celsius que queres saber: \n");
    scanf("%f",&tempC);
    printf("%.0f graus celsius equivale a %.0f graus fahrenheit.",tempC,fahrenheit(tempC));
}