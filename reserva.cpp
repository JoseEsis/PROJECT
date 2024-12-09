#include "Reserva.h"
#include <iostream>
using namespace std;

Reserva::Reserva(const std::string& destino, const string& fecha, const string& ordenAsiento, const double& pago)
    : destino(destino), fecha(fecha), ordenAsiento(ordenAsiento), pago(pago) {}

double Reserva::getPago() const {
    return pago;
}
string Reserva::getDestino() const {
    return destino;
}
string Reserva::getFecha() const {
    return fecha;
}

string Reserva::getOrdenAsiento() const {
    return ordenAsiento;
}

void Reserva::mostrarDatos() const {

    cout << "Datos de la Reserva:\n";
    cout << "Destino: " << destino << "\n";
    cout << "Fecha: " << fecha << "\n";
    cout << "Orden de Asiento: " << ordenAsiento << "\n";
    cout << "Pago: " << pago << "\n";
    
}
