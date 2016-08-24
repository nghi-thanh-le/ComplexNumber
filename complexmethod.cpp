#include <iostream>
#include "complexmethod.h"

ComplexMethod::ComplexMethod() {}

double ComplexMethod::getImagine(){
    return imaginePart;
}

double ComplexMethod::getReal(){
    return realPart;
}

void ComplexMethod::setImagine(double newImagine){
    imaginePart = newImagine;
}

void ComplexMethod::setReal(double newReal){
    realPart = newReal;
}

void ComplexMethod::AddComplex(ComplexNumber a, ComplexNumber b){
    setReal(a.getReal() + b.getReal());
    setImagine(a.getImagine() + b.getImagine());
}
