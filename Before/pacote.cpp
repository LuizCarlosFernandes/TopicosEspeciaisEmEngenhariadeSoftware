unsigned int empacotar(unsigned int passo, unsigned int color, unsigned int position, unsigned int velocity, unsigned int pista, unsigned int padding)
{
	unsigned int resultado = 0;

	resultado = resultado << 8;
	resultado = resultado | passo; // Adicionando passo ao número "codificado"

	resultado = resultado << 8;
	resultado = resultado | color; // Adiocionando a informação de cor ao caminhão
	resultado = resultado << 7;
	resultado = resultado | position; //Adicionando a informação de posição atual do caminhão
	resultado = resultado << 4;
	resultado = resultado | velocity; //Adicionando a informação de velocidade do caminhão
	resultado = resultado << 1;
	resultado = resultado | pista; //Adicionando a informação de condição de pista
	resultado = resultado << 4;
	resultado = resultado << padding; //Preencher lacunas nos bits.

	return resultado;
}
