#include "Sistema.h"
#include <iostream>
using namespace std;

int main() {
    Sistema sistema;
    sistema.cargarPasajerosDesdeArchivo("pasajeros.txt");
    sistema.cargarReservasDesdeArchivo("reservas.txt");

    char opcionPrincipal;
    bool salir = false;

    do {
        system("cls");
        cout << "|==================================|" << endl;
        cout << "|        AGENCIA DE VIAJES         |" << endl;
        cout << "|          --NACIONALES--          |" << endl;
        cout << "|              __|__               |" << endl;
        cout << "|       --@--@--(_)--@--@--        |" << endl;
        cout << "|==================================|" << endl;
        cout << "|1. Menu Pasajeros                 |" << endl;
        cout << "|2. Menu Reservas                  |" << endl;
        cout << "|3. Guardar datos generales        |" << endl;
        cout << "|x. Salir                          |" << endl;
        cout << "|----------------------------------|" << endl;
        cin >> opcionPrincipal;

        switch (opcionPrincipal) {
            case '1': {
                char opcionPasajero;
                bool subMenuPasajero = true;

                do {
                    system("cls");
                    cout << "|==================================|" << endl;
                    cout << "|          MENU PASAJEROS          |" << endl;
                    cout << "|==================================|" << endl;
                    cout << "|1. Registrar pasajero             |" << endl;
                    cout << "|2. Mostrar pasajeros              |" << endl;
                    cout << "|3. Guardar pasajeros              |" << endl;
                    cout << "|x. Volver al menu principal       |" << endl;
                    cout << "|----------------------------------|" << endl;
                    cin >> opcionPasajero;

                    switch (opcionPasajero) {
                        case '1': {
                            string nombre, DNI, telefono, destino;
                            cout << "Ingrese nombre: ";
                            cin.ignore();
                            getline(cin, nombre);
                            cout << "Ingrese DNI: ";
                            getline(cin, DNI);
                            cout << "Ingrese telefono: ";
                            getline(cin, telefono);
                            cout << "Ingrese destino: ";
                            getline(cin, destino);
                            Pasajero pasajero(nombre, DNI, telefono, destino);
                            sistema.agregarPasajero(pasajero);
                            cout << "Pasajero registrado con exito.\n";
                            system("pause");
                            break;
                        }
                        case '2':
                            sistema.mostrarPasajeros();
                            system("pause");
                            break;
                        case '3':
                            sistema.guardarPasajerosEnArchivo("pasajeros.txt");
                            cout << "Datos guardados con exito.\n";
                            system("pause");
                            break;
                        case 'x':
                            subMenuPasajero = false;
                            break;
                        default:
                            cout << "Opcion no valida. Intente nuevamente.\n";
                            system("pause");
                    }
                } while (subMenuPasajero);
                break;
            }

            case '2': {
                char opcionReserva;
                bool subMenuReserva = true;

                do {
                    system("cls");
                    cout << "|==================================|" << endl;
                    cout << "|          MENU RESERVAS           |" << endl;
                    cout << "|==================================|" << endl;
                    cout << "|1. Registrar reserva              |" << endl;
                    cout << "|2. Mostrar reservas               |" << endl;
                    cout << "|3. Guardar reservas               |" << endl;
                    cout << "|x. Volver al menu principal       |" << endl;
                    cout << "|----------------------------------|" << endl;
                    cin >> opcionReserva;

                    switch (opcionReserva) {
                        case '1': {
                            string destino, fecha, ordenAsiento;
                            double pago; 
                            cout << "Destino: ";
                            cin.ignore();
                            getline(cin, destino);
                            cout << "Ingrese fecha: ";
                            getline(cin, fecha);
                            cout << "Ingrese orden de asiento: ";
                            getline(cin, ordenAsiento);
                            cout<< "Ingese el monto: S/. ";
                            cin >> pago; 
                            Reserva reserva(destino, fecha, ordenAsiento, pago);
                            sistema.agregarReserva(reserva);
                            cout << "Reserva registrada con exito.\n";
                            system("pause");
                            break;
                        }
                        case '2':
                            sistema.mostrarReserva();
                            system("pause");
                            break;
                        case '3':
                            sistema.guardarReservasEnArchivo("reservas.txt");
                            cout << "Reservas guardadas con exito.\n";
                            system("pause");
                            break;
                        case 'x':
                            subMenuReserva = false;
                            break;
                        default:
                            cout << "Opcion no valida. Intente nuevamente.\n";
                            system("pause");
                    }
                } while (subMenuReserva);
                break;
            }

            case '3':
                sistema.guardarPasajerosEnArchivo("pasajeros.txt");
                sistema.guardarReservasEnArchivo("reservas.txt");
                cout << "Datos generales guardados con exito.\n";
                system("pause");
                break;

            case 'x':
                salir = true;
                cout << "Saliendo del sistema...\n";
                system("pause");
                break;

            default:
                cout << "Opcion no valida. Intente nuevamente.\n";
                system("pause");
        }
    } while (!salir);

    return 0;
}
