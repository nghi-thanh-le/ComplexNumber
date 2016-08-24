#include "complexnumber.h"
#include <iostream>
using namespace std;

//Constructor
ComplexNumber::ComplexNumber(){
    realPart = 0;
    imaginePart = 0;
}

ComplexNumber::ComplexNumber(double a, double b)
{
    realPart = a;
    imaginePart = b;
}

ComplexNumber::ComplexNumber(const ComplexNumber& c)
{
    realPart = c.realPart;
    imaginePart = c.imaginePart;
}

// get/set method
double ComplexNumber::getReal(){ return realPart; }

double ComplexNumber::getImagine(){ return imaginePart; }

double ComplexNumber::getModule(){ return module; }

double ComplexNumber::getPhase()
{
    // the range : [-180, 180]
    // new angle : [0, 360]
    double a = realPart;
    double b = imaginePart;
    double angel = atan2(b,a)*180/PI;
    if (a >= 0 && b >= 0)
        phase = angel;
    else if (a <= 0 && b >= 0)
        phase = angel;
    else if (a <= 0 && b <= 0)
        phase = 360 + angel;
    else if (a >= 0 && b <= 0)
        phase = 450 - angel;
    return phase;
}

void ComplexNumber::setReal(double newReal){ realPart = newReal; }

void ComplexNumber::setImagine(double newImagine){ imaginePart = newImagine; }

//setModule method which change the old real and imagine number by using new module
void ComplexNumber::setModule(double newModule)
{
    // module is changed
    // the alpha(the angle of real and imagine number) is kept
    if (newModule < 0)
        cout << "The new module must be more than 0" << endl;
    else
    {
        // calling new imagine and real number
        module = newModule;
        double newReal, newImagine;
        double x = abs(tan(phase));
        /*we have  newImagine / newReal = x
            and we also have newReal*newReal + newImagine*newImagin = newModule * newModule
                and i want newReal and newImagine not negative to make it simple*/

        newReal = sqrt((newModule * newModule) / (1 + x * x) );
        newImagine = newReal * x;
        changeInRealAndImagine(newReal, newImagine, phase);
    }
}

void ComplexNumber::setPhase(double newPhase)
{
    //the new phase is added but the module is kept
    double newReal, newImagine;
    double x = abs(tan(newPhase));
    /*we have  newImagine / newReal = x
        and we also have newReal*newReal + newImagine*newImagin = newModule * newModule
            and i want newReal and newImagine not negative to make it simple*/

    newReal = sqrt((module * module) / (1 + x * x) );
    newImagine = newReal * x;
    changeInRealAndImagine(newReal, newImagine, newPhase);
}

void ComplexNumber::operator +=(ComplexNumber& x){
    realPart += realPart + x.realPart;
    imaginePart += imaginePart + x.imaginePart;
}

void ComplexNumber::operator -=(ComplexNumber& x){
    realPart -= x.realPart;
    imaginePart -= x.imaginePart;
}

void ComplexNumber::operator *=(ComplexNumber& x){
    double a = realPart;
    double b = imaginePart;
    realPart =  a * x.realPart - b * x.imaginePart;
    imaginePart = a * x.imaginePart + b * x.realPart;
}

void ComplexNumber::operator /=(ComplexNumber& x){
    ComplexNumber xMinus(x.realPart, x.imaginePart * -1);
    double a = realPart;
    double b = imaginePart;
    double down = x.realPart * x.realPart + x.imaginePart * x.imaginePart;
    realPart = (a * xMinus.realPart - b * xMinus.imaginePart) / down;
    imaginePart = (a * xMinus.imaginePart + b * xMinus.realPart) / down;
}

ComplexNumber ComplexNumber::operator +(ComplexNumber& x){
    ComplexNumber tempt;
    tempt.realPart = realPart + x.realPart;
    tempt.imaginePart = imaginePart + x.imaginePart;
    return tempt;
}

ComplexNumber ComplexNumber::operator -(ComplexNumber& x){
    ComplexNumber tempt;
    tempt.realPart = realPart - x.realPart;
    tempt.imaginePart = imaginePart - x.imaginePart;
    return tempt;
}

ComplexNumber ComplexNumber::operator *(ComplexNumber& x){
    ComplexNumber tempt;
    double a = realPart;
    double b = imaginePart;
    tempt.realPart =  a * x.realPart - b * x.imaginePart;
    tempt.imaginePart = a * x.imaginePart + b * x.realPart;
    return tempt;
}

ComplexNumber ComplexNumber::operator /(ComplexNumber& x){
    ComplexNumber tempt;
    ComplexNumber xMinus(x.realPart, x.imaginePart * -1);
    double a = realPart;
    double b = imaginePart;
    double down = x.realPart * x.realPart + x.imaginePart * x.imaginePart;
    tempt.realPart = (a * xMinus.realPart - b * xMinus.imaginePart) / down;
    tempt.imaginePart = (a * xMinus.imaginePart + b * xMinus.realPart) / down;
    return tempt;
}

void ComplexNumber::changeInRealAndImagine(double real, double imagine, double phase){
    if (phase <= 90)
    {
        imaginePart = imagine;
        realPart = real;
    }
        else if (phase <= 180)
        {
            imaginePart = imagine;
            realPart = -real;
        }
            else if (phase <= 270)
            {
                imaginePart = -imagine;
                realPart = -real;
            }
                else if (phase <= 360)
                {
                    imaginePart = -imagine;
                    realPart = real;
                }
}
