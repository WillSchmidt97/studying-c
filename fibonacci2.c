#include <stdio.h>

int cfibonacci(int numero)
{       int n1, n2, n3, cont;
        n1 = 0;
        n2 = 1;
        n3 = 0;
        cont = 0;
        while (n3<=numero)
    {
        printf("%d\n",n3);
        n1 = n2;
        n2 = n3;
        n3 = n1 + n2;
        cont++;
    }
        return(cont);
}

int main()
{   int n, contador;
    printf("Digite um valor inteiro e positivo: ");
    scanf("%d",&n);
    printf("Entre 0 e %d", n);
    printf(" estao os seguintes elementos da sequencia Fibonacci.\n");
    contador = cfibonacci(n);
    printf("Antes de %d", n);
    printf(" existem %d", contador);
    printf(" elementos da sequencia fibonacci.");
}