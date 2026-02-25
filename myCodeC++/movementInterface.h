#ifndef MOVEMENT_INTERFACE_H
#define MOVEMENT_INTERFACE_H

#include "cryptocurrency.h"
#include <string>
using namespace std;

class MovementInterface {
    public:
        virtual void sendCoin(Cryptocurrency coin, string token, string date, double value) = 0;
        virtual void receiveCoin(Cryptocurrency coin, string token, string date, double value) = 0;
        virtual string viewMovements() = 0;
};

#endif