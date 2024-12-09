#ifndef RESERVA_H
#define RESERVA_H
#include <string>
using namespace std;

class Reserva {
private: 
	string destino;
    string fecha;
    string ordenAsiento;
    double pago; 

public:
    Reserva(const std::string& destino, const std::string& fecha , const std::string& ordenAsiento, const double& pago);
	
	string getDestino() const;
    string getFecha() const;
    string getOrdenAsiento() const;
    double getPago() const; 
    void mostrarDatos()const; 
};


#endif
