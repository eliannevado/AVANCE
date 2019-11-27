#ifndef PALABRA_H 
#define PALABRA_H
#include <string>
#include <iostream>
using namespace std;
class Palabra {
public:
      bool buscarPalabra(string frase, string palabra);
      string sustituyePalabra(string frase,string palabra, string reemplazo );
      string Derecha(char linea[106]);
      string Izquierda(char linea[106]);
      string encriptar(char linea[106]);
      string desencriptar(char linea2[106]);
      int Cuenta(string s, char Separador);
      string Centro(char linea[106]);
      string Justificado(char linea[106]);

};

#endif