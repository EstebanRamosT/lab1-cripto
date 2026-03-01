#include "receive.h"
#include <string>
#include <iostream>

using namespace std;

Receive::Receive(){
}

Receive::Receive(string t, string d): Transaction(t, d){    
}

int Receive::getType(){
    return 2;
}