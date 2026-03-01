#include "wallet.h"
#include <iostream>
using namespace std;

int main(){

    Wallet W;


    W.createCoin(Cryptocurrency("BTC", "Bitcoin"));
    W.createCoin(Cryptocurrency("ETH", "Ethereum"));
    W.createCoin(Cryptocurrency("RIPPLE", "Ripple"));

    W.receiveCoin(Cryptocurrency("BTC", "Bitcoin"),    "token0001", "2025-02-19 08:00", 40);
    W.receiveCoin(Cryptocurrency("ETH", "Ethereum"),   "token0002", "2025-02-19 08:10", 200);
    W.receiveCoin(Cryptocurrency("RIPPLE", "Ripple"),  "token0003", "2025-02-19 08:20", 70);
    W.receiveCoin(Cryptocurrency("BTC", "Bitcoin"),    "token0004", "2025-02-19 08:30", 50);
    W.receiveCoin(Cryptocurrency("RIPPLE", "Ripple"),  "token0005", "2025-02-19 08:40", 120);
    W.receiveCoin(Cryptocurrency("BTC", "Bitcoin"),    "token0006", "2025-02-19 08:50", 93);

    W.sendCoin(Cryptocurrency("BTC", "Bitcoin"),       "token0007", "2025-02-19 09:00", 50);
    W.sendCoin(Cryptocurrency("RIPPLE", "Ripple"),     "token0008", "2025-02-19 09:10", 30);
    W.sendCoin(Cryptocurrency("ETH", "Ethereum"),      "token0009", "2025-02-19 09:20", 10);
    W.sendCoin(Cryptocurrency("BTC", "Bitcoin"),       "token0010", "2025-02-19 09:30", 20);

    int opc;
    do {
        cout << "\n===== CRYPTO WALLET =====\n";
        cout << "1. View coins\n";
        cout << "2. View movements\n";
        cout << "3. Add coin\n";
        cout << "4. Edit coin\n";
        cout << "5. Delete coin\n";
        cout << "6. Send coin\n";
        cout << "7. Receive coin\n";
        cout << "0. Exit\n";
        cout << "Option: ";
        cin >> opc;

        switch(opc){
            case 1:
                W.viewCoin();
                break;
            case 2:
                W.viewMovements();
                break;
            case 3: {
                string id, name;
                cout << "ID: ";
                cin >> id;
                cout << "Name: ";
                cin >> name;
                W.createCoin(Cryptocurrency(id, name));
                cout << "Coin added!\n";
                break;
            }
            case 4:
                W.editCoin();
                break;
            case 5:
                W.deleteCoin();
                break;
            case 6: {
                string id, token, date;
                double value;
                int optCoin = W.listCoins();
                cout << "Token: ";
                cin >> token;
                cout << "Date: ";
                cin >> date;
                cout << "Value: ";
                cin >> value;
                W.sendCoin(W.getCoins()[optCoin], token, date, value);
                break;
            }
            case 7: {
                string id, token, date;
                double value;
                int optCoin = W.listCoins();
                cout << "Token: ";
                cin >> token;
                cout << "Date: ";
                cin >> date;
                cout << "Value: ";
                cin >> value;
                W.receiveCoin(W.getCoins()[optCoin], token, date, value);
                break;
            }
            case 0:
                cout << "Bye!\n";
                break;
            default:
                cout << "Invalid option\n";
        }
    } while(opc != 0);

    return 0;
}