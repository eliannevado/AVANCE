#ifndef MENU_H
#define MENU_H

#include "frase.h"
#include <string>
using namespace std;
//Clase menu definicion
class Menu {
    int opcion;
    Frase frase;
    void imprimirMenu();
    void seleccionarOpcion();
public:
Menu(): opcion{0} {}
void ejecutar();
};
#endif//AGREGACION_MENU_H