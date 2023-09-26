#ifndef COLA_H
#define COLA_H
#include <iostream>

const int TAM = 100;

class Constancia {
    private:
        std::string nombre, carrera;
        int materias;
        float promedio;
    public:
        Constancia();
        Constancia(std::string n, std::string c, int m, float p);
        friend operator == (Constancia& c1, Constancia& c2);
        friend operator != (Constancia& c1, Constancia& c2);
        friend std::istream& operator >> (std::istream& i, Constancia& c);
        friend std::ostream& operator << (std::ostream& o, Constancia& c);
};

class Cola {
    private:
        Constancia constancias[100];
        int ult;
        bool elimina(int posicion);
        int inserta(Constancia& constancia, int posicion);
    public:
        Cola(): ult(-1) {}
        bool vacia() const;
        bool llena() const;
        int ultimo() const;
        friend std::ostream& operator << (std::ostream & o, Cola& c);
        void enqueue(Constancia& constamcia);
        Constancia& dequeue();
};

#endif // COLA_H
