#include "Menu.h"
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;
// Metodo para limpiar pantalla
void limpiar() { cout << "\033[2J\033[0;0H"; }
// Metodo para esperar se presion una tecla para continuar
void esperar() {
    char w;
    do {
        cout << "Presione X y Enter para continuar..."; cin >> w;
    } while (toupper(w) != 'X');

}
// Metodo de impresion del menu principal
void Menu::imprimirMenu() {
    limpiar();
    cout << "========MENU PRINCIPAL========\n";
    cout << string(30, '=') << "\n";
    cout << "[1].- Agregar Frase\n";
    cout << "[2].- Crear Carpeta y Agregar Texto\n";
    cout << "[3].- Alinear a la Derecha\n";
    cout << "[4].- Alinear a la Izquierda\n";
    cout << "[5].- Centrar\n";   
    cout << "[6].- Justificar\n";
    cout << "[7].- Contar repitencia de una Palabra\n";
    cout << "[8].- Buscar una Palabra\n";
    cout << "[9].-Reemplazar una Palabra\n";
    cout << "[10].- Salir\n";
    cout << string(30, '=') << "\n\n";
 
}
// Metodo para activar el menu principal
void Menu::ejecutar() {
     
    do {
        imprimirMenu();
        cin >> opcion;
        seleccionarOpcion();
    } while (opcion != 10);
    cout << "Hasta Luego...\n";
}
// Metodo para seleccionar un opcion en el menu
void Menu::seleccionarOpcion() {
    limpiar();
     switch(opcion) {
        case 1: frase.agregarFrases(); break; // 1. Agregar Frase
        case 2: frase.leerArchivo(); break; // 2. Leer Archivo
        case 3: frase.alineaDerecha(); break; // 3. Derecha
        case 4: frase.alineaIzquierda(); break; // 4. Izquierda
        case 5: frase.alineaCentro(); break; // 5. Centro
        case 6: frase.justificaFrase(); break; // 6 Justifica 
        case 7: frase.cuentaPalabra(); break; // 9. Cuenta
        case 8: frase.buscaPalabra(); break; // 10. Buscar palabraCuenta
        case 9: frase.reemplazar(); break; // 10.Reemplazar una Palabra
    }
}