#include <stdio.h>
int main()
{   int n, aux, aux2, contador, i;

    printf("Escreva um número: ");
    scanf("%d",&n);
    printf("Os numeros primos entre 0 e %d sao: ",n);
    
    i = 1;
    aux = 0;
    for(aux; n; i++)
    {
        if ((aux = 1))
        {
            printf("1");
        } else {
            contador = 0;
            aux2 = 0;
            while ((aux <= (aux-1)) && (contador = 0))
            {
                if ((aux % aux2) = 0)
                {
                    contador = contador + 1;
                }
                aux2 = aux2 + 1;
                
            }
            if ((contador = 0))
            {
                printf("%d",aux);
            }
            
        }
        
    }
    

}