#ifndef WALLET_H
#define WALLET_H

#include <iostream>
#include <vector>
#include "cryptocurrency.h"
#include "movement.h"
#include "cryptocurrencyInterface.h" 
#include "movementInterface.h"

using namespace std;
class Wallet: public CryptocurrencyInterface, public MovementInterface {

    private:

        vector<Cryptocurrency> coins;
        vector<Movement*> movements;

    public:

        Wallet();
        
        void createCoin(Cryptocurrency) override;
        void viewCoin() override;
        void editCoin() override;
        void deleteCoin() override;
        
        void sendCoin(Cryptocurrency, string, string, double) override;
        void receiveCoin(Cryptocurrency, string, string, double) override;
        string viewMovements() override;
};

#endif