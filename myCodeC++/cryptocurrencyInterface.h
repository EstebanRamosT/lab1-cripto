#ifndef CRYPTOCURRENCYINTERFACE_H
#define CRYPTOCURRENCYINTERFACE_H

#include <string>
#include "cryptocurrency.h"

class CryptocurrencyInterface {

    public :

        virtual void createCoin(Cryptocurrency) = 0;
        virtual void viewCoin() = 0;
        virtual void editCoin() = 0;
        virtual void deleteCoin() = 0;
    };

#endif