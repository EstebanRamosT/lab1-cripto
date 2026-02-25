#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>

using namespace std;

class Transaction {

    private: 

        string token;
        string date;
    
    public:

        Transaction();
        Transaction(string, string);
        
        virtual int getType() = 0;

        string print();

        string getToken();
        void setToken(string);

        string getDate();
        void setDate(string);
};

#endif