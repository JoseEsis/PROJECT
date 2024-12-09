#ifndef PASAJERO_H
#define PASAJERO_H
#include <string>
using namespace std;

class Pasajero {
	private:
   		string nombre;
    	string DNI;
    	string telefono;
    	string destino;
	public:
    	Pasajero(const std::string& nombre, const std::string& DNI, const std::string& telefono, const std::string& destino);
    	string getNombre() const;
    	string getDNI() const;
    	string getTelefono() const;
    	string getDestino() const;
    	void mostrarDatos() const;
    
};

#endif
