#include <stdio.h>
int main()
{   float soma, idade, n, media;

    soma = 0;
    n = 0;
    printf("Digite sua idade: ");
    scanf("%f",&idade);

    while (idade>0)
        {
        soma = soma + idade;
        n = n + 1;
        printf("Digite sua idade: ");
        scanf("%f",&idade);
        }

    if (n>0) {
        media = soma / n;
        printf("A idade media entre todas as idades e: %.0f",media);
    } else {
        printf("nao houve entrada.");
    }
}