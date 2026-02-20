#ifndef ENVIAR_H
#define ENVIAR_H

#include "Transaccion.h"

class Enviar : public Transaccion {
public:
    Enviar();
    Enviar(string , string );

    int getTipo() override; // Retorna 1
};

#endif