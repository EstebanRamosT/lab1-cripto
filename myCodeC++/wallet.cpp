#include "wallet.h"
#include <iostream>
#include <limits>

using namespace std;

Wallet::Wallet(){}

void Wallet::createCoin(Cryptocurrency coin){
    coins.push_back(coin);
} 

vector<Cryptocurrency> Wallet::getCoins(){
    return coins;
}

void Wallet::viewCoin(){  
    string text = "";
    for (int i = 0; i < coins.size(); i++){
        double balance = calculateBalance(coins[i].getID());
        text = text + "ID : " + coins[i].getID() + " | Name : " + coins[i].getName() + " | Value : " + to_string(balance) + "\n";
    };
    cout << text;
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void Wallet::editCoin(){    
    
    int opt;
    string change;
    cout << "What coin do you want edit ? \n";
    int optCoin = listCoins();
    if (optCoin >= 0 && optCoin < coins.size()){
        cout << "Edit ID (0) or Edit Name (1) \n";
        cin >> opt;
        if ( opt == 0) {
            cout << "What is your new ID ? \n";
            cin >> change;
            coins[optCoin].setID(change);
        } else if (opt == 1){
            cout << "What is your new Name ? \n";
            cin >> change;
            coins[optCoin].setName(change);
        } else {
            cout << "Invalid Number \n";
        }
    } else {
        cout << "Invalid Number \n";
    }

}

void Wallet::deleteCoin(){
    int opt;
    string change;
    cout << "What coin do you want delete ? \n";
    int optCoin = listCoins();
    if (optCoin >= 0 && optCoin < coins.size()){
        coins.erase(coins.begin() + optCoin);
    } else {
        cout << "Invalid Number \n";
    }
}


double Wallet::calculateBalance(string coinID){
    double balance = 0;
    for (int i = 0; i < movements.size(); i++){
        if (movements[i]->getCoin().getID() == coinID){
            if (movements[i]->getTransaction()->getType() == 1){
                balance -= movements[i]->getValue();
            } else {
                balance += movements[i]->getValue();
            };
        };
    };

    return balance;
}

int Wallet::listCoins(){
    for (int i = 0; i < coins.size(); i++){
        cout << i << ". " << coins[i].getID() << "\n";
    }
    int opt;
    cin >> opt;
    return opt;
}

void Wallet::sendCoin(Cryptocurrency coin, string token, string date, double value){
    double balance = calculateBalance(coin.getID());
    if (balance - value < 0){
        cout << "Insufficient balance \n";
        return;
    }
    movements.push_back(new Movement(coin, token, date, 1, value));
    
}

void Wallet::receiveCoin(Cryptocurrency coin, string token, string date, double value){
    movements.push_back(new Movement(coin, token, date, 2, value));
}

void Wallet::viewMovements(){
    string resultado = "";
        for ( int i = 0; i < movements.size(); i++){
            cout << *movements[i];
        }
}

Wallet::~Wallet(){
    for (int i = 0; i < movements.size(); i++){
        delete movements[i];
    }
}

    