#include "Monedero.h"

Monedero::Monedero() {}

vector<CriptoMoneda> Monedero::getMonedas() const { return monedas; }
vector<Movimiento*>& Monedero::getMovimientos() { return movimientos; }

// --- CriptoMonedaInterface ---
void Monedero::crearMoneda(CriptoMoneda moneda) {
    monedas.push_back(moneda);
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
void Monedero::enviarMoneda(CriptoMoneda moneda, string token, string fecha_hora, double valor) 
{
    movimientos.push_back(new Movimiento(moneda, token, fecha_hora, 1, valor));
}

void Monedero::recibirMoneda(CriptoMoneda moneda, string token, string fecha_hora, double valor) 
{
    movimientos.push_back(new Movimiento(moneda, token, fecha_hora, 2, valor));
}
string Monedero::verMovimientos() {
    string resultado = "";

    // Recorremos cada moneda para calcular su saldo individual
    for (int i = 0; i < monedas.size(); i++) {
        double saldo = 0;
        string id = monedas[i].getIdentificador();
        resultado += "\n=== " + monedas[i].getNombre() + " (" + id + ") ===\n";

        // Recorremos todos los movimientos buscando los de esta moneda
        for (int j = 0; j < movimientos.size(); j++) {
            if (movimientos[j]->getMoneda().getIdentificador() == id) {
            resultado += movimientos[j]->print() + "\n";
            if (movimientos[j]->getTransaccion()->getTipo() == 2)
            saldo += movimientos[j]->getValor();
            else
            saldo -= movimientos[j]->getValor();
    }
}
        resultado += "Saldo final: " + to_string(saldo) + " " + id + "\n";
    }
    return resultado;
}
