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
    vector<Movimiento*> movimientos; // punteros

public:
    Monedero();

    // Getters & Setters
    vector<CriptoMoneda> getMonedas() const;
    vector<Movimiento*>& getMovimientos();

    // Métodos de CriptoMonedaInterface
    void crearMoneda(CriptoMoneda ) override;
    void verMonedas() override;
    void editarMoneda() override;
    void eliminarMoneda() override;
    

    // Métodos de MovimientoInterface
    void enviarMoneda(CriptoMoneda , string , string , double ) override;
    void recibirMoneda(CriptoMoneda , string , string , double ) override;
    string verMovimientos() override;
};

#endif