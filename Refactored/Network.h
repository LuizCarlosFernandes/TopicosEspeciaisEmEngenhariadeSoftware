#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include "Network.h"

#include "Color.h"

class Network{
    private:
    public:
        Network();
        void transmitir(unsigned int passo, unsigned int color, unsigned int position, unsigned int velocity, unsigned int pista, unsigned int padding);
        unsigned int receber(void);
        unsigned int processar(unsigned int resultado);
};
#endif