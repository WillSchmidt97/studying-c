#include <stdio.h>

int main()
{   int n, n1, n2, n3, contador;
    n1 = 0;
    n2 = 1;
    n3 = 0;
    contador = 0;

    printf("Digite um valor inteiro e positivo: ");
    scanf("%d",&n);
    printf("Entre 0 e %d", n);
    printf(" estao os seguintes elementos da sequencia Fibonacci.\n");
    while (n3<n)
    {
        printf("%d\n",n3);
        n1 = n2;
        n2 = n3;
        n3 = n1 + n2;
        contador = contador + 1;
    }
    
    printf("Antes de %d", n);
    printf(" existem %d", contador);
    printf(" elementos da sequencia fibonacci.");
}