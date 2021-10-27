#include <stdio.h>

int verificador(int n)
{       int i, i2, primo;
        for(i = 1; i <= n; i++)
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
        return (i);          
}

int main()
{   int c;
    printf("Digite um numero para saber quais numeros primos existem no intervalo entre 0 e esse numero: ");
    scanf("%d",&c);
    printf("Entre o numero 0 e o numero %d os numeros primos sao: ",c);
    verificador(c);
}