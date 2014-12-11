#include "Lista.h"
#include "ArbolTrinario.h"
#include "Evaluador.h"
#include <fstream>
#include <list>
#include <vector>
#include <math.h>
#include <iostream>
#include<fstream>
#include<string.h>
#include<algorithm>

using namespace std;

//1 a realizar estan ubicados en el archivo Lista.h

float obtenerPromedio(std::list<float> mi_lista)
{
    int cont = 0;
    float promedio = 0.0;

    while(!mi_lista.empty())
    {
        promedio += mi_lista.front();
        cont++;
        mi_lista.pop_front();
    }

    return promedio/cont;
}

int obtenerMediana(std::vector<int> mi_vector)
{
    float cant = (mi_vector.size()/2)+.5;
    sort(mi_vector.begin(), mi_vector.end());
    return mi_vector[cant];
}

bool existeEnArchivo(string nombre_archivo, string cadena)
{
    ifstream in(nombre_archivo.c_str());
    string what;
    while(in.good())
    {
        in>>what;
        if(strcmp(what.c_str(),cadena.c_str())==0)
            return true;
    }
    return false;
}

char obtenerUltimaLetra(string nombre_archivo)
{
    ifstream in(nombre_archivo.c_str());
    char what;
    while(in.good())
        in>>what;
    return what;
}

int contarEnArbol(NodoTrinario* raiz, int num)
{
    int cont = 0;

    if(raiz==NULL)
        {
            return NULL;
        }
    if(raiz->num==num)
        cont++;
    int izq = contarEnArbol(raiz->izq, num);
    int medio = contarEnArbol(raiz->medio, num);
    int der = contarEnArbol(raiz->der, num);
    cont += izq;
    cont += medio;
    cont += der;

        return cont;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}

