#include "complexform.h"
#include <iostream>
using namespace std;

ComplexForm::ComplexForm() {}

ComplexForm::ComplexForm(ComplexNumber c)
{
    this->number = &c;
}

void ComplexForm::canonicalForm(ComplexNumber c)
{
    if (c.getReal() == 0)
        cout << "Canonical Form: z = " << c.getImagine() << "i" << endl;
    else if(c.getImagine() == 0)
        cout << "Canonical Form: z = " << c.getReal() << endl;
    else if(c.getImagine() > 0)
        cout << "Canonical Form: z = " << c.getReal() << " + " << c.getImagine() << "i" << endl;
    else if(c.getImagine() < 0)
        cout << "Canonical Form: z = " << c.getReal() << " + (" << c.getImagine() << ")i" << endl;
}

void ComplexForm::trigonometricForm(ComplexNumber c)
{
    cout << "Trigonometric Form: " << c.getModule() << "(cos" << c.getPhase() << " + isin" << c.getPhase() << ")" << endl;
}
