#include "transaction.h"
#include <string>
#include <iostream>

using namespace std;

Transaction::Transaction(){}

Transaction::Transaction(string t, string d){
    this->token=t;
    this->date=d;
}

string Transaction::print(){
    return "Token: " + token + " | Fecha: " + date;
}

string Transaction::getToken(){
    return this->token;
}

void Transaction::setToken(string t){
    this->token=t;
}

string Transaction::getDate(){
    return this->date;
}

void Transaction::setDate(string d){
    this->date=d;
}


