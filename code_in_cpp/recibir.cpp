#include "recibir.h"

Recibir::Recibir() {}

Recibir::Recibir(string token, string fecha_hora)
    : Transaccion(token, fecha_hora) {}

int Recibir::getTipo() { return 2; }
