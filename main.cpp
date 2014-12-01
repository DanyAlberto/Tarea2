// queue::push/pop
#include "Evaluador.h"
#include <iostream>
#include <list>
#include <fstream>
using namespace std;


void escribir(string nombre_archivo, list<Cumpleanios*>cumpleanios)
{
   ofstream Cumpleanos;
   Cumpleanos.open(nombre_archivo.c_str(), ios::out);/*Se abre el archivo para poder escribir*/

   if(Cumpleanos.is_open())/*Valida si el archivo esta abierto*/
    {
        for(list<Cumpleanios*>::iterator inicio = cumpleanios.begin(); inicio!=cumpleanios.end(); inicio++)/*Haciendo uso del iterador se recorre la lista*/
        {
            Cumpleanos<<(*inicio)->cumpleaniero;
            Cumpleanos<< " ";
            Cumpleanos<<(*inicio)->dia;
            Cumpleanos<< " ";
            Cumpleanos<<(*inicio)->mes;
            Cumpleanos<< endl;
            /*Agregando registro*/
        }
    Cumpleanos.close();/* Cerrando el archivo*/
    }else
    {
        cout << "Archivo no se abrio correctamente" << endl;/*Indica que el archivo no se abrio*/
    }
}

list<Cumpleanios*> leer(string nombre_archivo)
{
    list<Cumpleanios*>cumpleanios;
    cumpleanios.clear();/*Limpieza de la lista*/

    ifstream Cumpleanos(nombre_archivo.c_str());/*Se abre el archivo en modo lectura*/

    string nombre;/*Variable que captura el nombre*/
    int dia;/*Variable que captura el dia*/
    int mes;/*Variable que captura el mes*/

    if(Cumpleanos)/*Valida si el archivo esta abierto*/
    {
        while(Cumpleanos>>nombre)/*Valida que aun no se haya llegado al final del archivo*/
        {
            Cumpleanos>>dia;/*Captura de dato para dia*/
            Cumpleanos>> mes;/*Captura de dato para mes*/
            cumpleanios.push_back(new Cumpleanios(nombre,dia,mes));/*Se agrega un nuevo registro a la lista*/
        }
    Cumpleanos.close();/*Cierre del archivo*/
    }

    return cumpleanios;/*Retornamos la lista*/
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
