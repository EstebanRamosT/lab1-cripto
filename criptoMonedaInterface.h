#ifndef CRIPTOMONEDAINTERFACE_H
#define CRIPTOMONEDAINTERFACE_H

class CriptoMonedaInterface {
public:
    virtual void crearMoneda() = 0;
    virtual void verMonedas() = 0;
    virtual void editarMoneda() = 0;
    virtual void eliminarMoneda() = 0;
    virtual ~CriptoMonedaInterface() {}
};

#endif
