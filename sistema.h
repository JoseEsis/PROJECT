#ifndef SISTEMA_H
#define SISTEMA_H
#include "Pasajero.h"
#include "Reserva.h"
#include <vector>
using namespace std;
class Sistema 
{
	private:
    	vector<Pasajero> listaPasajeros;
    	vector<Reserva> listaReserva;
	public:
    void agregarPasajero(const Pasajero& pasajero);
    void mostrarPasajeros() const;
    void agregarReserva(const Reserva& reserva); 
    void mostrarReserva() const;
    void guardarPasajerosEnArchivo(const string& nombreArchivo) const;
    void cargarPasajerosDesdeArchivo(const std::string& nombreArchivo);
    void guardarReservasEnArchivo(const string& nombreArchivo) const;
    void cargarReservasDesdeArchivo(const std::string& nombreArchivo);


};

#endif
