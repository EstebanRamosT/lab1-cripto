#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <string>
#include <iostream>
using namespace std;

class Transaccion {
private:
    string token;      // Identificador único alfanumérico
    string fecha_hora; // Fecha y hora de la transacción

public:
    Transaccion();
    Transaccion(string token, string fecha_hora);

    // Método virtual puro -> hace la clase abstracta
    virtual int getTipo() = 0;

    string print();

    // Getters
    string getToken() const;
    string getFechaHora() const;

    // Setters
    void setToken(string token);
    void setFechaHora(string fecha_hora);

    // Destructor virtual (buena práctica en clases abstractas)
    virtual ~Transaccion() {}
};

#endif