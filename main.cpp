#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include"Set.h"
using namespace std;



// Función estática para procesar comandos
void procesarComando(Set& conjunto, const string& comando) {

    if (comando.size() > 2 && comando[0] == 'E') {
        int capacidad = 0;
        capacidad = stoi(comando.substr(2));
        conjunto.setCapacity(capacidad);
        cout << "Capacidad establecida a " << conjunto.getCapacity() << endl;
    } else if (comando[0] == 'i') {
        string s = comando.substr(2);
        if (conjunto.insertar(s))
            cout << "SI insertado" << endl;
        else
            cout << "NO insertado" << endl;
    } else if (comando[0] == 'r') {
        string s = comando.substr(2);
        if (conjunto.eliminar(s))
            cout << "SI removido" << endl;
        else
            cout << "NO removido" << endl;
    } else if (comando[0] == 'c') {
        cout << conjunto.cardinalidad() << endl;
    } else if (comando[0] == 'v') {
        if (conjunto.estaVacio())
            cout << "VACIO" << endl;
        else
            cout << "NO VACIO" << endl;
    } else if (comando[0] == 't') {
        string s = comando.substr(2);
        if (conjunto.contiene(s))
            cout << "SI ESTA" << endl;
        else
            cout << "NO ESTA" << endl;
    }
}


int main() {
    Set miSet;
    string comando;
    bool exit = false;
    while(!exit) {
        getline(cin, comando);
        procesarComando(miSet,comando);
    }
    //miSet.insertar("hola");
    //miSet.insertar("mundo");
    //miSet.eliminar("hola");

    //Set otroSet;
    //otroSet.insertar("mundo");
    //otroSet.insertar("programa");

    //Set unionSet = miSet.unionSet(otroSet);
    //Set interseccionSet = miSet.intersect(otroSet);

    //vector<string> elementosUnion = unionSet.elementos();
    //vector<string> elementosInterseccion = interseccionSet.elementos();

    //cout << "Elementos de la unión: ";
    //for (const string& el : elementosUnion) {
        //cout << el << " ";
    //}
    //cout << endl;

    //cout << "Elementos de la intersección: ";
    //for (const string& el : elementosInterseccion) {
        //cout << el << " ";
    //}
    //cout << endl;

    return 0;
}
