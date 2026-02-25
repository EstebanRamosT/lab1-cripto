#ifndef CRYPTOCURRENCY_H
#define  CRYPTOCURRENCY_H
#include <string>
#include <iostream>
using namespace std;




class Cryptocurrency {

    private:

        string id;
        string name;
    
    public:
    
        Cryptocurrency();
        Cryptocurrency(string, string);

        string getID();
        void setID(string);

        string getName();
        void setName(string);

        friend ostream& operator<<( ostream&, Cryptocurrency);

};



#endif