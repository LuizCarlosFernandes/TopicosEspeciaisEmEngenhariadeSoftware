#ifndef COLOR_H
#define COLOR_H

#define gray   "\033[30;10m"			// Cinza
#define yellow  "\033[33;10m"			// Amarelo
#define green   "\033[32m"				// Verde
#define red     "\033[31;1m"			// Vermelho
#define blue	"\033[34;10m"			// Azul
#define purple	"\033[35;10m"			// Roxo
#define purpleb	"\033[35;7m"			//Backgroud roxo
#define default "\033[m"				// Retorna ao normal


class Color{

public:

Color();
void ajustarcor(int texto, int fundo);
void resetarcor(void);

};

#endif