#include "monedero.h"
#include <iostream>
using namespace std;

int main() {
    Monedero monedero;

    CriptoMoneda bitcoin("BTC", "Bitcoin");
    CriptoMoneda ethereum("ETH", "Ethereum");
    CriptoMoneda ripple("RIPPLE", "Ripple");

    monedero.crearMoneda(bitcoin);
    monedero.crearMoneda(ethereum);
    monedero.crearMoneda(ripple);

// 6 de Recibir
    monedero.recibirMoneda(bitcoin,  "token0001", "2025-02-19 08:00", 10);
    monedero.recibirMoneda(bitcoin,  "token0002", "2025-02-19 08:30", 5);
    monedero.recibirMoneda(ethereum, "token0003", "2025-02-19 09:00", 20);
    monedero.recibirMoneda(ethereum, "token0004", "2025-02-19 09:30", 8);
    monedero.recibirMoneda(ripple,   "token0005", "2025-02-19 10:00", 100);
    monedero.recibirMoneda(ripple,   "token0006", "2025-02-19 10:30", 50);

// 4 de Enviar
    monedero.enviarMoneda(bitcoin,  "token0007", "2025-02-19 11:00", 4);
    monedero.enviarMoneda(ethereum, "token0008", "2025-02-19 11:30", 6);
    monedero.enviarMoneda(ripple,   "token0009", "2025-02-19 12:00", 30);
    monedero.enviarMoneda(ripple,   "token0010", "2025-02-19 12:30", 20);
    
    cout << monedero.verMovimientos() << endl;
    
    return 0;
}