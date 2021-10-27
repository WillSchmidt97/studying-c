#include <stdio.h>
main()
{   int c, i, i2, primo;
    printf("Digite um numero para saber quais numeros primos existem no intervalo entre 0 e esse numero: ");
    scanf("%d",&c);
    printf("Entre o numero 0 e o numero %d os numeros primos sao: ",c);
    for(i = 1; i <= c; i++)
    {
        for(i2 = 1; i2 <= i; i2++)
        {   
            if ((i % i2) == 0)
            {
                primo = primo + 1;
            }
        }
            if (primo == 2)
            {
                printf("%d ",i);
        }
        primo = 0;
    }   
}