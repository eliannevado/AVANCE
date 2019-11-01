#include "archivo.h"
#include <cstdlib>
#include <iostream>
#include <string>
 
using namespace std;
void limpiar(){
    system("clear");
    }
int main()
{
   Archivo obj;
   Palabra obj2;
   bool opcion=false;
   int tecla;
   do {
    limpiar();
       cin.clear();
       cout << "Editor de Texto" << endl;
       cout << "-----------" << endl << endl;
       cout << "\t1  .- Crear Archivo" << endl;
       cout << "\t2  .- Leer Archivo" << endl;
       cout << "\t3  .- Guardar Archivo" << endl;
       cout << "\t4  .- Borrar archivo" << endl ;
       cout << "\t5  .- Aliniear a la Derecha" << endl ;
       cout << "\t6  .- Aliniear a la Izquierda" << endl ;
       cout << "\t7  .- Centrar" << endl ;
       cout << "\t8 .- Salir" << endl<< endl ;
       cout << "Elije una opcion: ";
       cin >> tecla;
    switch(tecla){
      case 1:
        limpiar();
        cout << "Creaciòn de Archivo.\n";
        obj.crearArchivo();
        break;
      case 2:
        limpiar();
        obj.leerArchivo();
   	 cin.get();
        break;
      case 3:
        limpiar();
        obj.guardaArchivo();
   	 cin.get();
        break;
      case 4:
        limpiar();
        obj.borrarArchivo();
   	 cin.get();
        break;
      case 5:
        limpiar();
               obj.MoverDerecha();
   	   cin.get();
        break;        
      case 6:
        limpiar();
               obj.MoverIzquierda();
   	   cin.get();
        break;        
      case 7:
        limpiar();
       obj.MoverCentro();
   	 cin.get();
        break;        
      case 8:
        opcion=true;
        break;
      default:
       limpiar();
        cout << "Opcion no valida.\a\n";
        break;
 
    }
   }while(opcion!=true);
}


