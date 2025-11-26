#ifndef TRUCK_H
#define TRUCK_H

#include <iostream>
#include "Color.h"


using namespace std;

class Truck{
    private:
        int position;
        int velocity;
        int road;
        int colorCode;
    public:
        Truck(int colorCode);
        void draw();
        void move(int pos);
        void whiteSpace(int qtd);
        void statistics(int passo);
        int getPosition();
        unsigned int accelerate();
        unsigned int roadState();
        int color();
        
};


#endif