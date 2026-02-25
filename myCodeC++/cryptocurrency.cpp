#include "cryptocurrency.h"
#include <string>
#include <iostream>

using namespace std;

Cryptocurrency::Cryptocurrency(){}

Cryptocurrency::Cryptocurrency(string i, string n){
    this->id=i;
    this->name=n;
}

string Cryptocurrency::getID(){
    return this->id;
}

void Cryptocurrency::setID(string i){
    this->id=i;
}

string Cryptocurrency::getName(){
    return this->name;
}

void Cryptocurrency::setName(string n){
    this->name=n;
}

ostream& operator<<(ostream& mssg, Cryptocurrency c1){
    mssg << "ID :" << c1.id << "name :" << c1.name;
    return mssg;
}
