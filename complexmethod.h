#ifndef COMPLEXMETHOD_H
#define COMPLEXMETHOD_H
#include "complex.h"
#include "complexnumber.h"

class ComplexMethod
{
    public:
        ComplexMethod();
        double getReal();
        double getImagine();
        void setReal(double newReal);
        void setImagine(double newImagine);
        void AddComplex(ComplexNumber a, ComplexNumber b);

    private:
        double realPart, imaginePart;
};

#endif // COMPLEXMETHOD_H
