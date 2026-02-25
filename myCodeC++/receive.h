#ifndef RECEIVE_H
#define RECEIVE_H

#include <iostream>
#include <string>
#include "transaction.h"

using namespace std;

class Receive : public Transaction{

    public:
        Receive();
        Receive(string, string);

        int getType();

};

#endif