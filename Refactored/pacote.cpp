unsigned int empacotar(unsigned int passo, unsigned int color, unsigned int position, unsigned int velocity, unsigned int pista, unsigned int padding)
{
	unsigned int resultado = 0;

	resultado = resultado << 8;
	resultado = resultado | passo; // Adicionando passo ao n�mero "codificado"

	resultado = resultado << 8;
	resultado = resultado | color; // Adiocionando a informa��o de cor ao caminh�o
	resultado = resultado << 7;
	resultado = resultado | position; //Adicionando a informa��o de posi��o atual do caminh�o
	resultado = resultado << 4;
	resultado = resultado | velocity; //Adicionando a informa��o de velocidade do caminh�o
	resultado = resultado << 1;
	resultado = resultado | pista; //Adicionando a informa��o de condi��o de pista
	resultado = resultado << 4;
	resultado = resultado << padding; //Preencher lacunas nos bits.

	return resultado;
}
