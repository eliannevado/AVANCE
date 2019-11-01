#include <iostream>
#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <string.h>
#include <cstdlib>
#include "palabra.h"
#include <fstream>
 
using namespace std;
class Archivo
{
    
private:    
 string nombre;
 
public:      
        void crearArchivo(){
              
               ofstream archivoelian;  
               //SOLO PARA LA DEMOSTRACION
               archivoelian.open("CarpetaDePrueba.txt");
               archivoelian << "Me gusta este curso y \n";
               archivoelian << "siempre llego temprano \n";
               archivoelian << "a clases\n";
               //PARA ABRIR UNA CARPETA DESDE MI PC,
               //archivo.open("d://elián Nevado//CarpetaDePrueba.txt")
               archivoelian.close();
              cout<<"Archivo creado"<<endl;
              cin.get();
              }
        // Metodo para Guardar  Frases en un archivo
        void guardaArchivo(){
              
              char cadena2[80];
              string cadena,cadena1;
              bool continua=true;
               ofstream archivoelian("CarpetaDePrueba.txt",ios::app);       
               cout << "Nota: Ingrese texto para continuar en la linea siguinte presione enter"<<endl;
               cout<< "para guardar escriba guardar y presione enter\n";
               cout<< "para salir escriba salir y presione enter\n";
               while (continua==true){
                      cout << "Ingrese texto: "<<endl;
                      cin.getline(cadena2,80); // getlinepermite leer la linea completa incluyendo espacios
                      cadena1=cadena2; 
                      if (cadena1=="salir"){continua=false; }
                      else if (cadena1=="guardar"){continua=false;  break;}
                      else {
                           cadena=cadena+cadena1+"\n";
                           cout<<cadena<<endl;
                      }
         
               }
               if (cadena1=="guardar"){
                       archivoelian << cadena;
               }
               archivoelian.close();
               cout<<"Archivo Actualizado"<<endl;
               cin.get();
        }
        // Metodo para Mostrar por pantalla datosde  un archivo
        void leerArchivo(){
             char cadena1[80]; // porque es el tamaño maximo de una linea enun archivo de texto.
             string cadena;
             ifstream Carpelian("CarpetaDePrueba.txt");
             while(!Carpelian.eof()) {
                  Carpelian.getline(cadena1, 80,'\n'); // lee la linea de 80 caracteres y lo guarda en la variable cadena \n paraindicar fin de linea
                  cout<< cadena1 << endl;
              }
              Carpelian.close();
              char n;
              cout<<"Presione enter"<<endl;
              cin>>n;
        }
        // Metodo para Inicializar el archivo
        void borrarArchivo(){
              
               ofstream archivoelian;  
               archivoelian.open("CarpetaDePrueba.txt");
               archivoelian.close();
              cout<<"Archivo creado"<<endl;
              system("PAUSE");
              }

       void MoverDerecha(){
            Palabra obj2;
            char cadena1[80]; 
            string cadena;
            ifstream Carpelian("CarpetaDePrueba.txt");
            while(!Carpelian.eof()) {
                 Carpelian.getline(cadena1, 80,'\n'); 
                 cadena+=obj2.MovimientoDerecha(cadena1)+"\n";
           }
           Carpelian.close();
           ofstream archivoelian;  
           archivoelian.open("CarpetaDePrueba.txt");
           archivoelian << cadena;
           archivoelian.close();
          
       }
       void MoverIzquierda(){
            Palabra obj2;
            char cadena1[80]; 
            string cadena;
            ifstream Carpelian("CarpetaDePrueba.txt");
            while(!Carpelian.eof()) {
                 Carpelian.getline(cadena1, 80,'\n'); 
                 cadena+=obj2.MovimientoIzquierda(cadena1)+"\n";
              
           }
           Carpelian.close();
           ofstream archivoelian;  
           archivoelian.open("CarpetaDePrueba.txt");
           archivoelian << cadena;
           archivoelian.close();
           
       }
       void MoverCentro(){
            Palabra obj2;
            char cadena1[80];
            string cadena;
            ifstream Carpelian("CarpetaDePrueba.txt");
            while(!Carpelian.eof()) {
                 Carpelian.getline(cadena1, 80,'\n'); 
                 cadena+=obj2.MovimientoCentro(cadena1)+"\n";
                
           }
           Carpelian.close();
           ofstream archivoelian;  // objeto de la clase ofstream
           archivoelian.open("CarpetaDePrueba.txt");
           archivoelian << cadena;
           archivoelian.close();
           
       }
 
      
      
};
#endif
