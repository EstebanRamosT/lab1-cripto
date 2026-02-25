#include "send.h"
#include <string>
#include <iostream>

using namespace std;

Send::Send(){

}

Send::Send(string t, string d): Transaction(t, d){
    
}

int Send::getType(){
    return 1;
}