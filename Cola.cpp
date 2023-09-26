#include "Cola.h"

Constancia::Constancia() {
    nombre = " ";
    carrera = " ";
    materias = 0;
    promedio = 0;
}

Constancia::Constancia(std::string n, std::string c, int m, float p) {
    nombre = n;
    carrera = c;
    materias = m;
    promedio = p;
}

operator == (Constancia& c1, Constancia& c2) {
    return (
        c1.nombre == c2.nombre && c1.carrera == c2.carrera &&
        c1.materias == c2.materias && c1.promedio == c2.promedio
    );
}

operator != (Constancia& c1, Constancia& c2) {
    return !(c1 == c2);
}

std::istream& operator >> (std::istream& i, Constancia& c) {
    std::cout << "Nombre del alumno: ";
    i >> c.nombre;

    std::cout << "Carrera del alumno: ";
    i >> c.carrera;

    std::cout << "Total de materias del alumno: ";
    i >> c.materias;

    std::cout << "Promedio del alumno: ";
    i >> c.promedio;

    return i;
}

std::ostream& operator << (std::ostream& o, Constancia& c) {
    o << "Nombre del alumno: " << c.nombre << std::endl;
    o << "Carrera del alumno: " << c.carrera << std::endl;
    o << "Total de materias del alumno: " << c.materias << std::endl;
    o << "Promedio del alumno: " << c.promedio << std::endl;

    return o;
}

bool Cola::vacia() const {
    if (ult == -1) return true;
    return false;
}

bool Cola::llena() const {
    if (ult == TAM - 1) return true;
    return false;
}

int Cola::ultimo() const {
    return ult;
}

std::ostream& operator << (std::ostream& o, Cola& c) {
    int i = 0;
    std::cout << "\n";

    while (i <= c.ultimo()) {
        o << c.constancias[i];
        i++;
    }

    return o;
}

void Cola::enqueue(Constancia& constancia) {
    inserta(constancia, 0);
}

Constancia& Cola::dequeue() {
    ult--;
    return constancias[ult + 1];
}

bool Cola::elimina(int posicion) {
    if (vacia() || posicion < 0 || posicion > ult) {
        return false;
    }

    int i = posicion;
    while(i < ult) {
        constancias[i] = constancias[i + 1];
        i++;
    }

    return true;
}

int Cola::inserta(Constancia& constancia, int posicion) {
    if (llena() || posicion < 0 || posicion > ult + 1) return 0;

    int i = ult + 1;
    while(i > posicion) {
        constancias[i] = constancias[i - 1];
        i--;
    }

    constancias[posicion] = constancia;
    ult++;

    return 1;
}
