#include <iostream>
#include <string>
#include <cstdlib>
#include "frase.h"
#include <fstream>

using namespace std;
// Metodo para limpiar pantalla
void limpiar2() { cout << "\033[2J\033[0;0H"; }
// Metodo para esperar se presion una tecla para continuar
void esperacomando() {
    char w;
    do {
        cout << "Presione S y Enter para Salir..."; cin >> w;
    } while (toupper(w) != 'S');}
Frase::Frase(){}
void Frase::CrearArchivo(){
   cout<<"Inicializando Archivo de texto"<<endl;
   ofstream ArchivoNevado;
   ArchivoNevado.open("datos.txt");
   ArchivoNevado.close();
   esperacomando();}

void Frase::agregarFrases(){
       char fraseEntrada2[300];
       string fraseEntrada,Lineaarchivo;
       bool sigue=true;
       ofstream ArchivoNevado("datos.txt",ios::app);        
       cout<<"[1] Typee 1 para salir"<<endl;
       cout<<"[2] Typee 2 para guardar"<<endl;       
       cout<<"Typee la frase y presione enter para generar una lineanueva\n";
        while (sigue==true){
               cout << ": "<<endl;
               cin.getline(fraseEntrada2,300);
               Lineaarchivo=fraseEntrada2;  
               if ((Lineaarchivo=="1") || (Lineaarchivo=="2")) {sigue=false; }
               else fraseEntrada=fraseEntrada+Lineaarchivo+"\n"; 
        }
        if (Lineaarchivo=="2") ArchivoNevado << fraseEntrada;
        ArchivoNevado.close();
        cout<<"-----Se han agregado las frases al archivo-----"<<endl;
        esperacomando();}
        
void Frase::leerArchivo(){
      char Lineaarchivo[300]; // porque es el tama?o maximo de una linea enun archivo de texto. 
      string fraseEntrada;
      ifstream archivoatrabajar("datos.txt");
      while(!archivoatrabajar.eof()) {
           archivoatrabajar.getline(Lineaarchivo, 300,'\n'); // lee la linea de 80 caracteres y lo guarda en la variable fraseEntrada \n paraindicar fin delinea
           cout<< Lineaarchivo << endl;
       }
       archivoatrabajar.close();
       esperacomando();}
       
void Frase::cuentaPalabra(){
     char Lineaarchivo[106];
     string fraseEntrada;
     string palabra, num2;
     int numero=0;
     cout<<"Ingrese la palabra a buscar: ";
     cin>>palabra;
     ifstream archivoatrabajar("datos.txt");
       while(!archivoatrabajar.eof()) {
           archivoatrabajar.getline(Lineaarchivo, 106,'\n');
           fraseEntrada=Lineaarchivo;
           if (buscarPalabra(fraseEntrada,palabra)==true) numero=numero+1;
           fraseEntrada=Lineaarchivo;
       }
       archivoatrabajar.close();
       num2=numero;
       cout<<"LA palabra '"+palabra+"' aparece: ";
       cout<<numero;
       cout<<" veces en el archivo"<<endl;
       esperacomando();}
       
void Frase::buscaPalabra(){
      char Lineatexto[106];
      string fraseEntrada;
      string palabra;
      bool encontrado=false;
      int numero=0;
       cout<<"Ingrese la palabra a buscar: ";
       cin>>palabra;
       ifstream archivoatrabajar("datos.txt");
       while(!archivoatrabajar.eof()) {
           archivoatrabajar.getline(Lineatexto, 106,'\n');
           fraseEntrada=Lineatexto;
           if (buscarPalabra(fraseEntrada,palabra)==true) {
              numero=numero+1;
              cout<<"Encontrada en linea:";
              cout<<numero;
              cout<<" "<<fraseEntrada<<endl;
              encontrado=true;
           }
       }
       if (encontrado==false) cout<<"No se encontraron coincidencias "<<endl;
       archivoatrabajar.close();
       esperacomando();}
       
void Frase::reemplazar(){
  char Lineatexto[106];
  string fraseEntrada, fraseF;
  string palabra,palabra2;
  bool encontrado=false;
  int numero=0;
  cout<<"Ingrese palabra a buscar: ";             
  cin>>palabra;
  cout<<"Ingrese palabra de reemplazo: ";
  cin>>palabra2;
  ifstream archivoatrabajar("datos.txt");
  while(!archivoatrabajar.eof()) {             
    archivoatrabajar.getline(Lineatexto, 106,'\n');
    fraseEntrada=Lineatexto;                    
    if (buscarPalabra(fraseEntrada,palabra)==true) {
      fraseF=fraseF+sustituyePalabra(fraseEntrada,palabra,palabra2)+"\n"; 
                      encontrado=true;
                  }
    else{ fraseF=fraseF+fraseEntrada+"\n"; }
  }
  archivoatrabajar.close();
  if (encontrado==false) cout<<"No se encontraron coincidencias "<<endl;
  else {
      ofstream ArchivoNevado;
      ArchivoNevado.open("datos.txt");
      ArchivoNevado << fraseF;
      ArchivoNevado.close();
      cout<<"Procesado...."<<endl;
  }
  esperacomando();}

void Frase::alineaDerecha(){
   char Entrada[106];
   string fraseEntrada;
   ifstream archivoatrabajar("datos.txt");
   while(!archivoatrabajar.eof()) {
      archivoatrabajar.getline(Entrada, 106,'\n');
      fraseEntrada+=Derecha(Entrada)+"\n";
    }
    archivoatrabajar.close();
    ofstream ArchivoNevado;
    ArchivoNevado.open("datos.txt");
    ArchivoNevado<< fraseEntrada;
    ArchivoNevado.close();
    cout<<"Jutificado el texto del archivo"<<endl;
    esperacomando();}

void Frase::alineaIzquierda(){
   char Lineaarchivo[106]; 
   string fraseEntrada;
   ifstream archivoatrabajar("datos.txt");
   while(!archivoatrabajar.eof()) {
       archivoatrabajar.getline(Lineaarchivo, 106,'\n');
       fraseEntrada+=Izquierda(Lineaarchivo)+"\n";
    }
    archivoatrabajar.close();
    ofstream ArchivoNevado;
    ArchivoNevado.open("datos.txt");
    ArchivoNevado<< fraseEntrada;
    ArchivoNevado.close();
    cout<<"Alineacion a la Izquierda Realizada"<<endl;
    esperacomando();}
    
void Frase::alineaCentro(){
  char Lineaarchivo[106];
  string fraseEntrada;
  ifstream archivoatrabajar("datos.txt");
  while(!archivoatrabajar.eof()) {
      archivoatrabajar.getline(Lineaarchivo, 106,'\n');
      fraseEntrada+=Centro(Lineaarchivo)+"\n";
   }
   archivoatrabajar.close();
   ofstream ArchivoNevado;
   ArchivoNevado.open("datos.txt");
   ArchivoNevado<< fraseEntrada;
   ArchivoNevado.close();
   cout<<"Archivo Justificado al Centro..."<<endl;
   esperacomando();}

void Frase::justificaFrase(){
  char Lineaarchivo[106];
  string fraseEntrada,control;
  ifstream archivoatrabajar("datos.txt");
  while(!archivoatrabajar.eof()) {
      archivoatrabajar.getline(Lineaarchivo, 106,'\n');
      control=Lineaarchivo;
       if(control.empty()==true) {}
       else{
         fraseEntrada+=Justificado(Lineaarchivo)+"\n";
       }
  }
  archivoatrabajar.close();
  ofstream ArchivoNevado;
  ArchivoNevado.open("datos.txt");
  ArchivoNevado<< fraseEntrada;
  ArchivoNevado.close();
  cout<<"Archivo Justificado"<<endl;
  esperacomando();} 