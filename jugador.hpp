#ifndef JUGADOR_HPP
#define JUGADOR_HPP

#include <string>
using namespace std;

class Jugador {
private:
    string nombre;
    size_t numeroPlayera;
    size_t goles;
public:
    Jugador() {}
    Jugador(const string& nombre, 
            size_t numeroPlayera, 
            size_t goles) {
                Jugador::nombre = nombre;
                Jugador::numeroPlayera = numeroPlayera;
                Jugador::goles = goles;
            }
    // Setter and Getter
    void setNombre(const string& value) { nombre = value; }
    string getNombre() { return nombre; }

    void setNumeroPlayera(size_t value) { numeroPlayera = value; }
    size_t getNumeroPlayer() { return numeroPlayera; }

    void setGoles(size_t value) { goles = value; }
    size_t getGoles() { return goles; }
};
#endif