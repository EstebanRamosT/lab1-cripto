#ifndef CRIPTOMONEDAINTERFACE_H
#define CRIPTOMONEDAINTERFACE_H

#include "CriptoMoneda.h"

class CriptoMonedaInterface {
public:
    virtual void crearMoneda(CriptoMoneda moneda) = 0;
    virtual void verMonedas() = 0;
    virtual void editarMoneda() = 0;
    virtual void eliminarMoneda() = 0;
    virtual ~CriptoMonedaInterface() {}
};

#endif
