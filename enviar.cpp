#include "enviar.h"

Enviar::Enviar() {}

Enviar::Enviar(string token, string fecha_hora)
    : Transaccion(token, fecha_hora) {}

int Enviar::getTipo() { return 1; }