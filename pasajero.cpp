#include "Pasajero.h"
#include <iostream>
using namespace std;
Pasajero::Pasajero(const string& nombre, const string& DNI, 
                   const string& telefono, const string& destino)
    : nombre(nombre), DNI(DNI), telefono(telefono), destino(destino) {}

string Pasajero::getNombre() const {
    return nombre;
}

string Pasajero::getDNI() const {
    return DNI;
}

string Pasajero::getTelefono() const {
    return telefono;
}

string Pasajero::getDestino() const {
    return destino;
}
void Pasajero::mostrarDatos() const {
    cout << "Nombre: " << nombre << "\nDNI: " << DNI
              << "\nTelefono: " << telefono << "\nDestino: " << destino << "\n";
}
