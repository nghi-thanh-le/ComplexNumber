#include <iostream>
#include "complexform.h"
#include "complexnumber.h"
#include "complexmethod.h"
using namespace std;

int main()
{
    ComplexForm form;
    ComplexNumber x;
    ComplexNumber x3;
    ComplexNumber x1(1,1);
    ComplexNumber x2(1,2);

    x = x1 + x2; // x = x1.operator + (x2);
    x3 +=x;
    form.canonicalForm(x);
    form.canonicalForm(x3);
    return 0;
}