#include "wallet.h"
#include <iostream>

using namespace std;

Wallet::Wallet(){}

void Wallet::createCoin(Cryptocurrency coin){
    coins.push_back(coin);
} 

void Wallet::viewCoin(){
    
}

void Wallet::editCoin(){
    
}

void Wallet::deleteCoin(){
    
}



void Wallet::sendCoin(Cryptocurrency coin, string token, string date, double value){
    movements.push_back(new Movement(coin, token, date, 1, value));
}

void Wallet::receiveCoin(Cryptocurrency coin, string token, string date, double value){
    movements.push_back(new Movement(coin, token, date, 2, value));
}

string Wallet::viewMovements(){
    string resultado = "";
    for ( int i = 0; i < coins.size(); i++){
        double balance = 0;
        for (int j = 0; j< movements.size(); j++){
            if (movements[j]->getCoin().getID() == coins[i].getID()){
                if (movements[j]->getTransaction()->getType() == 1){
                    balance -= movements[j]->getValue();
                } else {
                    balance += movements[j]->getValue();
                }

            }
        }   
        resultado += "Coin :" + coins[i].getID() + " Value :" + to_string(balance) + "\n";
    }
    return resultado;
}

    