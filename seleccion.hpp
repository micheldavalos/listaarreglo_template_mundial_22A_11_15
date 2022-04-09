#ifndef SELECCION_HPP
#define SELECCION_HPP

#include "jugador.hpp"
#include "listaarreglo.hpp"
#include <sstream>
#include <iomanip>

class Seleccion {
private:
    ListaArreglo<Jugador> jugadores;
    string nombre;
public:
    Seleccion() {}
    Seleccion(const string& nombre):nombre(nombre) {}

    // Getter and Setter
    void setNombre(const string& value) { nombre = value; }
    string getNombre() { return nombre; }

    void agregarInicio(const Jugador& j) { jugadores.push_front(j); }
    void agregarFinal(const Jugador& j) { jugadores.push_back(j); }

    string to_string() {
        stringstream ss;
        ss << left;
        ss << setw(10) << "Nombre"
           << setw(10) << "Numero"
           << setw(10) << "Goles"
           << endl;
        for (size_t i = 0; i < jugadores.size(); i++)
        {
            Jugador& j = jugadores[i];
            ss << setw(10) << j.getNombre()
                << setw(10) << j.getNumeroPlayer()
                << setw(10) << j.getGoles()
                << endl;
        }
        return ss.str();        
    }

    // Ordenar
    void ordenarNombre() { jugadores.sort([](Jugador& j1, Jugador& j2)
                         { return j1.getNombre() > j2.getNombre(); }); }
    void ordenarGoles() { jugadores.sort([](Jugador& j1, Jugador& j2)
                         { return j1.getGoles() > j2.getGoles(); }); }
};



#endif