#include "criptoMoneda.h"

CriptoMoneda::CriptoMoneda() {}

CriptoMoneda::CriptoMoneda(string identificador, string nombre) {
    this->identificador = identificador;
    this->nombre = nombre;
}

string CriptoMoneda::getIdentificador() const { return identificador; }
string CriptoMoneda::getNombre() const { return nombre; }

void CriptoMoneda::setIdentificador(string identificador) { this->identificador = identificador; }
void CriptoMoneda::setNombre(string nombre) { this->nombre = nombre; }

ostream& operator<<(ostream& os, const CriptoMoneda& moneda) {
    os << moneda.nombre << " (" << moneda.identificador << ")";
    return os;
}

