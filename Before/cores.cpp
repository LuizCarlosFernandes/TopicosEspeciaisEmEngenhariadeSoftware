#include <iostream>
#include "cores.h"
using namespace std;

void ajustarcor(int texto, int fundo)
{
	cout << "\033[" << texto << ";" << fundo << "m";
}

void resetarcor(void)
{
	cout << default;
}