#include <stdio.h>
#include "complex-numbers.h"

void Initialize(ComplexNumber *c, double real, double imaginary)
{
    c->real = real;
    c->imaginary = imaginary;
}

void CopyNumber(const ComplexNumber *source, ComplexNumber *destination)
{
    destination->real = source->real;
    destination->imaginary = source->imaginary;
}

void Sum(const ComplexNumber *c1, const ComplexNumber *c2, ComplexNumber *result)
{
    result->real = c1->real + c2->real;
    result->imaginary = c1->imaginary + c2->imaginary;
}

void IsReal(const ComplexNumber *c)
{
    if (c->imaginary == 0)
        printf("\nThe number is real.\n");
    else
        printf("\nThe number is not real.\n");
}

void Print(const ComplexNumber *c)
{
    printf("%f + %fi\n", c->real, c->imaginary);
}