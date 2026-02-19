#include "Monedero.h"

Monedero::Monedero() {}

vector<CriptoMoneda> Monedero::getMonedas() const { return monedas; }
vector<Movimiento>& Monedero::getMovimientos() { return movimientos; }

// --- CriptoMonedaInterface ---
void Monedero::crearMoneda() {
    // Lógica pendiente
}
void Monedero::verMonedas() {
    // Lógica pendiente
}
void Monedero::editarMoneda() {
    // Lógica pendiente
}
void Monedero::eliminarMoneda() {
    // Lógica pendiente
}

// --- MovimientoInterface ---
void Monedero::enviarMoneda() {
    // Lógica pendiente
}
void Monedero::recibirMoneda() {
    // Lógica pendiente
}
string Monedero::verMovimientos() {
    // Lógica pendiente
    return "";
}
