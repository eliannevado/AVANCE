#include "palabra.h"
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <ctype.h>
using namespace std;
bool Palabra::buscarPalabra(string frase, string palabra){
    if(frase.find(palabra)==string::npos) return false;
    else return true; }

string Palabra::sustituyePalabra(string frase,string palabra, string reemplazo ){
  string::size_type pos = frase.find(palabra, 0);
  if (pos < string::npos)
    frase.replace(pos, palabra.length(), reemplazo);
    return frase;     }

string Palabra::Derecha(char linea[106]){
   int v; char salida[100];
   for (int i=0; i<100;i++){ salida[i]=' '; }    
   int tam=string(linea).length();
   v=tam;
   for (int y=99; y>-1;y--){
       if (v<0) break;
       else salida[y]=linea[v];
       v--;
   }
   string sal=salida;
   return sal;}
   
string Palabra::Izquierda(char linea[106]){
   int v=0, ind=0;
   char salida[100];
   for (int y=0; y<100;y++){
        if (linea[y]!=' ') break;
        else v++; }
   for (int i=v; i<100;i++){
        salida[ind]=linea[i];
        ind++;}
   string sal=salida;
   return sal;}

int Palabra::Cuenta(string s, char Separador) {
    int TotalChars=0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == Separador) TotalChars++;
     return TotalChars;}

string Palabra::Centro(char linea[106]){
   int v=0, ind=0; int tam=0;
   char temp[106]; char salida[106];
   for (int i=0; i<106;i++){ salida[i]=' '; }    
       for (int y=0; y<106;y++){
           if (linea[y]!=' ') break;
           else v++; }
        for (int i=v; i<106;i++){
           temp[ind]=linea[i];
           ind++;}
        tam=(string(temp).length())/2;
        
        ind=0;
        for (int i=tam; i<53;i++){
            salida[i]=temp[ind];
            ind++;}
        for (int i=50; i<106;i++){
            salida[i]=temp[ind];
            ind++;}
        string sal=salida;
        return sal;}
        
string Palabra::Justificado(char linea[106]){
    string control2=linea;
    char temp1[106];
    strcpy(temp1, control2.c_str()); 
    char salida[106];
    int indic=0;
    for (int i=0; i<106;i++){ 
        if ((temp1[i]==' ') && (temp1[i-1]==' '))
        {} 
        else {salida[indic]=temp1[i]; 
        indic++;}}
    int cantidadEsp=Cuenta(salida,' ');
    control2=salida;
    int tam0=control2.length();
    int esplibres=0;
    char temp[106];
    bool sigue=true;
    int numS=0; 
    int numT=0; 
    int espxPal=0;
    if (tam0==106){
        return control2;}
    else{
        esplibres=tam0-cantidadEsp;
        espxPal=esplibres/cantidadEsp;

    while (sigue){
      if (salida[numS]==' '){    
        for (int x=0; x<espxPal;x++){
          temp[numT]=' ';
          numT++; }}
      temp[numT]=salida[numS];
      numT++;
      if (numS<106) numS++;
      else sigue=false;}}
    string sal=temp;
    return sal;}