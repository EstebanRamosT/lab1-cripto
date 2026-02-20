#include "movimiento.h"

Movimiento::Movimiento() : transaccion(nullptr), valor(0) {}

Movimiento::Movimiento(CriptoMoneda moneda, string token, string fecha_hora, int tipo, double valor) {
    this->moneda = moneda;
    this->valor = valor;
    if (tipo == 1)
        this->transaccion = new Enviar(token, fecha_hora);
    else
        this->transaccion = new Recibir(token, fecha_hora);
}

CriptoMoneda Movimiento::getMoneda() const { return moneda; }
Transaccion* Movimiento::getTransaccion() const { return transaccion; }
double Movimiento::getValor() const { return valor; }

void Movimiento::setMoneda(CriptoMoneda moneda) { this->moneda = moneda; }
void Movimiento::setValor(double valor) { this->valor = valor; }

ostream& operator<<(ostream& os, const Movimiento& mov) {
    string tipo = (mov.transaccion->getTipo() == 1) ? "ENVIAR" : "RECIBIR";
    os << "[" << tipo << "] " << mov.moneda
       << " | Valor: " << mov.valor
       << " | " << mov.transaccion->print();
    return os;
}

string Movimiento::print() {
    string tipo = (transaccion->getTipo() == 1) ? "ENVIAR" : "RECIBIR";
    return "[" + tipo + "] Valor: " + to_string(valor) + 
           " | " + transaccion->print();
}

Movimiento::~Movimiento() {
    delete transaccion;
}