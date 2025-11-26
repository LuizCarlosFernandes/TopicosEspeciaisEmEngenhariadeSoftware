#include <iostream>
#include "Network.h"
#include "Color.h"
#include "Truck.h"
using namespace std;


//Roxo = 35; Vermelho = 31; Amarelo = 33
//Background limpo = 10; background colorido 07

void endRace(Truck truckA, Truck truckB, Color color, int passo);

int main()
{
	Network net;
	Color color;
	Truck truckA(35);
	Truck truckB(31);
	int passo = 0;
	do
	{
		system("clear");
		color.ajustarcor(33, 7);  cout << right; cout.width(60); cout << "Truck racing"; cout << left; cout.width(60); cout << " ";

		
		truckA.draw();
		truckB.draw();

		
		net.transmitir(passo, truckA.color(), truckA.getPosition(), truckA.accelerate(), truckA.roadState(), 0);
		truckA.move(net.processar(net.receber()));
		
		cout << "\n\n\n";
		
		net.transmitir(passo, truckB.color(), truckB.getPosition(), truckB.accelerate(), truckB.roadState(), 0);
		truckB.move(net.processar(net.receber()));
		
		passo = passo + 1;
		cin.get();
	}
 while (truckA.getPosition() <= 100 && truckB.getPosition()  <= 100); 
	cout.setf(ios_base::fixed, ios_base::floatfield);//Ajustar números após virgula

	endRace(truckA, truckB, color, passo);

	truckA.statistics(passo);
	truckB.statistics(passo);

	cout << "\n\n";
	color.ajustarcor(33, 7);  cout << right; cout.width(60); cout << " "; cout << left; cout.width(60); cout << " "; color.resetarcor();
	cin.get();
}

void endRace(Truck truckA, Truck truckB, Color color, int passo){
	system("clear");
	color.ajustarcor(33, 7);  cout << right; cout.width(60); 
	cout << "Truck racing"; cout << left; cout.width(60); cout << " ";
	truckA.draw();
	truckB.draw();
	color.ajustarcor(33, 7);  cout << right; cout.width(60); 
	cout << "Corrida Concluida"; cout << left; cout.width(60); cout << " ";
	color.resetarcor();

	cout << "\n\n";
	color.resetarcor(); color.ajustarcor(33, 7);  cout << "\n\n Passos "; 
	color.resetarcor(); color.ajustarcor(33, 10); cout << " " << passo;
	cout << "\n\n";
}



