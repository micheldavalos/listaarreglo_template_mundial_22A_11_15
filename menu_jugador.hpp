#ifndef MENU_JUGADOR_HPP
#define MENU_JUGADOR_HPP

#include "seleccion.hpp"

Jugador leerJugador() {
    Jugador j;
    string temp;

    cout << "Nombre: "; getline(cin, temp); j.setNombre(temp);
    cout << "Numero: "; getline(cin, temp); j.setNumeroPlayera(stoll(temp));
    cout << "Goles: "; getline(cin, temp); j.setGoles(stoll(temp));

    return j;
}

void menu_jugador(Seleccion* s) {
    string op;
    while (true)
    {
        cout << "1) Agregar Jugador" << endl;
        cout << "2) Mostrar Jugadores" << endl;
        cout << "3) Ordenar por Nombre" << endl;
        cout << "4) Ordenar por Goles" << endl;
        cout << "0) Salir" << endl;
        cout << "Opcion: ";
        cin >> op; cin.ignore();

        if (op == "1") {
            s->agregarFinal(leerJugador());
        }
        else if (op == "2") {
            cout << s->to_string();
        }
        else if (op == "3") {
            s->ordenarNombre();
        }
        else if (op == "4") {
            s->ordenarGoles();
        }
        else if (op == "0") {
            break;
        }
    }
    
}

#endif