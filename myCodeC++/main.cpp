#include <iostream>
#include <string>
#include "wallet.h"

using namespace std;


int main(){


    // cout << "-----MENU------\n";
    // cout << "1. Transacciones pedidas por el Laboratorio\n";
    // cout << "2. Crear nueva moneda\n";
    // cout << "3. Editar Moneda\n";
    // cout << "4. Eliminar Moneda\n";
    // cout << "5. Enviar Moneda\n";
    // cout << "6. Recibir Moneda\n";
    // cout << "7. Salir\n";

    Wallet W;

    Cryptocurrency btc("BTC", "Bitcoin");
    Cryptocurrency eth("ETH", "Ethereum");
    Cryptocurrency ripple("RIPPLE", "Ripple");

    W.createCoin(btc);
    W.createCoin(eth);
    W.createCoin(ripple);

    W.receiveCoin(btc, "token0001", "2025-02-19 08:00", 40);
    W.receiveCoin(eth, "token0002", "2025-02-19 08:10", 200);
    W.receiveCoin(ripple, "token0003", "2025-02-19 08:20", 70);
    W.receiveCoin(btc, "token0004", "2025-02-19 08:30", 50);
    W.receiveCoin(ripple, "token0005", "2025-02-19 08:40", 120);
    W.receiveCoin(btc, "token0006", "2025-02-19 08:50", 93);

    W.sendCoin(btc, "token0007", "2025-02-19 09:00", 50);
    W.sendCoin(ripple, "token0008", "2025-02-19 09:10", 30);
    W.sendCoin(eth, "token0009", "2025-02-19 09:20", 10);
    W.sendCoin(btc, "token0010", "2025-02-19 09:30", 20);

    cout << W.viewMovements()<< endl;


    return 0;


};