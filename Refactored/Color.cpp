
#include <iostream>
#include "Color.h"
using namespace std;

Color::Color(){}

void Color::ajustarcor(int cor, int fundo)
{
    cout << "\033[" << cor << ";" << fundo << "m";
}

void Color::resetarcor(void)
{
    cout << "\033[m";
}