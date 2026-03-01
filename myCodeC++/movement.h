#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <iostream>
#include <string>
#include "transaction.h"
#include "cryptocurrency.h"

class Movement {

    private:

        Cryptocurrency coin;
        Transaction* transaction;
        double value;

    public:

        Movement();
        Movement(Cryptocurrency, string, string, int, double);

        double getValue();
        void setValue(double);

        Cryptocurrency getCoin();

        Transaction* getTransaction();
        

        friend ostream& operator<<( ostream&, Movement );

        ~Movement();
};

#endif