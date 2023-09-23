#ifndef COMPLEX_NUMBERS_H
#define COMPLEX_NUMBERS_H

typedef struct {
    double real;
    double imaginary;
} ComplexNumber;

void Initialize(ComplexNumber *c, double real, double imaginary);
void CopyNumber(const ComplexNumber *source, ComplexNumber *destination);
void Sum(const ComplexNumber *c1, const ComplexNumber *c2, ComplexNumber *result);
void IsReal(const ComplexNumber *c);
void Print(const ComplexNumber *c);

#endif