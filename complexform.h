#ifndef COMPLEXFORM_H
#define COMPLEXFORM_H
#include "complexnumber.h"


class ComplexForm
{
public:
    ComplexForm();
    ComplexForm(ComplexNumber c);
    void canonicalForm(ComplexNumber c); // output canonical form of complex number
    void trigonometricForm(ComplexNumber c);

private:
    ComplexNumber* number;
};
#endif // COMPLEXFORM_H
