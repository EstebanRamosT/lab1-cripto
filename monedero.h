#ifndef MONEDERO_H
#define MONEDERO_H

#include "CriptoMonedaInterface.h"
#include "MovimientoInterface.h"
#include "CriptoMoneda.h"
#include "Movimiento.h"
#include <vector>
using namespace std;

class Monedero : public CriptoMonedaInterface, public MovimientoInterface {
private:
    vector<CriptoMoneda> monedas;
    vector<Movimiento> movimientos;

public:
    Monedero();

    // Getters & Setters
    vector<CriptoMoneda> getMonedas() const;
    vector<Movimiento>& getMovimientos();

    // Métodos de CriptoMonedaInterface
    void crearMoneda() override;
    void verMonedas() override;
    void editarMoneda() override;
    void eliminarMoneda() override;

    // Métodos de MovimientoInterface
    void enviarMoneda() override;
    void recibirMoneda() override;
    string verMovimientos() override;
};

#endif