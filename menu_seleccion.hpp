#ifndef MENU_SELECCION_HPP
#define MENU_SELECCION_HPP

#include "seleccion.hpp"
#include "menu_jugador.hpp"

void menu_seleccion(Arreglo<Seleccion>& grupo) {
    string op;
    while (true)
    {
        cout << "1) Agregar Seleccion" << endl;
        cout << "2) Mostrar Seleccion" << endl;
        cout << "0) Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> op; cin.ignore();

        if (op == "1") {
            if (grupo.full()) {
                cout << "Grupo ya esta completo" << endl;
                continue;
            }
            Seleccion s;
            string nombre;

            cout << "Nombre de la seleccion: ";
            getline(cin, nombre);
            s.setNombre(nombre);

            grupo.push_back(s);
        }
        else if (op == "2") {
            if (grupo.empty()) {
                cout << "El grupo no tiene selecciones" << endl;
                continue;
            }
            size_t cont{0};
            for (size_t i = 0; i < grupo.size(); i++)
            {
                Seleccion& s = grupo[i];
                cout << cont + 1 << ") " << s.getNombre() << endl;
                cont++;
            }
            size_t op_selcc;
            cout << "0) Salir" << endl;
            cout << "Elige una opcion: ";
            cin >> op_selcc; cin.ignore();
            if (op_selcc == 0) continue;
            else if (op_selcc > grupo.size()) {
                cout << "Opcion no validad" << endl;
                continue;
            }
            Seleccion* s = &grupo[op_selcc - 1];
            cout << "Seleccion elegida: " << s->getNombre() << endl;
            menu_jugador(s);
        }
        else if (op == "0") {
            break;
        }

    }
    


}

#endif