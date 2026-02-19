#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H

#include "CriptoMoneda.h"
#include "Transaccion.h"
#include "Enviar.h"
#include "Recibir.h"
#include <iostream>
using namespace std;

class Movimiento {
private:
    CriptoMoneda moneda;      // Agregación
    Transaccion* transaccion; // Agregación (puntero por ser clase abstracta)
    double valor;

public:
    Movimiento();
    // tipo: 1 = Enviar, 2 = Recibir
    Movimiento(CriptoMoneda moneda, string token, string fecha_hora, int tipo, double valor);

    // Getters
    CriptoMoneda getMoneda() const;
    Transaccion* getTransaccion() const;
    double getValor() const;

    // Setters
    void setMoneda(CriptoMoneda moneda);
    void setValor(double valor);

    // Sobrecarga del operador <<
    friend ostream& operator<<(ostream& os, const Movimiento& mov);

    ~Movimiento();
};

#endif