#include <iostream>
#include "rede.h"
#include "cores.h"
using namespace std;


//Roxo = 35; Vermelho = 31; Amarelo = 33
//Background limpo = 10; background colorido 07

void espaçobranco(int);
void desenhar(int posição, int cor);

int main()
{
	srand(unsigned(time(NULL)));
	unsigned int posA = 0, posB = 0;
	unsigned int velocidadeA = (rand() % 10) + 1, velocidadeB = (rand() % 10 + 1);
	unsigned int pistaA = rand() % 1, pistaB = rand() % 1;
	unsigned int corA = 35, corB = 31;
	desenhar(posA, corA);
	int passo = 0;
	transmitir(passo, corA, posA, velocidadeA, pistaA, 0);
	do
	{
		
		unsigned int pistaA = rand() % 2, pistaB = rand() % 2;
		unsigned int velocidadeA = (rand() % 10) + 1, velocidadeB = (rand() % 10 + 1);

		system("cls");
		ajustarcor(33, 7);  cout << right; cout.width(60); cout << "Truck racing"; cout << left; cout.width(60); cout << " ";
		desenhar(posA, corA);
		desenhar(posB, corB);
		transmitir(passo, corA, posA, velocidadeA, pistaA, 0);
		posA = processar(receber());
		cout << "\n\n\n";
		transmitir(passo, corB, posB, velocidadeB, pistaB, 0);
		posB = processar(receber());
		passo = passo + 1;
		cout << system("pause");
	}
 while (posA <= 100 && posB <= 100);
	cout.setf(ios_base::fixed, ios_base::floatfield);//Ajustar números após virgula

	system("cls"); //Finalizando corrida.
	ajustarcor(33, 7);  cout << right; cout.width(60); cout << "Truck racing"; cout << left; cout.width(60); cout << " ";
	desenhar(posA, corA);
	desenhar(posB, corB);
	ajustarcor(33, 7);  cout << right; cout.width(60); cout << "Corrida Concluída"; cout << left; cout.width(60); cout << " "; resetarcor(); //Mostrando estatisticas
	cout << "\n\n";
	resetarcor(); ajustarcor(33, 7);  cout << "\n\n Passos "; resetarcor(); ajustarcor(33, 10); cout << " " << passo;
	cout << "\n\n";
	ajustarcor(corA, 7); cout << " Posição ";
	resetarcor();  ajustarcor(corA, 10); cout << " " << posA << " "; ajustarcor(corA, 7); cout << " Velocidade Média "; 
	float velocidademediaA = float(posA) / float(passo);//Calculando velocidade media do caminhão A
	resetarcor();  ajustarcor(corA, 10); cout << fixed; cout.precision(2); cout << "  " << velocidademediaA << endl;
	cout << "\n";
	ajustarcor(corB, 7); cout << " Posição "; 
	resetarcor(); ajustarcor(corB, 10); cout << " " << posB << " "; ajustarcor(corB, 7); cout << " Velocidade Média "; 
	float velocidademediaB = float(posB) / float(passo);//Calculando velocidade media do caminhão B
	resetarcor(); ajustarcor(corB, 10); cout << fixed ; cout.precision(2); cout << "  " << velocidademediaB << endl;
	resetarcor(); cout << "\n\n\n";
	ajustarcor(33, 7);  cout << right; cout.width(60); cout << " "; cout << left; cout.width(60); cout << " "; resetarcor();
	system("pause");
}

void desenhar(int posição, int cor)
{
	resetarcor();
	ajustarcor(cor, 10); //Adicionando cor do caminhão
	cout << "\n\n";
	espaçobranco(posição);  cout << "\xDB\xDB\xDB\xDB\xDB\xDB \xDB\xDB\xDC\n";
	espaçobranco(posição);  cout << "\xDFOO\xDF\xDF\xDF\xDF\xDFO\xDF\n";  //DESENHANDO O CAMINHÃO
	cout << "---------------------------------------------------------------------------------------------------|--------------------\n";
	cout << right; cout.width(102); cout << "100\n";
	resetarcor();
}

void espaçobranco(int qtd) { while (qtd-- > 0) cout << ' '; }
