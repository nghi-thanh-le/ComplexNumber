#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H
#define PI 3.14159265;
#include <cmath>
#include <iostream>

class ComplexNumber
{
    public:
        //Constructor
        ComplexNumber();// default complex .
        ComplexNumber(double a, double b);  // complex constructor with parameters
        ComplexNumber(const ComplexNumber& c); // copying complex constructor

        // get methods
        double getReal();
        double getImagine();
        double getModule();
        double getPhase();

        // set methods
        void setReal(double newReal);
        void setImagine(double newImagine);
        void setModule(double newModule);
        void setPhase(double newPhase);

        // operator change the real and part of object
        void operator +=(ComplexNumber& x);
        void operator -=(ComplexNumber& x);
        void operator *=(ComplexNumber& x);
        void operator /=(ComplexNumber& x);

        // operator return an object
        ComplexNumber operator+(ComplexNumber& x);
        ComplexNumber operator-(ComplexNumber& x);
        ComplexNumber operator*(ComplexNumber& x);
        ComplexNumber operator/(ComplexNumber& x);

    private:
        double realPart, imaginePart;
        double module = sqrt(realPart * realPart + imaginePart * imaginePart);
        double phase;

        // base on phase, set the real and imagine
        void changeInRealAndImagine(double real, double imagine, double phase);
};
#endif // COMPLEXNUMBER_H
