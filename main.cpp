#include "Sistema.h"
#include <iostream>
#include <windows.h> // Para gotoxy y manejo de consola
#include <iomanip>   // Para formato
using namespace std;

// Función para mover el cursor en la consola
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Función para dibujar un cuadro en la consola
void dibujarCuadro(int x1, int y1, int x2, int y2) {
    gotoxy(x1, y1);
    cout << char(201); // Esquina superior izquierda
    for (int i = x1 + 1; i < x2; i++) cout << char(205); // Línea horizontal superior
    cout << char(187); // Esquina superior derecha

    for (int i = y1 + 1; i < y2; i++) {
        gotoxy(x1, i);
        cout << char(186); // Línea vertical izquierda
        gotoxy(x2, i);
        cout << char(186); // Línea vertical derecha
    }

    gotoxy(x1, y2);
    cout << char(200); // Esquina inferior izquierda
    for (int i = x1 + 1; i < x2; i++) cout << char(205); // Línea horizontal inferior
    cout << char(188); // Esquina inferior derecha
}

// Función para mostrar el menú principal
void mostrarMenuPrincipal() {
    system("cls");
    dibujarCuadro(2, 1, 77, 23); // Cuadro principal
    gotoxy(33, 2);
    cout << "AGENCIA DE VIAJES";

    // Encabezado
    gotoxy(5, 4);
    cout << "PASAJEROS";
    gotoxy(35, 4);
    cout << "RESERVAS";
    gotoxy(65, 4);
    cout << "GUARDAR";

    // Separador horizontal
    gotoxy(2, 5);
    for (int i = 3; i < 77; i++) cout << char(205);

    // Opciones del menú principal
    gotoxy(5, 7);
    cout << "MENU PRINCIPAL";
    gotoxy(5, 9);
    cout << "(1) Menu Pasajeros";
    gotoxy(5, 11);
    cout << "(2) Menu Reservas";
    gotoxy(5, 13);
    cout << "(3) Guardar datos generales";
    gotoxy(5, 15);
    cout << "(x) Salir";

    gotoxy(5, 17);
    cout << "Ingrese opcion: ";
}

// Función para mostrar el submenú de pasajeros
void mostrarMenuPasajeros() {
    system("cls");
    dibujarCuadro(2, 1, 77, 23);
    gotoxy(33, 2);
    cout << "MENU PASAJEROS";

    gotoxy(5, 7);
    cout << "(1) Registrar Pasajero";
    gotoxy(5, 9);
    cout << "(2) Mostrar Pasajeros";
    gotoxy(5, 11);
    cout << "(3) Guardar Pasajeros";
    gotoxy(5, 13);
    cout << "(x) Volver al menu principal";

    gotoxy(5, 17);
    cout << "Ingrese opcion: ";
}

// Función para mostrar el submenú de reservas
void mostrarMenuReservas() {
    system("cls");
    dibujarCuadro(2, 1, 77, 23);
    gotoxy(33, 2);
    cout << "MENU RESERVAS";

    gotoxy(5, 7);
    cout << "(1) Registrar Reserva";
    gotoxy(5, 9);
    cout << "(2) Mostrar Reservas";
    gotoxy(5, 11);
    cout << "(3) Guardar Reservas";
    gotoxy(5, 13);
    cout << "(x) Volver al menu principal";

    gotoxy(5, 17);
    cout << "Ingrese opcion: ";
}

int main() {
    Sistema sistema;
    sistema.cargarPasajerosDesdeArchivo("pasajeros.txt");
    sistema.cargarReservasDesdeArchivo("reservas.txt");

    char opcionPrincipal;
    bool salir = false;

    do {
        mostrarMenuPrincipal();
        cin >> opcionPrincipal;

        switch (opcionPrincipal) {
            case '1': {
                char opcionPasajero;
                bool subMenuPasajero = true;

                do {
                    mostrarMenuPasajeros();
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
                    mostrarMenuReservas();
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
                            cout << "Ingrese el monto: ";
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
