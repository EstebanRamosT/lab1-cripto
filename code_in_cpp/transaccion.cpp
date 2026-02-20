#include "transaccion.h"
Transaccion::Transaccion() {}

Transaccion::Transaccion(string token, string fecha_hora) {
    this->token = token;
    this->fecha_hora = fecha_hora;
}

string Transaccion::print() {
    return "Token: " + token + " | Fecha: " + fecha_hora;
}

string Transaccion::getToken() const { return token; }
string Transaccion::getFechaHora() const { return fecha_hora; }

void Transaccion::setToken(string token) { this->token = token; }
void Transaccion::setFechaHora(string fecha_hora) { this->fecha_hora = fecha_hora; }
