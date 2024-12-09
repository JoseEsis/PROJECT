#include "Sistema.h"
#include <iostream>
#include <fstream>
using namespace std;
void Sistema::agregarPasajero(const Pasajero& pasajero) {
    listaPasajeros.push_back(pasajero);
    cout << "Pasajero agregado correctamente.\n";
}
void Sistema::mostrarPasajeros() const {
    if (listaPasajeros.empty()) {
        cout << "No hay pasajeros registrados.\n";
        return;
    }
    cout << "\nLista de Pasajeros:\n";
    for (const auto& pasajero : listaPasajeros) {
        pasajero.mostrarDatos();
        cout << "---------------------\n";
    }
}
void Sistema::agregarReserva(const Reserva& reserva) {
    listaReserva.push_back(reserva);
    cout << "Reserva agregada correctamente.\n";
}
void Sistema::mostrarReserva() const {
    if (listaReserva.empty()) {
        cout << "No hay reservas registradas.\n";
        return;
    }
    cout << "\nLista de Reservas:\n";
    for (const auto& Reserva : listaReserva) {
        Reserva.mostrarDatos();
        cout << "---------------------\n";
    }
}
void Sistema::guardarPasajerosEnArchivo(const string& nombreArchivo) const {
    ofstream archivo(nombreArchivo, ios::app); 

    if (!archivo.is_open()) 
	{
        cout << "No se pudo abrir el archivo para guardar los datos.\n";
        return;
    }

    for (const auto& pasajero : listaPasajeros) {
        archivo << "Nombre: " << pasajero.getNombre() << "\n";
        archivo << "DNI: " << pasajero.getDNI() << "\n";
        archivo << "Telefono: " << pasajero.getTelefono() << "\n";
        archivo << "Destino: " << pasajero.getDestino() << "\n";
        archivo << "---------------------\n";
    }

    archivo.close(); 
    cout << "Datos de los pasajeros guardados en el archivo " << nombreArchivo << " correctamente.\n";
}

void Sistema::cargarPasajerosDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);  

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo para leer los datos.\n";
        return;
    }

    string nombre, DNI, telefono, destino;
    string linea;
    
    while (getline(archivo, linea))
	{
  		if(linea.find("Nombre: ") == 0) 
		{  
            nombre = linea.substr(8);
            getline(archivo, linea); 
            DNI = linea.substr(5);   
            getline(archivo, linea); 
            telefono = linea.substr(10); 
            getline(archivo, linea);  
            destino = linea.substr(9);

        Pasajero pasajero(nombre, DNI, telefono, destino);
        listaPasajeros.push_back(pasajero);
        }
   }

    archivo.close();
}

void Sistema::guardarReservasEnArchivo(const string& nombreArchivo) const {
    ofstream archivo(nombreArchivo, ios::app); 

    if (!archivo.is_open()) 
	{
        cout << "No se pudo abrir el archivo para guardar los datos.\n";
        return;
    }

    for (const auto& reserva : listaReserva) {
        archivo << "Destino: " << reserva.getDestino() << "\n";
        archivo << "Fecha: " << reserva.getFecha() << "\n";
        archivo << "Orden de Asiento: " << reserva.getOrdenAsiento() << "\n";
        archivo << "Pago: "<<reserva.getPago() << "\n";
        archivo << "---------------------\n";
    }

    archivo.close(); 
    cout << "Datos de los pasajeros guardados en el archivo " << nombreArchivo << " correctamente.\n";
}

void Sistema::cargarReservasDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);  

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo para leer los datos.\n";
        return;
    }

    string destino, fecha, ordenAsiento;
    double pago; 
    string linea;
    
    while (getline(archivo, linea))
	{
  		if(linea.find("Destino: ") == 0) 
		{  
            destino = linea.substr(8);
            getline(archivo, linea); 
            fecha = linea.substr(7);   
            getline(archivo, linea); 
            ordenAsiento = linea.substr(18);
			getline(archivo, linea);
			string pagoStr = linea.substr(6);
			pago = stod(pagoStr);
            

        Reserva reserva(destino, fecha, ordenAsiento, pago);
        listaReserva.push_back(reserva);
        }
   }

    archivo.close();
}


