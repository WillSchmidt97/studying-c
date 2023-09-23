#include <stdio.h>
#include "complex-numbers.h"

int main(){
    ComplexNumber n1, n2, n3, sum;
    double real, imaginary;

    printf("Enter the first complex number, first the real and then the imaginary: ");
    scanf("%lf %lf", &real, &imaginary);
    Initialize(&n1, real, imaginary);

    printf("\nEnter the second complex number, first the real and then the imaginary: ");
    scanf("%lf %lf", &real, &imaginary);
    Initialize(&n2, real, imaginary);

    printf("\nPrinting the number in the format R + Ci: ");
    Print(&n1);

    printf("\nCopying the first complex number to the third complex number...\n");
    CopyNumber(&n1, &n3);
    printf("Printing the third complex number in the format R + Ci: ");
    Print(&n3);

    printf("\nSumming %f + %fi and %f + %fi...\n", n1.real, n1.imaginary, n2.real, n2.imaginary);
    Sum(&n1, &n2, &sum);
    printf("The sum is: %f + %fi\n", sum.real, sum.imaginary);

    printf("\nSumming %f + %fi and %f + %fi...\n", n1.real, n1.imaginary, n3.real, n3.imaginary);
    Sum(&n1, &n3, &sum);
    printf("The sum is: %f + %fi\n", sum.real, sum.imaginary);

    printf("\nChecking if %f + %fi is real...\n", n1.real, n1.imaginary);
    IsReal(&n1);

    printf("\nChecking if %f + %fi is real...\n", n2.real, n2.imaginary);
    IsReal(&n2);

    printf("\nChecking if %f + %fi is real...\n", n3.real, n3.imaginary);
    IsReal(&n3);
}