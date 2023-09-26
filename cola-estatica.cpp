#include <iostream>
#include "Cola.h"

int main() {
    int opcion;
    Cola cola;
    Constancia constancia;

    do {
        std::cout << "1. Dar de alta la solicitud de un alumno" << std::endl;
        std::cout << "2. Elaborar una constancia" << std::endl;
        std::cout << "3. Salir" << std::endl;
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                if (cola.llena()) {
                    std::cout << "La cola esta llena" << std::endl;
                } else {
                    std::cin >> constancia;
                    cola.enqueue(constancia);
                }
                break;
            case 2:
                if (cola.vacia()) {
                    std::cout << "No hay constancias" << std::endl;
                } else {
                    std::cout << "Constancia elaborada: " << std::endl;
                    std::cout << cola.dequeue();
                }
                break;
            case 3:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opcion incorrecta" << std::endl;
        }
    } while (opcion != 3);

    return 0;
}
