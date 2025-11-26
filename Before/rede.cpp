#include <iostream>
#include "Cores.h"
#include "pacote.h"

using namespace std;
unsigned int rede;

void transmitir(unsigned int passo, unsigned int color, unsigned int position, unsigned int velocity, unsigned int pista, unsigned int padding)
{
	cout << "Transmitindo dados... \n";
	unsigned int local = empacotar(passo, color, position, velocity, pista, padding); //Codificando dados
	cout << "\033[" << color << ";07m" << local << default << endl;
	rede = local; // Atribuindo valor a rede
}

unsigned int receber(void)
{
	unsigned int resultado = rede; //Recebendo dados da rede

	// Criando mascaras para 1, 4, 7 e 8 bits.
	unsigned int mascara4 = 0; mascara4 = ~mascara4; mascara4 = mascara4 >> 28;
	unsigned int mascara1 = 1;
	unsigned int mascara7 = 0; mascara7 = ~mascara7; mascara7 = mascara7 >> 25;
	unsigned int mascara8 = 0; mascara8 = ~mascara8; mascara8 = mascara8 >> 24;

	//Desempacotando resultado em pista, velocidade, posição, cor e passo
	resultado = resultado >> 4;
	unsigned int oil = resultado & mascara1;
	resultado = resultado >> 1;
	unsigned int velocidade = resultado & mascara4;
	resultado = resultado >> 4;
	unsigned int posição = resultado & mascara7;
	resultado = resultado >> 7;
	unsigned int cor = resultado & mascara8;
	resultado = resultado >> 8;
	unsigned int frame = resultado;

	cout << "Recebendo dados...";
	ajustarcor(cor, 10); cout << "\nFrame "; resetarcor();
		ajustarcor(cor, 07); cout << " " << frame << " " ; resetarcor();
		ajustarcor(cor, 10); cout << " Pos "; resetarcor();
		ajustarcor(cor, 07); cout << " " << posição << " "; resetarcor();
		ajustarcor(cor, 10); cout << " Vel "; resetarcor();
		ajustarcor(cor, 7); cout << " " << velocidade << " "; resetarcor();
		ajustarcor(cor, 10); cout << " Oil "; resetarcor();
	if (oil == 1)
		{ajustarcor(cor, 07); cout << " True \n"; resetarcor();}
	else
		{ajustarcor(cor, 07); cout << " False \n"; resetarcor();}
	return rede;
}

unsigned int processar(unsigned int resultado) //Processa os dados recebidos da função receber e calcula a proxima posição
{

	unsigned int mascara4 = 0; mascara4 = ~mascara4; mascara4 = mascara4 >> 28;
	unsigned int mascara1 = 1;
	unsigned int mascara7 = 0; mascara7 = ~mascara7; mascara7 = mascara7 >> 25;
	unsigned int mascara8 = 0; mascara8 = ~mascara8; mascara8 = mascara8 >> 24;

	unsigned int oleo, velocidade, posicaoATUAL, posicaoNOVA;

	//Decodificando os dados da rede
	resultado = resultado >> 4;
	oleo = resultado & mascara1;
	resultado = resultado >> 1;
	velocidade = resultado & mascara4;
	resultado = resultado >> 4;
	posicaoATUAL = resultado & mascara7;
	resultado = resultado >> 7;
	unsigned int cor = resultado & mascara8;
	cout << "Processando dados...\n";
	posicaoNOVA = posicaoATUAL + velocidade - oleo; //Calculando posição nova.
	ajustarcor(cor, 10);
	cout << "Proxima posição: " << posicaoNOVA << endl; resetarcor();
	return posicaoNOVA;
}