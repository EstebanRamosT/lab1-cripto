#ifndef MOVIMIENTOINTERFACE_H
#define MOVIMIENTOINTERFACE_H

#include "CriptoMoneda.h"

#include <string>
using namespace std;

class MovimientoInterface {
public:
    virtual void enviarMoneda(CriptoMoneda moneda, string token, string fecha_hora, double valor) = 0;
    virtual void recibirMoneda(CriptoMoneda moneda, string token, string fecha_hora, double valor) = 0;
    virtual string verMovimientos() = 0;
    virtual ~MovimientoInterface() {}
};

#endif