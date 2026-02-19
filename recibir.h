#ifndef RECIBIR_H
#define RECIBIR_H

#include "Transaccion.h"

class Recibir : public Transaccion {
public:
    Recibir();
    Recibir(string token, string fecha_hora);

    int getTipo() override; // Retorna 2
};

#endif