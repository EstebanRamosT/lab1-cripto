#ifndef SEND_H
#define SEND_H

#include <iostream>
#include <string>
#include "transaction.h"

using namespace std;

class Send : public Transaction{

    public:
        Send();
        Send(string, string);

        int getType();
};

#endif