#include <iostream>
#include <string>
#include "movement.h"
#include "send.h"
#include "receive.h"

using namespace std;

Movement::Movement(){}

Movement::Movement(Cryptocurrency c, string t, string d,int type, double v){
    this ->coin = c;
    this ->value = v;
    
    if (type == 1){
        this->transaction = new Send(t, d);
    }else {
        this->transaction = new Receive(t, d);
    }
}

double Movement::getValue(){
    return this->value;
}

void Movement::setValue(double v){
    this ->value = v;
}

Cryptocurrency Movement::getCoin(){
    return this-> coin;
}

Transaction* Movement::getTransaction(){
    return this-> transaction;
}
ostream& operator<<(ostream& mssg, Movement m){
    string type;
    if ( m.transaction->getType() == 1){ 
        type = "Shipment";
    } else {
        type = "Received";
    }
    mssg << "[" << type << "] "
     << "Coin: " << m.coin.getID()
     << " | Value: " << m.value
     << " | " << m.transaction->print();
    return mssg;
}