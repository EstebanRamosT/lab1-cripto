#ifndef CRIPTOMONEDA_H
#define CRIPTOMONEDA_H

#include <string>
#include <iostream>
using namespace std;

class CriptoMoneda {
private:
    string identificador;  
    string nombre;         

public:
    CriptoMoneda();
    CriptoMoneda(string , string );

    // Getters
    string getIdentificador() const;
    string getNombre() const;

    // Setters
    void setIdentificador(string );
    void setNombre(string );

    // Sobrecarga del operador <<
    friend ostream& operator<<(ostream& os, const CriptoMoneda& moneda);
};

#endif
