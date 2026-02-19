#ifndef MOVIMIENTOINTERFACE_H
#define MOVIMIENTOINTERFACE_H

#include <string>
using namespace std;

class MovimientoInterface {
public:
    virtual void enviarMoneda() = 0;
    virtual void recibirMoneda() = 0;
    virtual string verMovimientos() = 0;
    virtual ~MovimientoInterface() {}
};

#endif