#include "Truck.h"


Truck::Truck(int colorCode)
{
    this->position = 0;
    this->velocity = 0;
    this->road = 0;
    this->colorCode = colorCode;

	srand(unsigned(time(NULL)));
}

void Truck::draw()
{
    Color color;

	color.resetarcor();
	color.ajustarcor(colorCode, 10); //Adicionando cor do caminh�o
	cout << "\n\n";
	whiteSpace(position);  std::cout << "██████ ██▄\n";
    whiteSpace(position);  std::cout << "▀OO▀▀▀▀▀O▀\n";
	cout << "---------------------------------------------------------------------------------------------------|--------------------\n";
	cout << right; cout.width(102); cout << "100\n";
	color.resetarcor();
}

void Truck::statistics(int passo)
{
	Color color;
	color.ajustarcor(colorCode, 7); cout << " Posição ";
	color.resetarcor();  color.ajustarcor(colorCode, 10); 
	
	cout << " " << position << " "; color.ajustarcor(colorCode, 7); 
	cout << " Velocidade Média "; 
	float velocidademediaA = float(position) / float(passo);//Calculando velocidade media do caminh�o A
	color.resetarcor();  color.ajustarcor(colorCode, 10); 
	cout << fixed; cout.precision(2); 
	cout << "  " << velocidademediaA << endl;
	cout << "\n";
}

void Truck::move(int pos)
{
	this->position = pos;
}

int Truck:: getPosition() 
{
	return this->position;
}

unsigned int Truck::accelerate()
{	
	return (rand() % 10) + 1;
}

unsigned int Truck::roadState()
{

	return rand() % 1;
}

int Truck::color() {
	return this->colorCode;
}

void Truck::whiteSpace(int qtd) { while (qtd-- > 0) cout << ' '; }
